// Philipp Klaus Krause, philipp@informatik.uni-frankfurt.de, pkk@spth.de, 2010 - 2011
//
// (c) 2010-2011 Goethe-Universität Frankfurt
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option) any
// later version.
//   
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//   
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
// An optimal, polynomial-time register allocator.
// The current version can handle general-purpose registers only.
//
// To use this from a port do teh following:
//
// 1) Supply a cost function
// template <class G_t, class I_t>
// float instruction_cost(const assignment &a, unsigned short int i, const G_t &G, const I_t &I);
// Which can range from
// simple, e.g. cost 1 for each byte accessed in a register, cost 4 for each byte accessed in memory
// to
// quite involved, e.g. the number of bytes of code the code generator would generate.
//
// 2) Call
// create_cfg(), thorup_tree_decomposition(), nicify(), alive_tree_dec(), tree_dec_ralloc_nodes().
//
// The Z80 port can serve as an example, see z80_ralloc2_cc() in z80/ralloc2.cc.

#ifndef SDCCRALLOC_HH
#define SDCCRALLOC_HH 1

#include <iostream>
#include <limits>
#include <utility>
#include <sstream>
#include <fstream>

#include <boost/graph/graphviz.hpp>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/connected_components.hpp>

#include "SDCCtree_dec.hpp"

extern "C"
{
#include "sdccconf.h"
#include "SDCCsymt.h"
#include "SDCCicode.h"
#include "SDCCBBlock.h"

#include "z80.h"
#include "ralloc.h"
}

typedef short int var_t;
typedef signed char reg_t;

// Todo: Move this port-dependency somewehere else?
#define NUM_REGS (TARGET_IS_Z80 ? 4 : (TARGET_IS_GBZ80 ? 2 : 0))

// Assignment at an instruction
struct i_assignment
{
	short int registers[4][2];	// 4 needs to be at least MAX_REGS
	
	i_assignment(void)
	{
		for(reg_t r = 0; r < NUM_REGS; r++)
			for(unsigned int i = 0; i < 2; i++)
				registers[r][i] = -1;
	}
	
	bool operator<(const i_assignment &i_a) const
	{
		for(reg_t r = 0; r < NUM_REGS; r++)
			for(unsigned int i = 0; i < 2; i++)
			{
				if(registers[r][i] < i_a.registers[r][i])
					return(true);
				else if(registers[r][i] > i_a.registers[r][i])
					return(false);
			}
		return(false);
	}
	
	void add_var(var_t v, reg_t r)
	{
		if(registers[r][1] < v)
		{
			registers[r][0] = registers[r][1];
			registers[r][1] = v;
		}
		else
			registers[r][0] = v;
	}
	
#if 0
	void remove_var(var_t v)
	{
		for(reg_t r = 0; r < NUM_REGS; r++)
		{
			if(registers[r][1] == v)
			{
				registers[r][1] = registers[r][0];
				registers[r][0] = -1;
			}
			else if(registers[r][0] == v)
				registers[r][0] = -1;
		}
	}
#endif
};

struct assignment
{
	float s;

	std::set<var_t> local;	// Entries: var
	std::vector<reg_t> global;	// Entries: gloabal[var] = reg (-1 if no reg assigned)
	
	std::map<int, i_assignment> i_assignments;

	bool operator<(const assignment& a) const
	{
		std::set<var_t>::const_iterator i, ai, i_end, ai_end;

		i_end = local.end();
		ai_end = a.local.end();

		for(i = local.begin(), ai = a.local.begin();; ++i, ++ai)
		{
			if(i == i_end)
				return(true);
			if(ai == ai_end)
				return(false);

			if(*i < *ai)
				return(true);
			if(*i > *ai)
				return(false);

			if(global[*i] < a.global[*ai])
				return(true);
			if(global[*i] > a.global[*ai])
				return(false);
		}
	}
};

