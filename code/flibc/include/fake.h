/*  fake.h - Some fake macros

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

#ifndef _FAKE_H
#define _FAKE_H     1

#include <features.h>
#include <stddef.h>

/* C++ needs to know that types and declarations are C, not C++.  */
#ifdef __cplusplus
# define __BEGIN_DECLS  extern "C" {
# define __END_DECLS    }
#else
# define __BEGIN_DECLS
# define __END_DECLS
#endif /* __cplusplus */

/* TODO: we need to validate INT_BIT when compiling flibc */
#ifndef INT_BIT
#  define INT_BIT (CHAR_BIT * (sizeof(int) / sizeof(char)))
#else
#  warning "flibc using predefined INT_BIT"
#endif

#ifndef LOG_2
#  define LOG_2 ((double)0.301)
#endif

#ifndef INT_DIGIT
#  define INT_DIGIT ((int)(LOG_2*((double)(INT_BIT-1))))
#endif

#endif /* fake.h */

/* $Id$ */
