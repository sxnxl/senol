#include <stdio.h>

#ifdef TEST_USE_STD
#include <string.h>
#define TEST_USING "string.h"
#else
#include "fstring.h"
#define TEST_USING "fstring.h"
#endif

#define TEST_STRLEN(S) \
  printf("strlen( %s:\"%s\" ) = %d\n",#S,S,(int)strlen(S))

#define TEST_MEMCHR(S,C,N) \
  printf("memchr( %s:\"%s\",'%c',%p) = %d\n",#S,S,C,N,memchr(S,C,N))


int
main (int argc, char **argv)
{
  const char *str35 = "This is a 35 character long string.";
  const char *str1 = "1";
  const char *str0 = "";
  const char *strNull = "\0";
  const char *strSpace = " ";

  printf("### USING %s ###\n",TEST_USING);

  TEST_STRLEN (str35);
  TEST_STRLEN (str1);
  TEST_STRLEN (str0);
  TEST_STRLEN (strNull);
  TEST_STRLEN (strSpace);
/*
  TEST_MEMCHR (str35);
  TEST_MEMCHR (str1);
  TEST_MEMCHR (str0);
  TEST_MEMCHR (strNull);
  TEST_MEMCHR (strSpace);
*/

  return 0;
}
