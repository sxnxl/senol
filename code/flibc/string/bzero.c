/*  bzero - write zero-valued bytes

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
#include <string.h>

/* This  function  is  deprecated  (marked  as  LEGACY  in  POSIX.1-2001):
 * use  memset(3) in new programs. */

void
bzero (void *s, size_t n)
{
  /* The bzero() function sets the first n bytes of the byte area starting at s
   * to zero, we may use the function memset() */
  memset (s, 0, n);
}

/* $Id$ */
