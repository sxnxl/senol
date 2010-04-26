#include <fstring.h>
#include <ffake.h>

/* fills the first n bytes of the memory area pointed to by s with the constant byte c. */
void *
_f_memset (void *s, int c, size_t n)
{
  unsigned char *s_byte = (unsigned char *) s;

  while (n--)
    *s_byte++ = c;

  return s;
}
