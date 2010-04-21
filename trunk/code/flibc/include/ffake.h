#ifndef _FFAKE_H
#define _FFAKE_H

#ifndef size_t /* \fake: size_t*/
#define size_t _f_size_t
typedef unsigned long _f_size_t;
#endif /* \fake : size_t */


#if 0
#ifndef bool /* /fake: bool*/
#define bool _f_bool
typedef int _f_bool;
const int false = 0;
const int true = 1;
#endif /* \fake: bool */
#endif

#endif /* _FFAKE_H */
