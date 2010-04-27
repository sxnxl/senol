#include <ffake.h>

#ifndef _FSTRING_H
#define _FSTRING_H

#undef strlen
#define strlen(str) _f_strlen(str)
size_t _f_strlen (const char *);

#undef memchr
#define memchr(s,c,n) _f_memchr(s,c,n)
void *_f_memchr (const void *, int, size_t);

#undef memcmp
#define memcmp(s,c,n) _f_memcmp(s,c,n)
int _f_memcmp (const void *, const void *, size_t);

#undef memcpy
#define memcpy(d,s,n) _f_memcpy(d,s,n)
void *_f_memcpy (void *, const void *, size_t);

#undef memmove
#define memmove(d,s,n) _f_memmove(d,s,n)
void *_f_memove (void *, const void *, size_t);

#undef memset
#define memset(s,c,n) _f_memset(s,c,n)
void *_f_memset (void *, int, size_t);

#undef strcat
#define strcat(d,s) _f_strcat(d,s)
char *_f_strcat (char *, const char *);

#undef strncat
#define strncat(d,s,n) _f_strcat(d,s,n)
char *_f_strncat (char *, const char *, size_t);

#undef strchr
#define strchr(s,c) _f_strchr(s,c)
char *_f_strchr (const char *, int);

#undef strrchr
#define strrchr(s,c) _f_strchr(s,c)
char *_f_strrchr (const char *, int);

#undef strcmp
#define strcmp(s,t) _f_strcmp(s,t)
int _f_strcmp (const char *, const char *);

#undef strncmp
#define strncmp(s,t,n) _f_strncmp(s,t,n)
int _f_strncmp (const char *, const char *, size_t);


/* TODO
- string.h
--- strcoll
--- strcpy, strncpy
--- strcspn
--- strerror
+-- strlen
--- strpbrk
--- strspn
--- strstr
--- strtok
--- strxfrm
*/

#endif /* _FSTRING_H */
