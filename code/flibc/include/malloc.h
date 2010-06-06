/*  malloc.h - calloc, malloc, free, realloc    - Allocate and free dynamic memory
             - posix_memalign, memalign, valloc - Allocate aligned memory
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

#ifndef _MALLOC_H
#define _MALLOC_H   1

#include <fake.h>

#define __MEM_MALLOC 	1
#define __MEM_CALLOC 	2
#define __MEM_MEMALIGN	4

#define __MEMINFO_SIZE (sizeof(struct __meminfo))

#define __info2chunk(info) ((void *)info - info->padding)
#define __mem2info(ptr) ((struct __meminfo *) (ptr - __MEMINFO_SIZE))

struct __meminfo
{
  unsigned int flags;
  size_t padding;
  size_t alignment;
  size_t size;
};

__BEGIN_DECLS

#undef calloc
extern void *calloc (size_t nmemb, size_t size);

#undef malloc
extern void *malloc (size_t);

#undef free
extern void free (void *ptr);

#undef realloc
extern void *realloc (void *ptr, size_t size);

#undef posix_memalign
extern int posix_memalign(void **memptr, size_t alignment, size_t size);

#undef memalign
extern void *memalign (size_t boundary, size_t size);

#undef valloc
extern void *valloc (size_t size);

__END_DECLS

#endif				/* malloc.h */

/* $Id$ */
