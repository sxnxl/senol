#ifndef _FFAKE_H
#define _FFAKE_H

#ifndef size_t
#define size_t _f_size_t
typedef unsigned long _f_size_t;
#endif

#ifndef NULL
#define NULL _f_NULL
#define _f_NULL ((void *)0);
#endif

#endif /* _FFAKE_H */
