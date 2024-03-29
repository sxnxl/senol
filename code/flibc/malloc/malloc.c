/*  malloc - Allocate dynamic memory

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

#include "fake.h"
#include <sys/mman.h>
#include "malloc.h"

//#undef malloc

void *
malloc (size_t size)
{
  void *ptr = NULL;
  struct __meminfo *info = NULL;

  /* map memory to our virtual address space */
  if (size)
    ptr = mmap (NULL, size + sizeof (struct __meminfo),
		PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  /*
     If size is 0 or mapping failed, then return a NULL pointer,
     that can later be successfully passed to free().
   */
  if (ptr == MAP_FAILED || !size)
    return NULL;

  /* shift pointer from beginning of chunk to usable part */
  ptr += __MEMINFO_SIZE;

  /* get a pointer to __meminfo part of chunk */
  info = __mem2info (ptr);

  /* i'm malloc, so set __MEM_MALLOC flag */
  info->flags = __MEM_MALLOC;

  /* store size information */
  info->size = size;

  /* memory is not aligned, so padding and alignment is zero */
  info->padding = 0;
  info->alignment = 0;

  return (ptr);			/* happy end */
}

/* $Id$ */
