/*  memalign - Allocate aligned memory

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

void *
memalign (size_t boundary, size_t size)
{
  void *ptr;
  unsigned long int adj;

  result = malloc (size + alignment - 1);
  if (result == NULL)
    return NULL;

  adj =
    (unsigned long
     int) ((unsigned long int) ((char *) result - (char *) NULL)) % alignment;
  if (adj)
    {
      struct alignlist *l;
      __MALLOC_LOCK;
      for (l = _aligned_blocks; l != NULL; l = l->next)
	if (l->aligned == NULL)
	  /* This slot is free.  Use it.  */
	  break;
      if (l == NULL)
	{
	  l = (struct alignlist *) malloc (sizeof (struct alignlist));
	  if (l == NULL)
	    {
	      free (result);
	      result = NULL;
	      goto DONE;
	    }
	  l->next = _aligned_blocks;
	  _aligned_blocks = l;
	}
      l->exact = result;
      result = l->aligned = (char *) result + alignment - adj;
    DONE:
      __MALLOC_UNLOCK;
    }

  return result;
}

/* $Id$ */
