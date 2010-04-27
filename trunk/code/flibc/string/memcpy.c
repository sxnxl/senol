/*  memcpy - copy memory area
    Copyright © 2010 Şenol Korkmaz

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

/* memcpy does not care about memory overlaps,
 * use memmove for overlaping memory areas */
void *
_f_memcpy (void *dest, const void *src, size_t n)
{
  /* use char pointers to move byte-by-byte */
  unsigned char *dest_byte = dest;
  const unsigned char *src_byte = src;

  /* loop for n bytes */
  /* copy src byte to dest byte and increase pointers for next bytes */
  for (; n; n--)
    *dest_byte++ = *src_byte++;

  /* return pointer to memory area dest */
  return dest;
}