struct tree_dec_node
{
	std::set<unsigned int> bag;
	std::set<var_t> alive;
	std::list<assignment> assignments;
};

struct cfg_node
{
	iCode *ic;
	std::multimap<int, var_t> operands;
	std::set<var_t> alive;
};

struct con_node
{
	int v;
	int byte;
	char *name;
};

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS, tree_dec_node> tree_dec_t;
typedef boost::adjacency_list<boost::setS, boost::vecS, boost::undirectedS, con_node> con_t;
typedef boost::adjacency_matrix<boost::undirectedS, con_node> con2_t;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::bidirectionalS, cfg_node> cfg_t;
typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> cfg_sym_t;

inline void add_operand_to_cfg_node(cfg_node &n, operand *o, std::map<std::pair<int, reg_t>, var_t> &sym_to_index)
{
	reg_t k;
	if(o && IS_SYMOP(o) && sym_to_index.find(std::pair<int, reg_t>(OP_SYMBOL(o)->key, 0)) != sym_to_index.end())
	{
		if(n.operands.find(OP_SYMBOL(o)->key) == n.operands.end())
			for(k = 0; k < OP_SYMBOL(o)->nRegs; k++)
				n.operands.insert(std::pair<int, var_t>(OP_SYMBOL(o)->key, sym_to_index[std::pair<int, int>(OP_SYMBOL(o)->key, k)]));
	}
}

