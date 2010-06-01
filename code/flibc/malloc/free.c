/*  free - Allocate and free dynamic memory 

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

#include <malloc.h>
#include <fake.h>

#undef free 

void
free (void *ptr)
{
  struct __meminfo *info;
  void *chunk;

  /* get a pointer to __meminfo part of chunk */
  info = mem2info(ptr);

  /* get a pointer to beginning of chunk */
  chunk = info2chunk(info);

  /* unmap using munmap */
  /* total size of chunk is (info->size + info->padding + __MEMINFO_SIZE) */
  if (ptr && (info->flags & __MEM_MALLOC))
    munmap (chunk, info->size + info->padding + __MEMINFO_SIZE);
}

/* $Id$ */
