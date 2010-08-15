
#define _TEST_FNAME strlen
#define _TEST_FTYPE size_t
#define _TEST_ARGS_LEN 1
#define __TEST_ARGT_1 char*
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>

#include <testsuite.h>

int
main ()
{
  __test_func_type ret;
  ret __do_test (__TEST_ARGS_LEN, "test");
  printf ("%d \n", ret);
  return 0;
}
