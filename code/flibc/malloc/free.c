/*  free - Free dynamic memory

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
#include <sys/mman.h>
#include <malloc.h>

#undef free

void
free (void *ptr)
{
  struct __meminfo *info;
  void *chunk;

  /* do nothing and return if ptr is NULL*/
  if (!ptr)
    return;

  /* get a pointer to __meminfo part of chunk */
  info = __mem2info (ptr);

  /* get a pointer to the beginning of chunk */
  chunk = __info2chunk (info);

  /* remove mapping using munmap */
  /* total size of chunk is (info->size + info->padding + __MEMINFO_SIZE) */
  if (info->flags & __MEM_MALLOC)
    munmap (chunk, info->size + info->padding + __MEMINFO_SIZE);
}

/* $Id$ */
