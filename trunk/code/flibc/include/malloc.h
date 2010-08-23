/*  malloc.h - Dynamic memory allocators

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

/*
  The malloc routines and its friends (calloc, realloc, etc.) allocatest memory
  by using system call mmap(). The actual memory area that is obtained from system
  is in the chunk form that is figured below.

       ______________________________________________________________________________
      |                   |                |                |                        |
Part: |      UNUSED       |      INFO      |     USABLE     |         UNUSED         |
----- |     --------      |     ------     |    --------    |        --------        |
Size: | __meminfo.padding | __MEMINFO_SIZE | __meminfo.size | __meminfo.alignment -  |
      |                   |                |                | __meminfo.padding      |
      |___________________|________________|________________|________________________|
      | size may be zero  |   exact size   | variable size  |    size may be zero    |


  Structure __meminfo is internally used by malloc routines
  to store information about dynamically allocated memory.

    .flags can be a combination of bits:
        __MEM_MALLOC
        __MEM_CALLOC
        __MEM_MEMALIGN

    .padding is used by aligned memory allocators to refer to the size
    of unused area that is at the beginning of the chunk.

    .alignment is used by aligned memory allocators to refer to the
    alignment of memory area.

    .size is used to refer the size of usable (requested) memory area
    that is allocated by dynamic memory allocators
*/

#ifndef _MALLOC_H
#define _MALLOC_H   1

#include <fake.h>

enum _mem_flags
{
  _MEM_MALLOC = 0x01,		/* Memory is allocated by malloc or its friends */
  _MEM_CALLOC = 0x02,		/* Memory is allocated by calloc (zeroed)       */
  _MEM_MEMALIGN = 0x04		/* Memory is allocated by memalign,.. (aligned) */
};

/* size of the info part of a chunk */
#define __MEMINFO_SIZE (sizeof(struct __meminfo))


/* get a pointer to the beginning of the chunk */
#define __info2chunk(info) ((void *)((char *)info - info->padding))


/* get a pointer to the info part of the chunk */
#define __mem2info(ptr) ((struct __meminfo *) ((char *)ptr - __MEMINFO_SIZE))


struct __meminfo
{
  enum _mem_flags flags;	/* allocator type */
  size_t padding;		/* size of unused area that is at beginning */
  size_t alignment;		/* alignment */
  size_t size;			/* usable (requested) size */
};

__BEGIN_DECLS
/* Allocate zeroed dynamic memory */
#undef calloc
extern void *calloc (size_t nmemb, size_t size);

/* Allocate dynamic memory */
#undef malloc
extern void *malloc (size_t);

/* Free dynamic memory */
#undef free
extern void free (void *ptr);

/* Grow or shrink dynamically allocated memory */
#undef realloc
extern void *realloc (void *ptr, size_t size);

/* Allocate aligned memory */
#undef posix_memalign
extern int posix_memalign (void **memptr, size_t alignment, size_t size);

/* Allocate aligned memory */
#undef memalign
extern void *memalign (size_t boundary, size_t size);

/* Allocate aligned memory */
#undef valloc
extern void *valloc (size_t size);

__END_DECLS
#endif /* malloc.h */
/* $Id$ */
