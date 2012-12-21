/* stm8.src/instcl.h */

  //virtual void incx(void);
  virtual int fetchea(t_mem code, unsigned char prefix);
  virtual int inst_adc(t_mem code, unsigned char prefix);
  virtual int inst_add(t_mem code, unsigned char prefix);
  virtual int inst_and(t_mem code, unsigned char prefix);
  virtual int inst_bccmbcpl(t_mem code, unsigned char prefix);
  virtual int inst_bcp(t_mem code, unsigned char prefix);
  virtual int inst_bresbset(t_mem code, unsigned char prefix);
  virtual int inst_btjfbtjt(t_mem code, unsigned char prefix);
  virtual int inst_call(t_mem code, unsigned char prefix);
  virtual int inst_callr(t_mem code, unsigned char prefix);
  virtual int inst_clr(t_mem code, unsigned char prefix);
  virtual int inst_cp(t_mem code, unsigned char prefix);
  virtual int inst_cpw(t_mem code, unsigned char prefix);
  virtual int inst_cpl(t_mem code, unsigned char prefix);
  virtual int inst_dec(t_mem code, unsigned char prefix);

  virtual int inst_inc(t_mem code, unsigned char prefix);
  virtual int inst_jp(t_mem code, unsigned char prefix);
  virtual int inst_jr(t_mem code, unsigned char prefix);
  virtual int inst_lda(t_mem code, unsigned char prefix);
  virtual int inst_lddst(t_mem code, unsigned char prefix);
  virtual int inst_ldw(t_mem code, unsigned char prefix);
  virtual int inst_neg(t_mem code, unsigned char prefix);
  virtual int inst_negw(t_mem code, unsigned char prefix);
  virtual int inst_or(t_mem code, unsigned char prefix);
  virtual int inst_rlc(t_mem code, unsigned char prefix);
  virtual int inst_rrc(t_mem code, unsigned char prefix);
  virtual int inst_rotw(t_mem code, unsigned char prefix);
  virtual int inst_sbc(t_mem code, unsigned char prefix);
  virtual int inst_sll(t_mem code, unsigned char prefix);
  virtual int inst_sra(t_mem code, unsigned char prefix);
  virtual int inst_srl(t_mem code, unsigned char prefix);
  virtual int inst_shiftw(t_mem code, unsigned char prefix);
  virtual int inst_sub(t_mem code, unsigned char prefix);
  virtual int inst_subw(t_mem code, unsigned char prefix);
  virtual int inst_swap(t_mem code, unsigned char prefix);
  virtual int inst_swapw(t_mem code, unsigned char prefix);
  virtual int inst_tnz(t_mem code, unsigned char prefix);
  virtual int inst_tnzw(t_mem code, unsigned char prefix);
  virtual int inst_trap(t_mem code, unsigned char prefix);
  virtual int inst_xor(t_mem code, unsigned char prefix);


  //virtual int inst_nop(t_mem code, bool prefix);
  //virtual int inst_transfer(t_mem code, bool prefix);
  //virtual int inst_setclearflags(t_mem code, bool prefix);
  //virtual int inst_rsp(t_mem code, bool prefix);
  //virtual int inst_nsa(t_mem code, bool prefix);
  //virtual int inst_lda(t_mem code, bool prefix);
  //virtual int inst_ldx(t_mem code, bool prefix);
  //virtual int inst_sta(t_mem code, bool prefix);
  //virtual int inst_stx(t_mem code, bool prefix);
  //virtual int inst_sub(t_mem code, bool prefix);
  //virtual int inst_sbc(t_mem code, bool prefix);
  //virtual int inst_cmp(t_mem code, bool prefix);
  //virtual int inst_cpx(t_mem code, bool prefix);
  //virtual int inst_jmp(t_mem code, bool prefix);
  //virtual int inst_jsr(t_mem code, bool prefix);
  //virtual int inst_ais(t_mem code, bool prefix);
  //virtual int inst_aix(t_mem code, bool prefix);
  //virtual int inst_and(t_mem code, bool prefix);
  //virtual int inst_bit(t_mem code, bool prefix);
  //virtual int inst_ora(t_mem code, bool prefix);
  //virtual int inst_eor(t_mem code, bool prefix);
  //virtual int inst_asr(t_mem code, bool prefix);
  //virtual int inst_lsr(t_mem code, bool prefix);
  //virtual int inst_lsl(t_mem code, bool prefix);
  //virtual int inst_rol(t_mem code, bool prefix);
  //virtual int inst_ror(t_mem code, bool prefix);
  //virtual int inst_inc(t_mem code, bool prefix);
  //virtual int inst_dec(t_mem code, bool prefix);
  //virtual int inst_dbnz(t_mem code, bool prefix);
  //virtual int inst_tst(t_mem code, bool prefix);
  //virtual int inst_clr(t_mem code, bool prefix);
  //virtual int inst_clrh(t_mem code, bool prefix);
  //virtual int inst_com(t_mem code, bool prefix);
  //virtual int inst_neg(t_mem code, bool prefix);
  //virtual int inst_pushpull(t_mem code, bool prefix);
  //virtual int inst_stop(t_mem code, bool prefix);
  //virtual int inst_wait(t_mem code, bool prefix);
  //virtual int inst_daa(t_mem code, bool prefix);
  //virtual int inst_mul(t_mem code, bool prefix);
  //virtual int inst_div(t_mem code, bool prefix);
  //virtual int inst_condbranch(t_mem code, bool prefix);
  //virtual int inst_bitsetclear(t_mem code, bool prefix);
  //virtual int inst_bittestsetclear(t_mem code, bool prefix);
  //virtual int inst_cbeq(t_mem code, bool prefix);
  //virtual int inst_rti(t_mem code, bool prefix);
  //virtual int inst_rts(t_mem code, bool prefix);
  //virtual int inst_mov(t_mem code, bool prefix);
  //virtual int inst_sthx(t_mem code, bool prefix);
  //virtual int inst_ldhx(t_mem code, bool prefix);
  //virtual int inst_cphx(t_mem code, bool prefix);
  //virtual int inst_swi(t_mem code, bool prefix);
  //virtual int inst_bsr(t_mem code, bool prefix);


/* End of stm8.src/instcl.h */