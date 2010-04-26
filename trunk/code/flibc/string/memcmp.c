#include <fstring.h>
#include <ffake.h>

/* compares the first n bytes of two memory areas */
int
_f_memcmp (const void *s1, const void *s2, size_t n)
{
  const unsigned char *s1_byte = s1;
  const unsigned char *s2_byte = s2;

  for (; n && *s1_byte == *s1_byte; n--, s1_byte++, s2_byte++)
    ;

  return (int) *s1_byte - (int) *s2_byte;
}
