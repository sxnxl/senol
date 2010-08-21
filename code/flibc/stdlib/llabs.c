/*  llabs - compute the absolute value of a long long integer

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

#include <fake.h>
#include <stdlib.h>

/* see xabs.c */

#ifdef _xabs_t
# undef _xabs_t
#endif
#define _xabs_t long long int	/* define return type (long long int) */

#ifdef _xabs_func
# undef _xabs_func
#endif
#define _xabs_func llabs	/* define function name as (llabs) */

#include "xabs.c"

/* $Id$ */
