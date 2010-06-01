/*  calloc - Allocate and free dynamic memory 

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

#include <string.h>
#include <errno.h>
#include <malloc.h>

#include <fake.h>

#undef calloc

void *
calloc (size_t nmemb, size_t lsize)
{
  void *ptr;
  struct __meminfo *info;
  size_t size = lsize * nmemb;

  if (nmemb && lsize != (size / nmemb))
    {
      set_errno (ENOMEM);
      return NULL;
    }

/* malloc */
  if (size)
    ptr = mmap (NULL, size + sizeof(struct __meminfo),
	      PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

  /* If size is 0, then return a NULL pointer, 	      */
  /* return null if memory mapping failed */
  /* that can later be successfully passed to free(). */
  if (ptr == MAP_FAILED || !size)
    return NULL;

  /* shift pointer from head of chunk to usable memory space */
  ptr += __MEMINFO_SIZE;

  /* get a pointer to __meminfo part of memory */
  info = __mem2info(ptr);
  
  /* fill __meminfo */
  info->flags = __MEM_MALLOC;
  info->size = size;
  
  /* memory is not aligned, so no padding and alignment */
  info->padding = 0;
  info->alignment = 0;
/* malloc */

  /* initialize memory content to zero, like memset(ptr,0,size) does */
  for (i = 0; i < size; i++)
    *(((char *) ptr) + i) = 0;

  return ptr;
}

/* $Id$ */
