#include <ffake.h>

#ifndef _FSTRING_H
#define _FSTRING_H

#ifdef strlen
#undef strlen
#endif
#define strlen(str) _f_strlen(str)
size_t _f_strlen (const char *);

#ifdef memchr
#undef memchr
#endif
#define memchr(s,c,n) _f_memchr(s,c,n)
void *_f_memchr (const void *s, char c, size_t n);

#endif /* _FSTRING_H */