// A quick-and-dirty function to get the CFG from sdcc.
inline void create_cfg(cfg_t &cfg, con_t &con, ebbIndex *ebbi)
{
	eBBlock **ebbs = ebbi->bbOrder;
	iCode *start_ic;
	iCode *ic;

	std::map<int, unsigned int> key_to_index;
	std::map<std::pair<int, reg_t>, var_t> sym_to_index;

	start_ic = iCodeLabelOptimize(iCodeFromeBBlock (ebbs, ebbi->count));
	//start_ic = joinPushes(start_ic);

	int i;
	var_t j;
	for(ic = start_ic, i = 0, j = 0; ic; ic = ic->next, i++)
	{
		boost::add_vertex(cfg);
		key_to_index[ic->key] = i;

		cfg[i].ic = ic;

		for(int j2 = 0; j2 <= operandKey; j2++)
		{
			if(bitVectBitValue(ic->rlive, j2))
			{
				symbol *sym = (symbol *)(hTabItemWithKey(liveRanges, j2));

				if(!sym->for_newralloc)
					continue;

				// Add node to conflict graph:
				if(sym_to_index.find(std::pair<int, reg_t>(j2, 0)) != sym_to_index.end())
					continue;

				for(reg_t k = 0; k < sym->nRegs; k++)
				{
					boost::add_vertex(con);
					con[j].v = j2;
					con[j].byte = k;
					con[j].name = sym->name;
					sym_to_index[std::pair<int, reg_t>(j2, k)] = j;
					for(reg_t l = 0; l < k; l++)
						boost::add_edge(j - l - 1, j, con);
					j++;
				}
			}
		}		
	}
		
	// Get control flow graph from sdcc.
	for(ic = start_ic; ic; ic = ic->next)
	{
		if(ic->op != GOTO && ic->op != RETURN && ic->op != JUMPTABLE && ic->next)
			boost::add_edge(key_to_index[ic->key], key_to_index[ic->next->key], cfg);

		if(ic->op == GOTO)
			boost::add_edge(key_to_index[ic->key], key_to_index[eBBWithEntryLabel(ebbi, ic->label)->sch->key], cfg);
		else if(ic->op == RETURN)
			boost::add_edge(key_to_index[ic->key], key_to_index[eBBWithEntryLabel(ebbi, returnLabel)->sch->key], cfg);
		else if(ic->op == IFX)
			boost::add_edge(key_to_index[ic->key], key_to_index[eBBWithEntryLabel(ebbi, IC_TRUE(ic) ? IC_TRUE(ic) : IC_FALSE(ic))->sch->key], cfg);
		else if(ic->op == JUMPTABLE)
			for(symbol *lbl = (symbol *)(setFirstItem (IC_JTLABELS (ic))); lbl; lbl = (symbol *)(setNextItem (IC_JTLABELS (ic))))
				boost::add_edge(key_to_index[ic->key], key_to_index[eBBWithEntryLabel(ebbi, lbl)->sch->key], cfg);

		for(int i = 0; i <= operandKey; i++)
		{
			if(sym_to_index.find(std::pair<int, reg_t>(i, 0)) == sym_to_index.end())
				continue;

			if(bitVectBitValue(ic->rlive, i))
			{
				symbol *isym = (symbol *)(hTabItemWithKey(liveRanges, i));
				for(reg_t k = 0; k < isym->nRegs; k++)
					cfg[key_to_index[ic->key]].alive.insert(sym_to_index[std::pair<int, int>(i, k)]);
			}
		}

		add_operand_to_cfg_node(cfg[key_to_index[ic->key]], IC_RESULT(ic), sym_to_index);
		add_operand_to_cfg_node(cfg[key_to_index[ic->key]], IC_LEFT(ic), sym_to_index);
		add_operand_to_cfg_node(cfg[key_to_index[ic->key]], IC_RIGHT(ic), sym_to_index);
	}

	// Get conflict graph from sdcc
	for(var_t i = 0; i < num_vertices(con); i++)
	{
		symbol *isym = (symbol *)(hTabItemWithKey(liveRanges, con[i].v));
		for(int j = 0; j <= operandKey; j++)
			if(bitVectBitValue(isym->clashes, j))
			{
				//symbol *jsym = (symbol *)(hTabItemWithKey(liveRanges, j));
				if(sym_to_index.find(std::pair<int, reg_t>(j, 0)) == sym_to_index.end())
					continue;
				for(reg_t k = 0; k < isym->nRegs; k++)
					boost::add_edge(i, sym_to_index[std::pair<int, reg_t>(j, k)], con);
			}
	}

	// Check for unconnected live ranges, some might have survived dead code elimination.
	// Todo: Improve efficiency, e.g. using subgraph or filtered_graph.
	// Todo: Split live ranges instead?
	for(int i = boost::num_vertices(con) - 1; i >= 0; i--)
	{
		cfg_sym_t cfg2;
		boost::copy_graph(cfg, cfg2);
		for(int j = boost::num_vertices(cfg) - 1; j >= 0; j--)
		{
			if(cfg[j].alive.find(i) == cfg[j].alive.end())
			{
				boost::clear_vertex(j, cfg2);
				boost::remove_vertex(j, cfg2);
			}
		}
		std::vector<int> component(num_vertices(cfg2));
		if(boost::connected_components(cfg2, &component[0]) > 1)
		{
			//std::cerr << "Non-connected liverange found and spilt:" << con[i].name << "\n";
			for(unsigned int k = 0; k < boost::num_vertices(cfg) - 1; k++)
				cfg[k].alive./*insert*/erase(i);
		}
	}
}

// Computes live ranges for tree decomposition from live ranges from cfg.
inline void alive_tree_dec(tree_dec_t &tree_dec, const cfg_t &cfg)
{
	for(unsigned int i = 0; i < num_vertices(tree_dec); i++)
	{
		std::set<unsigned int>::const_iterator v;
		for(v = tree_dec[i].bag.begin(); v != tree_dec[i].bag.end(); ++v)
			tree_dec[i].alive.insert(cfg[*v].alive.begin(), cfg[*v].alive.end());
	}
}

#if 0
void print_assignment(const assignment &a)
{
	std::map<unsigned short int, unsigned short int>::const_iterator i;
	std::cout << "[";
	for(i = a.local.begin(); i != a.local.end(); ++i)
		std::cout << "(" << i->first << ", " << i->second << "), ";
	std::cout << "c: " << a.s << "]";
}
#endif

