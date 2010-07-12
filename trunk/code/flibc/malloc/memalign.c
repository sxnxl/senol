/*  memalign - Allocate aligned memory

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

void *
memalign (size_t boundary, size_t size)
{
  void *ptr;
  size_t pad;
  struct __meminfo *info;

  /*
     boundary should be a power of 2 as required by standards.
     If not, set errno to EINVAL and return NULL pointer.
     Use bitwise method to see if boundary is a power of two. [0]
   */
  if (boundary && !(boundary & (boundary - 1)))
    {
      set_errno (EINVAL);
      return NULL;
    }

  /*
     If the address returned by malloc is already aligned, we will not have
     anything to deal with, otherwise we have to align it manually by moving
     usable part of chunk. We need to obtain some extra space to move usable
     part in chunk. The worst case is address returned by malloc that is one
     more of a multiple of boundary. We should (obtain boundary - 1) bytes more
     to deal with the worst case. (Note that -1 % boundary = boundary - 1)
   */
  ptr = malloc (size + boundary - 1);

  /* return NULL if malloc fails */
  if (ptr == NULL)
    return NULL;

  info = __mem2info (ptr);	/* get info part of the chunk */
  info->flags |= __MEM_MEMALIGN;	/* I'm memalign so set my flag */
  info->alignment = boundary;	/* set alignment */

  /*
     size was (size + boundary - 1) when calling malloc,
     but this is not the actual size of usable part.
     (boundary - 1) bytes are unusable,
     so we need to set size of usable part to (size)
   */
  info->size = size;

  /* how much padding we need? */
  pad = boundary - (((size_t) ((char *) ptr - (char *) NULL)) % boundary);

  /* if we need padding */
  if (pad % boundary)
    {
      /* move address of usable part to (pad) bytes forward */
      ptr = (void *) ((char *) ptr + pad);
      /* move info part */
      info = memmove (__mem2info (ptr), info, sizeof (struct __meminfo));
      /* store padding information */
      info->padding = pad;
    }

  return ptr;			/* happy end */
}

/*
 NOTES & REFERENCES :
 --------------------
 0. Bit Twiddling Hacks, Sean Eron Anderson <seander@cs.stanford.edu>,
    <http://graphics.stanford.edu/~seander/bithacks.html#DetermineIfPowerOf2>.
*/

/* $Id$ */
