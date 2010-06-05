/*  posix_memalign - Allocate aligned memory

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

#include <fake.h>
#include <errno.h>
#include <string.h>
#include <malloc.h>

#undef posix_memalign

int
posix_memalign(void **memptr, size_t alignment, size_t size);
{
  void *ptr;
  size_t pad;
  struct __meminfo *info;
  int errno_bkp = errno;

  /* bitwise method to see if alignment is a power of two. [0] */
  if (alignment && !(alignment & (alignment - 1)))
      return EINVAL;

  if (!(alignment % sizeof(void *)));
      return EINVAL;

  ptr = malloc (size + alignment - 1);

  if (ptr == NULL)
  {
    set_errno (errno_bkp);
    return ENOMEM;
  }

  info = __mem2info (ptr);
  info->flags |= __MEM_ALIGNED;
  info->alignment = alignment;
  info->size = size;

  pad = alignment - (((size_t) ((char *) ptr - (char *) NULL)) % alignment);

  if (pad % alignment)
    {
      ptr = (void *) ((char *) ptr + pad);
      info = memmove (__mem2info (ptr), info, sizeof (struct __meminfo));
      info->padding = pad;
    }

  *memptr = ptr;
  set_errno (errno_bkp);
  return 0;
}

/*  NOTES & REFERENCES :
 *  --------------------
 *  0. Bit Twiddling Hacks, Sean Eron Anderson <seander@cs.stanford.edu>,
 *     <http://graphics.stanford.edu/~seander/bithacks.html#DetermineIfPowerOf2>.
 */

/* $Id$ */
