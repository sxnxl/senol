#include <fstring.h>
#include <ffake.h>

/* returns a pointer to the first occurrence of      */
/* c in the first n bytes of s, or NULL if not found */
void *
_f_memchr (const void *s, char c, size_t n)
{
  while (n--)
    {
      if (*s++ == c)
	break;
    }
  return (void *) (n == 0 ? NULL : s);
}
