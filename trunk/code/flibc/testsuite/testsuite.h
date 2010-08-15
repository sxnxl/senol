/*  testsuite.h - Flibc testsuite headers

    Copyright © 2010 Şenol Korkmaz <mail@senolkorkmaz.info>
    Copyright © 2010 Sarı Çizmeli Mehmet Ağa (a.k.a. John Doe) <scma@senolkorkmaz.info>

    This file is part of flibc.

    flibc is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    flibc is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with flibc.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _TESTSUITE_H
#define _TESTSUITE_H    1

#include <fake.h>

#if !defined _TEST_FUNC_NAME
# error "Function name (_TEST_FUNC_NAME) is not defined!"
#elif !defined _TEST_FUNC_ARGC
# warning "Number of arguments which function takes (_TEST_ARGC) is not defined!\n" \
          "Function will be called without argument."
# define _TEST_FUNC_ARGC 0
# elif !defined _TEST_FUNC_TYPE
# warning "Return type of function (_TEST_FUNC_TYPE) is not defined! It will be treated as void."
# define _TEST_FUNC_T void
#endif

#ifdef __TEST_ARG_T_1
# define __argv_1

#if __argc == 0
# define __argv
# define __argv_declare
#elif __argc == 1
# define __argv __argv_1
#elif __argc == 2
# define __argv __argv_1, __argv_2
#elif __argc == 3
#
#elif __argc == 4
#
#elif __argc == 5
#
#endif

#define __func _TEST_FUNC
#define __type _TEST_FUNC_T
#define __argc _TEST_FUNC_ARGC
#define __argv
#define __argtv
#define __args_declare
#define __vargs_get

__type
_test (int argc, ...)
{
  __type retval;
  __argv_declare;
  va_list ap;

  va_start (argc, ap);

  __vargs_get;

  retval = __func (__argv);

  return retval;
}


#endif /* testsuite.h */

/* $Id$ */
