/*  string.h - String functions header file

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

#include <ffake.h>

#ifndef _FSTRING_H
#define _FSTRING_H

#undef strlen
#define strlen(str) _f_strlen(str)
extern size_t _f_strlen (const char *);

#undef memchr
#define  memchr(s,c,n) _f_memchr(s,c,n)
extern void *_f_memchr (const void *, int, size_t);

#undef memrchr
#define  memrchr(s,c,n) _f_memrchr(s,c,n)
extern void *_f_memrchr (const void *, int, size_t);

#undef memcmp
#define memcmp(s,c,n) _f_memcmp(s,c,n)
extern int _f_memcmp (const void *, const void *, size_t);

#undef memcpy
#define memcpy(d,s,n) _f_memcpy(d,s,n)
extern void *_f_memcpy (void *, const void *, size_t);

#undef memmove
#define memmove(d,s,n) _f_memmove(d,s,n)
extern void *_f_memove (void *, const void *, size_t);

#undef memset
#define memset(s,c,n) _f_memset(s,c,n)
extern void *_f_memset (void *, int, size_t);

#undef strcat
#define strcat(d,s) _f_strcat(d,s)
extern char *_f_strcat (char *, const char *);

#undef strncat
#define strncat(d,s,n) _f_strcat(d,s,n)
extern char *_f_strncat (char *, const char *, size_t);

#undef strchr
#define strchr(s,c) _f_strchr(s,c)
extern char *_f_strchr (const char *, int);

#undef strrchr
#define strrchr(s,c) _f_strrchr(s,c)
extern char *_f_strrchr (const char *, int);

#undef strcmp
#define strcmp(s,t) _f_strcmp(s,t)
extern int _f_strcmp (const char *, const char *);

#undef strncmp
#define strncmp(s,t,n) _f_strncmp(s,t,n)
extern int _f_strncmp (const char *, const char *, size_t);

#undef strcoll
#define strcoll(s1,s2) _f_strcoll(s1,s2)
extern int _f_strcoll(const char *s1, const char *s2);

#undef strcpy
#define strcpy(dest,src) _f_strcpy(dest,src)
extern char *_f_strcpy(char *dest, const char *src);

#undef strncpy
#define strncpy(dest,src,n) _f_strcpy(dest,src,n)
extern char *_f_strncpy(char *dest, const char *src, size_t n);

#undef strspn
#define strspn(s,accept) _f_strspn(s,accept)
extern size_t _f_strspn(const char *s, const char *accept);

#undef strcspn
#define strcspn(s,reject) _f_strcspn(s,reject)
extern size_t _f_strcspn(const char *s, const char *reject);

#undef strpbrk
#define strpbrk(s,accept) _f_strpbrk(s,accept)
extern char *_f_strpbrk(const char *s, const char *accept);

#undef strstr
#define strstr(haystack,needle) _f_strstr(haystack,needle)
extern char *_f_strstr(const char *haystack, const char *needle);

/* TODO
- string.h
--- strerror
--- strtok
--- strxfrm
*/

#endif /* _FSTRING_H */
/* $Id$ */