template <class I_t>
bool assignment_ok_conflict(const assignment &a, const I_t &I)
{
	std::set<var_t>::const_iterator i, j;

	for(i = a.local.begin(); i != a.local.end(); ++i)
		for(j = i, ++j; j != a.local.end(); ++j)
		{
			// Different registers - always OK.
			if(a.global[*i] != a.global[*j])
				continue;

			// Same registers - check for conflict.
			if(boost::edge(*i, *j, I).second)
				return(false);
		}
	return(true);
}

template<class G_t>
void assignments_introduce_instruction(std::list<assignment> &alist, unsigned short int i, const G_t &G)
{
	std::list<assignment>::iterator ai, ai_end;
	
	for(ai = alist.begin(), ai_end = alist.end(); ai != ai_end; ++ai)
	{
		std::set<var_t> i_variables;
		
		std::set_intersection(ai->local.begin(), ai->local.end(), G[i].alive.begin(), G[i].alive.end(), std::inserter(i_variables, i_variables.end()));
		
		i_assignment ia;
		
		std::set<var_t>::iterator v, v_end;
		for(v = i_variables.begin(), v_end = i_variables.end(); v != v_end; ++v)
			if(ai->global[*v] >= 0)
				ia.add_var(*v, ai->global[*v]);

		ai->i_assignments[i] = ia;
	}
}

template <class I_t>
void assignments_introduce_variable(std::list<assignment> &alist, unsigned short int i, short int v, const I_t &I)
{
	std::list<assignment>::iterator ai, ai_end, ai2;

	for(ai = alist.begin(), ai_end = alist.end(); ai != ai_end; ai = ai2)
	{
		ai2 = ai;
		++ai2;
		
		assignment a = *ai;
		a.local.insert(v);
		for(reg_t r = 0; r < NUM_REGS; r++)
		{
			a.global[v] = r;
			if(assignment_ok_conflict(a, I))
			{
				std::map<int, i_assignment>::iterator ia_i = a.i_assignments.find(i);
				i_assignment ia = ia_i->second;
				ia_i->second.add_var(v, r);
				alist.insert(ai2, a);
				ia_i->second = ia;
			}
		}
	}
}

// Cost function. Port-specific.
template <class G_t, class I_t>
float instruction_cost(const assignment &a, unsigned short int i, const G_t &G, const I_t &I);

// Handle Leaf nodes in the nice tree decomposition
template <class T_t, class G_t, class I_t>
void tree_dec_ralloc_leaf(T_t &T, typename boost::graph_traits<T_t>::vertex_descriptor t, const G_t &G, const I_t &I)
{
	//std::cout << "Leaf:\n";

	assignment a;
	std::list<assignment> &alist = T[t].assignments;

	a.s = 0;
	a.global.resize(boost::num_vertices(I), -1);
	alist.push_back(a);
	
	unsigned short int i = *(T[t].bag.begin());

	std::set<var_t>::const_iterator v;
	for(v = T[t].alive.begin(); v != T[t].alive.end(); ++v)
		assignments_introduce_variable(alist, i, *v, I);

	// Summation of costs and early removal of assignments.
	std::list<assignment>::iterator ai;
	for(ai = alist.begin(); ai != alist.end();)
	{
		if((ai->s += instruction_cost(*ai, i, G, I)) == std::numeric_limits<float>::infinity())
			ai = alist.erase(ai);
		else
			++ai;
	}

	/*std::list<assignment>::iterator ai;
	for(ai = alist.begin(); ai != alist.end(); ++ai)
		print_assignment(*ai);
	std::cout << "\n";*/
}

struct assignment_rep
{
	std::list<assignment>::iterator i;
	float s;

	bool operator<(const assignment_rep& a) const
	{
		return(s < a.s);
	}
};

