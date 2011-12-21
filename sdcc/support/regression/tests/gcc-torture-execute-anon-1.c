/*
   anon-1.c from the execute part of the gcc torture tests.
 */

#include <testfwk.h>

#ifdef SDCC
#pragma std_c89
#endif

/* Copyright (C) 2001 Free Software Foundation, Inc.  */

/* Source: Neil Booth, 4 Nov 2001, derived from PR 2820 - field lookup in
   nested anonymous entities was broken.  */

struct
{
  int x;
  struct
  {
    int a;
    union
    {
      int b;
    };
  };
} foo;

void
testTortureExecute (void)
{
  foo.b = 6;
  foo.a = 5;

  if (foo.b != 6)
    ASSERT (0);

  return;
}

