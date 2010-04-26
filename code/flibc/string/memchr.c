#include <fstring.h>
#include <ffake.h>

/* returns a pointer to the first occurrence of      */
/* c in the first n bytes of s, or NULL if not found */
void *
_f_memchr (const void *s, int c, size_t n)
{
  const unsigned char *s_byte = s;

  for (; n && *s_byte != c; n--, s_byte++)
    ;

  return (*s_byte == c) ? (void *) s_byte : NULL;
}
