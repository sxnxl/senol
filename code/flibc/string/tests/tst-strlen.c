#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#ifndef TEST_USING_FSTRING
# include <string.h>
#else
# include "fstring.h"
#endif

/* strlen proto : int strlen(const char *); */
#define TEST_STRLEN(S,E) \
  fprintf(stderr,"strlen( %s:\"%s\" ) = %d\n",#S,S,(int)strlen(S));\
  fprintf(stdout,"%d\n",(int)strlen(S));\
  assert (strlen(S) == E)

void
test_strlen ()
{
  const char *str35 = "This is a 35 character long string.";
  const char *str1 = "1";
  const char *str0 = "";
  const char *strNull = "\0";
  const char *strSpace = " ";

  TEST_STRLEN (str35,35);	/* = 35 */
  TEST_STRLEN (str1,1);		/* =  1 */
  TEST_STRLEN (str0,0);		/* =  0 */
  TEST_STRLEN (strNull,0);	/* =  0 */
  TEST_STRLEN (strSpace,1);	/* =  1 */
  TEST_STRLEN ("ÇĞIÜÖÇ½£",15);  /* = 15 */
  return ;
}

int
main (int argc, char **argv)
{
  fprintf (stderr,"TESTING %s\n",__FILE__+4);
  test_strlen ();
  exit (EXIT_SUCCESS);
}

/* $Id: test.c 23 2010-04-27 15:59:04Z senol.korkmaz $ */
