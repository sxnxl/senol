#include <stdio.h>
#include <fstring.h>

#define TEST_STRLEN(P) \
  printf("strlen ( %s: \"%s\" ) = %d\n",#P,P,(int)strlen(P))

int
main (int argc, char **argv)
{
  const char *str35 = "This is a 35 character long string.";
  const char *str1 = "1";
  const char *str0 = "";
  const char *strNull = "\0";
  const char *strSpace = " ";

  TEST_STRLEN (str35);
  TEST_STRLEN (str1);
  TEST_STRLEN (str0);
  TEST_STRLEN (strNull);
  TEST_STRLEN (strSpace);

  return 0;
}
