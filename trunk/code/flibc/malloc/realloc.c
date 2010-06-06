/*  realloc - Grow or shrink dynamically allocated memory

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
#include <string.h>
#include <malloc.h>

#undef realloc

void *
realloc (void *ptr, size_t size)
{
  void *ptr_new = NULL;
  void *ptr_old = ptr;
  struct __meminfo *info_new = NULL;
  struct __meminfo *info_old = NULL;

  if (!size)
    {
      free (ptr_old);
      return NULL;
    }

  if (!ptr_old)
    return malloc (size);

  info_old = __mem2info (ptr_old);

  if (info_old->flags & __MEM_MEMALIGN)
    ptr_new = memalign (info_old->alignment, size);
  else
    ptr_new = malloc (size);

  if (!ptr_new)
    return NULL;

  info_new = __mem2info (ptr_new);

  if (info_new->size > info_old->size)
    {
      memcpy (ptr_new, ptr_old, info_old->size);
      if (info_old->flags & __MEM_CALLOC)
	{
	  memset ((void *) ((char *) ptr_new + info_old->size), 0,
		  info_new->size - info_old->size);
	  info_new->flags |= __MEM_CALLOC;
	}
    }
  else
    memcpy (ptr_new, ptr_old, info_new->size);

  return ptr;
}

/* $Id$ */
