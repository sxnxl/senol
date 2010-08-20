/*  string.h - String functions

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

#ifndef _FSTRING_H
#define _FSTRING_H  1

__BEGIN_DECLS
/* strlen - calculate the length of a string */
#undef strlen
extern size_t strlen (const char *s);

/* memchr - scan memory for a character */
#undef memchr
extern void *memchr (const void *s, int c, size_t n);

/* memrchr - scan memory for a character */
#undef memrchr
extern void *memrchr (const void *s, int c, size_t n);

/* memcmp - compare memory areas */
#undef memcmp
extern int memcmp (const void *s1, const void *s2, size_t n);

/* memcpy - copy memory area */
#undef memcpy
extern void *memcpy (void *dest, const void *src, size_t n);

/* memmove - copy memory area */
#undef memmove
extern void *memmove (void *dest, const void *src, size_t n);

/* memset - fill memory with a constant byte */
#undef memset
extern void *memset (void *s, int c, size_t n);

/* strcat - concatenate two strings */
#undef strcat
extern char *strcat (char *dest, const char *src);

/* strncat - concatenate two strings */
#undef strncat
extern char *strncat (char *dest, const char *src, size_t n);

/* strchr - locate character in string */
#undef strchr
extern char *strchr (const char *s, int c);

/* strrchr - locate character in string */
#undef strrchr
extern char *strrchr (const char *s, int c);

/* strcmp - compare two strings */
#undef strcmp
extern int strcmp (const char *s1, const char *s2);

/* strncmp - compare two strings */
#undef strncmp
extern int strncmp (const char *s1, const char *s2, size_t n);

/* strcoll - compare two strings using the current locale */
#undef strcoll
extern int strcoll (const char *s1, const char *s2);

/* strcpy - copy a string */
#undef strcpy
extern char *strcpy (char *dest, const char *src);

/* strncpy - copy a string */
#undef strncpy
extern char *strncpy (char *dest, const char *src, size_t n);

/* strspn - search a string for a set of characters */
#undef strspn
extern size_t strspn (const char *s, const char *accept);

/* strcspn - search a string for a set of characters */
#undef strcspn
extern size_t strcspn (const char *s, const char *reject);

/* strpbrk - search a string for any of a set of characters */
#undef strpbrk
extern char *strpbrk (const char *s, const char *accept);

/* strstr - locate a substring */
#undef strstr
extern char *strstr (const char *haystack, const char *needle);

/* strtok - extract tokens from strings */
#undef strtok
extern char *strtok (char *str, const char *delim);

/* strtok_r - extract tokens from strings */
#undef strtok_r
extern char *strtok_r (char *str, const char *delim, char **saveptr);

/* strdup - duplicate a string */
#undef strdup
extern char *strdup (const char *s);

/* strndup - duplicate a string */
#undef strndup
extern char *strndup (const char *s, size_t n);

#ifdef _GNU_SOURCE

/* memmem - locate a substring */
#undef memmem
extern void *memmem (const void *haystack, size_t haystacklen,
		     const void *needle, size_t needlelen);

/* strverscmp - compare two version strings */
#undef strverscmp
extern int strverscmp (const char *s1, const char *s2);

/* strnlen - determine the length of a fixed-size string */
#undef strnlen
extern size_t strnlen (const char *s, size_t maxlen);

/* memfrob - frobnicate (encrypt) a memory area */
#undef memfrob
extern void *memfrob (void *s, size_t n);

#endif /* _GNU_SOURCE */

__END_DECLS
#endif /* string.h */
/* $Id$ */
