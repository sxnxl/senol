/*  malloc.h - calloc, malloc, free, realloc - Allocate and free dynamic memory
	     - memalign, valloc - Allocate aligned memory
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

#ifndef _MALLOC_H
#define _MALLOC_H	1

#define __MEM_MALLOC 	1
#define __MEM_ZEROED 	2
#define __MEM_ALIGNED	4

#define __MEMINFO_SIZE (sizeof(struct __meminfo))

#define __info2chunk(info) ((void *)info - info->padding)
#define __mem2info(ptr) ((struct __meminfo *) (ptr - __MEMINFO_SIZE))

extern void *calloc(size_t nmemb, size_t size);
extern void *malloc(size_t size);
extern void free(void *ptr);
extern void *realloc(void *ptr, size_t size);
extern void *valloc(size_t size);
extern void *memalign(size_t boundary, size_t size);

struct __meminfo
{
	unsigned int flags;
	size_t padding;
	size_t alignment;
	size_t size;
}

#endif /* malloc.h */

/* $Id$ */
