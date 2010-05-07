/*  memchr - scan memory for a character

    Copyright © 2010 Şenol Korkmaz <mail@senolkorkmaz.info>
    Copyright © 2010 Sarı Çizmeli Mehmet Ağa (aka. John Doe) <scma@senolkorkmaz.info>

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

#include "fstring.h"
#include "ffake.h"

void *
_f_memchr (const void *s, int c, size_t n)
{
  /* use unsigned char pointer to move byte-by-byte */
  const unsigned char *s_byte = s;

  /* loop n times until find c in s
   * and increase pointer for next byte */
  for (; n && *s_byte != c; n--, s_byte++)
    ;

  /* If n is zero, that means there is no c found in the first n bytes of s */
  /* if found then return pointer to byte, otherwise return NULL */
  return (n == 0) ? NULL : (void *) s_byte;
}

/* $Id$ */