// Ensure that we never get more than z80_opts.max_allocs_per_node assignments at a single node of the tree decomposition.
// Tries to drop the worst ones first (but never drop the empty assignment, as it's the only one guaranteed to be always valid).
void drop_worst_assignments(std::list<assignment> &alist)
{
	unsigned int i;
	size_t alist_size;
	std::list<assignment>::iterator ai, an;

	if((alist_size = alist.size()) * NUM_REGS <= z80_opts.max_allocs_per_node)
		return;

	//std::cerr << "Too many assignments here:" << z80_opts.max_allocs_per_node << "Dropping some.\n";

	assignment_rep *arep = new assignment_rep[alist_size];

	for(i = 0, ai = alist.begin(); i < alist_size; ++ai, i++)
	{
		arep[i].i = ai;
		arep[i].s = ai->s;
	}

	std::nth_element(arep + 1, arep + z80_opts.max_allocs_per_node / NUM_REGS, arep + alist_size);

	for(i = z80_opts.max_allocs_per_node / NUM_REGS; i < alist_size; i++)
		alist.erase(arep[i].i);
		
	delete[] arep;
}

// Handle introduce nodes in the nice tree decomposition
template <class T_t, class G_t, class I_t>
void tree_dec_ralloc_introduce(T_t &T, typename boost::graph_traits<T_t>::vertex_descriptor t, const G_t &G, const I_t &I)
{
	typedef typename boost::graph_traits<T_t>::adjacency_iterator adjacency_iter_t;
	adjacency_iter_t c, c_end;
	std::list<assignment>::iterator ai;
	boost::tie(c, c_end) = adjacent_vertices(t, T);

	//std::cout << "Introduce:\n";

	std::list<assignment> &alist = T[t].assignments;

	std::swap(alist, T[*c].assignments);

	std::set<var_t> new_vars;
	std::set_difference(T[t].alive.begin(), T[t].alive.end(), T[*c].alive.begin(), T[*c].alive.end(), std::inserter(new_vars, new_vars.end()));

	std::set<unsigned short> new_inst;
	std::set_difference(T[t].bag.begin(), T[t].bag.end(), T[*c].bag.begin(), T[*c].bag.end(), std::inserter(new_inst, new_inst.end()));
	unsigned short int i = *(new_inst.begin());
	
	// Extend to new instruction.
	assignments_introduce_instruction(alist, i, G);
	
	std::set<var_t>::const_iterator v;
	for(v = new_vars.begin(); v != new_vars.end(); ++v)
	{
		drop_worst_assignments(alist);
		assignments_introduce_variable(alist, i, *v, I);
	}

	// Summation of costs and early removal of assignments.
	for(ai = alist.begin(); ai != alist.end();)
	{
		if((ai->s += instruction_cost(*ai, i, G, I)) == std::numeric_limits<float>::infinity())
			ai = alist.erase(ai);
		else
			++ai;
	}

	/*std::list<assignment>::iterator ai;
	for(ai = alist1.begin(); ai != alist1.end(); ++ai)
		print_assignment(*ai);
	std::cout << "\n";*/
}

bool assignments_locally_same(const assignment &a1, const assignment &a2)
{
	if(a1.local != a2.local)
		return(false);

	std::set<var_t>::iterator i, i_end;

	for(i = a1.local.begin(), i_end = a1.local.end(); i != i_end; ++i)
		if(a1.global[*i] != a2.global[*i])
			return(false);
	
	return(true);
}

