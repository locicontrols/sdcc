#ifndef __TESTFWK_H
#define __TESTFWK_H 1

extern int __numTests;

void __fail(const char *szMsg, const char *szCond, const char *szFile, int line);
void __printf(const char *szFormat, ...);

#define ASSERT(_a) 	(__numTests++, (_a) ? (void)0 : __fail("Assertion failed", #_a, __FILE__, __LINE__))
#define LOG(_a)		__printf _a

typedef void TESTFUN(void);

// Provided by the suite
void **
suite(void);

const char *
getSuiteName(void);

#define NULL	0

#endif
