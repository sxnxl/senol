/*  abs, labs, llabs - compute the absolute value of an integer

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

#include <fake.h>
#include <stdlib.h>

#if !defined _xabs_t || !defined _xabs_func
#  error "Do not compile xabs.c directly; abs, labs, llabs instead."
#endif

_xabs_t
_xabs_func (_xabs_t j)
{
  /* if j is negative then absolute value is positive of itself (-j),
   * if j is positive then absolute value is itself (j) */
  return j < 0 ? -j : j;
}

/* $Id$ */
