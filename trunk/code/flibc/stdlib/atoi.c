/*  atoi - convert a string to an integer

    Copyright (C) 2010 Şenol Korkmaz <mail@senolkorkmaz.info>

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

#include <limits.h>
#include <ctype.h>
#include <fake.h>
#include <stdlib.h>

/* see atox.c */

#ifdef _atox_t
# undef _atox_t
#endif
#define _atox_t int		/* define return type (int) */

#ifdef _atox_type
# undef _atox_type
#endif
#define _atox_type INT		/* define function type (INT) */

#ifdef _atox_func
# undef _atox_func
#endif
#define _atox_func atoi		/* define function name as (atoi) */

#include "atox.c"

/* $Id$ */
