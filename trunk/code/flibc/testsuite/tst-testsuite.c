/*  tst-testsuite.c - Flibc testsuite

    Copyright © 2010 Şenol Korkmaz <mail@senolkorkmaz.info>

    This file is part of flibc.

    flibc is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    flibc is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with flibc.  If not, see <http://www.gnu.org/licenses/>.
*/

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
