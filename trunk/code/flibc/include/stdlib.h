/*  malloc.h - Dynamic memory allocators

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

#ifndef _STDLIB_H
#define _STDLIB_H   1

#include <fake.h>

__BEGIN_DECLS
/* Compute the absolute value of an integer */
#undef abs
extern int abs (int j);

/* Compute the absolute value of an long integer */
#undef labs
extern long int labs (long int j);

/* Compute the absolute value of an long long integer */
#undef llabs
extern long long int llabs (long long int j);

__END_DECLS
#endif /* stdlib.h */
/* $Id$ */
