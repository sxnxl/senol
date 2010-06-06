/*  memset - fill memory with a constant byte

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

#include <string.h>
#include <fake.h>

void *
memset (void *s, int c, size_t n)
{
  /* use char pointer to move byte-by-byte */
  char *s_byte = (char *) s;

  for (; n; n--)		/* loop for n bytes */
    *s_byte++ = c;		/* set byte to c and move next byte */

  /* return pointer to memory area */
  return s;
}

/* $Id$ */
