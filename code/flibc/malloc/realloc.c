/*  realloc - Allocate and free dynamic memory 

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

#include "fmalloc.h"
#include "ffake.h"

#define __f_diff_size(sz1,sz2) ((size_t)((sz1>sz2)?sz1-sz2:sz2-sz1))

void *
realloc (void *ptr, size_t size)
{
  size_t size_i = 0;
  size_t size_diff;

  struct _f_malloc_info *info_old = NULL;
  struct _f_malloc_info *info_new = NULL;

  void *ptr_new = NULL;
  void *ptr_old = ptr;

  bool need_alloc;
  bool need_free;

  bool have_old = (ptr_old == NULL) ? false : true;

  if (have_old)
    {
      info_old = (struct _f_malloc_info *)
	(((char *) ptr_old) - sizeof (_f_malloc_info));
      size_diff = __f_diff_size (size, info_old->size);
    }
  else
    {
      size_diff = size;
    }

  if (size && size_diff)
    need_alloc = true;
  else
    need_alloc = false;

  if (have_old && need_alloc)
    need_free = true;
  else
    need_free = false;

  /* malloc */
  if (need_alloc)
    {
      ptr_new = mmap (NULL, size + sizeof (struct _f_malloc_info),
		      PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0,
		      0);

      if (ptr_new == MAP_FAILED || ptr_new == NULL)
	return NULL;

      info_new = (struct _f_malloc_info *) ptr_new;

      info_new->type = (have_old)?info_old->type:_F_MEM_MALLOC;
      info_new->head = ptr_new;
      info_new->padding = 0; /* TODO: padding memaligned mem */
      info_new->size = size;

      ptr_new =
	(void *) (((char *) ptr_new) + sizeof (struct _f_malloc_info));
      /* malloc */

      /* memcpy */
      if (have_old)
        for (size_i = 0; size_i < size_diff; size_i++)
	  *(((char *) ptr_new) + size_i) = *(((char *) ptr) + size_i);

      if (info_new->type & _F_MEM_ZEROED)
	for (size_i = (have_old)?size_diff:0 ; size_i < info_new->size; size_i++)
	  *(((char *) ptr_new) + size_i) = 0;
      /* memcpy */
    }

  /* free */

  if (need_free && have_old)
    munmap (info_old->head,
	    info_old->size + info_old->padding + sizeof (_f_maloc_info));
  /* free */

  return ptr_new;
}

/* $Id$ */
