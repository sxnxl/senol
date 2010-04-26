#include <fstring.h>
#include <ffake.h>

/* returns a pointer to the last (or backward first) occurrence of */
/* c in the first n bytes of s, or NULL if not found               */
void *
_f_memrchr (const void *s, char c, size_t n)
{
  const char *s_byte = s;
  s_byte += n - 1;

  for (; n && *s_byte != c; n--, s_byte--)
    ;

  return (*s_byte == c) ? (void *) s_byte : NULL;
}
