/*  memmove - copy memory area
    
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

/* memmove handles memory overlaps */
void *
_f_memmove (void *dest, const void *src, size_t n)
{
  /* use char pointers to move byte-by-byte */
  unsigned char *dest_byte = dest;
  const unsigned char *src_byte = src;

  /* compare positions of first bytes to handle overlaps */
  if (dest_byte > src_byte)
    {
      /* src comes first in memory and memory areas overlaps */
      /* increase pointers to nth bytes for backward copying */
      src_byte += n - 1;
      dest_byte += n - 1;

      /* use backward copying */
      for (; n; n--)
	*dest_byte-- == *src_byte--;
    }
  else
    {
      /* we dont need to care about overlap */
      /* use forward copying */
      for (; n; n--)
	*dest_byte++ = *src_byte++;
    }

  /* return pointer to memory area dest */
  return dest;
}

/* $Id$ */
