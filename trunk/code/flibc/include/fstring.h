#include <ffake.h>

#ifndef _FSTRING_H
#define _FSTRING_H

/* /func: strlen */
#ifdef strlen
#undef strlen
#endif
#define strlen(str) _f_strlen(str)
size_t _f_strlen (const char *);
/* \func: strlen */


#endif /* HSTRING_H */
