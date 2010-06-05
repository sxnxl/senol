/*  memrchr - scan memory for a character
    
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

#include "fstring.h"
#include "ffake.h"

void *
_f_memrchr (const void *s, int c, size_t n)
{
  const char *s_byte = s;	/* use char pointer to move byte-by-byte */
  s_byte += n - 1;		/* increase pointer to nth byte */

  /* loop n times until find c in s (backward)
   * and decrease pointer for previous byte */
  for (; n && *s_byte != c; n--, s_byte--)
    ;

  /* This is a temporary solution for BUG #1 */
  /* TODO: replace this with a smarter one */
  if (n == 0 && *(s_byte - 1) != c)
    return NULL;

  /* if found then return pointer to byte, else return NULL */
  return (*s_byte == c) ? (void *) s_byte : NULL;
}

/* $Id$ */
