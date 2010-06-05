/*  calloc - Allocate dynamic memory and set to zero

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

#include <fake.h>
#include <errno.h>
#include <malloc.h>

#undef calloc

void *
calloc (size_t nmemb, size_t lsize)
{
  void *ptr;
  struct __meminfo *info;
  size_t size = lsize * nmemb;
  size_t size_i;

  /* if size overflow occurs, then set errno to ENOMEM and return NULL */
  if (nmemb && lsize != (size / nmemb))
    {
      set_errno (ENOMEM);
      return NULL;
    }

  /* allocate memory */
  ptr = malloc (size);

  /* get pointer to info part of memory */
  info = __mem2info (prt);

  /* fill memory with zeros and set __MEM_CALLOC flag */
  memset (ptr, 0, info->size);
  info->flags |= __MEM_CALLOC;

  return ptr;
}

/* $Id$ */