// Handle forget nodes in the nice tree decomposition
template <class T_t, class G_t, class I_t>
void tree_dec_ralloc_forget(T_t &T, typename boost::graph_traits<T_t>::vertex_descriptor t, const G_t &G, const I_t &I)
{
	typedef typename boost::graph_traits<T_t>::adjacency_iterator adjacency_iter_t;
	adjacency_iter_t c, c_end;
	boost::tie(c, c_end) = adjacent_vertices(t, T);

	//std::cout << "Forget: " << t << "\n";

	std::list<assignment> &alist = T[t].assignments;

	std::swap(alist, T[*c].assignments);

	std::set<unsigned short int> old_inst;
	std::set_difference(T[*c].bag.begin(), T[*c].bag.end(), T[t].bag.begin(), T[t].bag.end(), std::inserter(old_inst, old_inst.end()));
	unsigned short int i = *(old_inst.begin());

	std::set<var_t> old_vars;
	std::set_difference(T[*c].alive.begin(), T[*c].alive.end(), T[t].alive.begin(), T[t].alive.end(), std::inserter(old_vars, old_vars.end()));

	std::list<assignment>::iterator ai, aif;

	// Restrict assignments (locally) to current variables.
	for(ai = alist.begin(); ai != alist.end(); ++ai)
	{
		std::set<var_t>::iterator mi, mi2, m_end;
		for(mi = ai->local.begin(), m_end = ai->local.end(); mi != m_end; mi = mi2)
		{
			mi2 = mi;
			++mi2;
			if(old_vars.find(*mi) != old_vars.end())
				ai->local.erase(mi);
		}
		ai->i_assignments.erase(i);
	}

	alist.sort();

	// Collapse (locally) identical assignments.
	for(ai = alist.begin(); ai != alist.end();)
	{
		aif = ai;

		for(++ai; ai != alist.end() && assignments_locally_same(*aif, *ai);)
		{
			if(aif->s > ai->s)
			{
				alist.erase(aif);
				aif = ai;
				++ai;
			}
			else
			{
				alist.erase(ai);
				ai = aif;
				++ai;
			}
		}
	}

	/*for(ai = alist1.begin(); ai != alist1.end(); ++ai)
		print_assignment(*ai);
	std::cout << "\n";*/
}

// Handle join nodes in the nice tree decomposition
template <class T_t, class G_t, class I_t>
void tree_dec_ralloc_join(T_t &T, typename boost::graph_traits<T_t>::vertex_descriptor t, const G_t &G, const I_t &I)
{
	typedef typename boost::graph_traits<T_t>::adjacency_iterator adjacency_iter_t;
	adjacency_iter_t c, c_end, c2, c3;
	boost::tie(c, c_end) = adjacent_vertices(t, T);

	//std::cout << "Join:\n";

	c2 = c;
	++c;
	c3 = c;

	std::list<assignment> &alist1 = T[t].assignments;
	std::list<assignment> &alist2 = T[*c2].assignments;
	std::list<assignment> &alist3 = T[*c3].assignments;

	alist2.sort();
	alist3.sort();

	std::list<assignment>::iterator ai2, ai3;
	for(ai2 = alist2.begin(), ai3 = alist3.begin(); ai2 != alist2.end() && ai3 != alist3.end();)
	{
		if(assignments_locally_same(*ai2, *ai3))
		{
			ai2->s += ai3->s;
			// Avoid double-counting instruction costs.
			std::set<unsigned int>::iterator bi;
			for(bi = T[t].bag.begin(); bi != T[t].bag.end(); ++bi)
				ai2->s -= instruction_cost(*ai2, *bi, G, I);
			for(unsigned int i = 0; i < ai2->global.size(); i++)
				ai2->global[i] = ((ai2->global[i] != -1) ? ai2->global[i] : ai3->global[i]);
			alist1.push_back(*ai2);
			++ai2;
			++ai3;
		}
		else if(*ai2 < *ai3)
		{
			++ai2;
			continue;
		}
		else if(*ai3 < *ai2)
		{
			++ai3;
			continue;
		}
	}

	alist2.clear();
	alist3.clear();

	/*std::list<assignment>::iterator ai;
	for(ai = alist1.begin(); ai != alist1.end(); ++ai)
		print_assignment(*ai);
	std::cout << "\n";*/
}

