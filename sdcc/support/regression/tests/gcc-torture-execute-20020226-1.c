/*
   20020226-1.c from the execute part of the gcc torture suite.
 */

#include <testfwk.h>

#ifdef __SDCC
#pragma std_c99
#endif

#if 0 // TODO:Enable when long long literal support is complete!
/* This tests the rotate patterns that some machines support.  */

#include <limits.h>

#ifndef CHAR_BIT
#define CHAR_BIT 8
#endif

#define ROR(a,b) (((a) >> (b)) | ((a) << ((sizeof (a) * CHAR_BIT) - (b))))
#define ROL(a,b) (((a) << (b)) | ((a) >> ((sizeof (a) * CHAR_BIT) - (b))))

#define CHAR_VALUE ((unsigned char)0x1234U)
#define SHORT_VALUE ((unsigned short)0x1234U)
#define INT_VALUE 0x1234U
#define LONG_VALUE 0x12345678LU
#define LL_VALUE 0x12345678abcdef0LLU

#define SHIFT1 4
#define SHIFT2 ((sizeof (long long) * CHAR_BIT) - SHIFT1)

unsigned char uc = CHAR_VALUE;
unsigned short us = SHORT_VALUE;
unsigned int ui = INT_VALUE;
unsigned long ul = LONG_VALUE;
unsigned long long ull = LL_VALUE;
int shift1 = SHIFT1;
int shift2 = SHIFT2;
#endif

void
testTortureExecute (void)
{
#if 0
  if (ROR (uc, shift1) != ROR (CHAR_VALUE, SHIFT1))
    ASSERT (0);

  if (ROR (uc, SHIFT1) != ROR (CHAR_VALUE, SHIFT1))
    ASSERT (0);

  if (ROR (us, shift1) != ROR (SHORT_VALUE, SHIFT1))
    ASSERT (0);

  if (ROR (us, SHIFT1) != ROR (SHORT_VALUE, SHIFT1))
    ASSERT (0);

  if (ROR (ui, shift1) != ROR (INT_VALUE, SHIFT1))
    ASSERT (0);

  if (ROR (ui, SHIFT1) != ROR (INT_VALUE, SHIFT1))
    ASSERT (0);

  if (ROR (ul, shift1) != ROR (LONG_VALUE, SHIFT1))
    ASSERT (0);

  if (ROR (ul, SHIFT1) != ROR (LONG_VALUE, SHIFT1))
    ASSERT (0);

  if (ROR (ull, shift1) != ROR (LL_VALUE, SHIFT1))
    ASSERT (0);

  if (ROR (ull, SHIFT1) != ROR (LL_VALUE, SHIFT1))
    ASSERT (0);

  if (ROR (ull, shift2) != ROR (LL_VALUE, SHIFT2))
    ASSERT (0);

  if (ROR (ull, SHIFT2) != ROR (LL_VALUE, SHIFT2))
    ASSERT (0);

  if (ROL (uc, shift1) != ROL (CHAR_VALUE, SHIFT1))
    ASSERT (0);

  if (ROL (uc, SHIFT1) != ROL (CHAR_VALUE, SHIFT1))
    ASSERT (0);

  if (ROL (us, shift1) != ROL (SHORT_VALUE, SHIFT1))
    ASSERT (0);

  if (ROL (us, SHIFT1) != ROL (SHORT_VALUE, SHIFT1))
    ASSERT (0);

  if (ROL (ui, shift1) != ROL (INT_VALUE, SHIFT1))
    ASSERT (0);

  if (ROL (ui, SHIFT1) != ROL (INT_VALUE, SHIFT1))
    ASSERT (0);

  if (ROL (ul, shift1) != ROL (LONG_VALUE, SHIFT1))
    ASSERT (0);

  if (ROL (ul, SHIFT1) != ROL (LONG_VALUE, SHIFT1))
    ASSERT (0);

  if (ROL (ull, shift1) != ROL (LL_VALUE, SHIFT1))
    ASSERT (0);

  if (ROL (ull, SHIFT1) != ROL (LL_VALUE, SHIFT1))
    ASSERT (0);

  if (ROL (ull, shift2) != ROL (LL_VALUE, SHIFT2))
    ASSERT (0);

  if (ROL (ull, SHIFT2) != ROL (LL_VALUE, SHIFT2))
    ASSERT (0);

  return;
#endif
}