// Handle nodes in the tree decomposition, by detecting their type and calling the appropriate function. Recurses.
template <class T_t, class G_t, class I_t>
void tree_dec_ralloc_nodes(T_t &T, typename boost::graph_traits<T_t>::vertex_descriptor t, const G_t &G, const I_t &I)
{
	typedef typename boost::graph_traits<T_t>::adjacency_iterator adjacency_iter_t;

	adjacency_iter_t c, c_end;
	typename boost::graph_traits<T_t>::vertex_descriptor c0, c1;

	boost::tie(c, c_end) = adjacent_vertices(t, T);

	switch(out_degree(t, T))
	{
	case 0:
		tree_dec_ralloc_leaf(T, t, G, I);
		break;
	case 1:
		c0 = *c;
		tree_dec_ralloc_nodes(T, c0, G, I);
		T[c0].bag.size() < T[t].bag.size() ? tree_dec_ralloc_introduce(T, t, G, I) : tree_dec_ralloc_forget(T, t, G, I);
		break;
	case 2:
		c0 = *c++;
		c1 = *c;
		tree_dec_ralloc_nodes(T, c0, G, I);
		tree_dec_ralloc_nodes(T, c1, G, I);
		tree_dec_ralloc_join(T, t, G, I);
		break;
	default:
		std::cerr << "Not nice.\n";
		break;
	}
}

// Dump con, with numbered nodes, show live variables at each node.
void dump_con(const con_t &con)
{
	std::ofstream dump_file((std::string(dstFileName) + ".dumpcon" + currFunc->rname + ".dot").c_str());

	std::string *name = new std::string[num_vertices(con)];
	for(unsigned int i = 0; i < num_vertices(con); i++)
	{
		std::ostringstream os;
		os << i;
		if(con[i].name)
			os << " : " << con[i].name << ":" << con[i].byte;
		name[i] = os.str();
	}
	write_graphviz(dump_file, con, boost::make_label_writer(name));
	delete[] name;
}

// Dump cfg, with numbered nodes, show live variables at each node.
void dump_cfg(const cfg_t &cfg)
{
	std::ofstream dump_file((std::string(dstFileName) + ".dumpcfg" + currFunc->rname + ".dot").c_str());

	std::string *name = new std::string[num_vertices(cfg)];
	for(unsigned int i = 0; i < num_vertices(cfg); i++)
	{
		std::ostringstream os;
		os << i << ", " << cfg[i].ic->key << ": ";
		std::set<var_t>::const_iterator v;
		for(v = cfg[i].alive.begin(); v != cfg[i].alive.end(); ++v)
			os << *v << " ";
		name[i] = os.str();
	}
	write_graphviz(dump_file, cfg, boost::make_label_writer(name));
	delete[] name;
}

// Dump tree decomposition, show bag and live variables at each node.
void dump_tree_decomposition(const tree_dec_t &tree_dec)
{
	std::ofstream dump_file((std::string(dstFileName) + ".dumpdec" + currFunc->rname + ".dot").c_str());

	unsigned int w = 0;

	std::string *name = new std::string[num_vertices(tree_dec)];
	for(unsigned int i = 0; i < num_vertices(tree_dec); i++)
	{
		if(tree_dec[i].bag.size() > w)
			w = tree_dec[i].bag.size();
		std::ostringstream os;
		std::set<unsigned int>::const_iterator v1;
		for(v1 = tree_dec[i].bag.begin(); v1 != tree_dec[i].bag.end(); ++v1)
			os << *v1 << " ";
		os << ": ";
		std::set<var_t>::const_iterator v2;
		for(v2 = tree_dec[i].alive.begin(); v2 != tree_dec[i].alive.end(); ++v2)
			os << *v2 << " ";
		name[i] = os.str();
	}
	write_graphviz(dump_file, tree_dec, boost::make_label_writer(name));
	delete[] name;
	
	//std::cout << "Width: " << (w  - 1) << "(" << currFunc->name << ")\n";
}

#endif

