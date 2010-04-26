#include <fstring.h>
#include <ffake.h>

/* copies n bytes between two memory areas, which must not overlap */
void *
_f_memcpy (void *dest, const void *src, size_t n)
{
  unsigned char *dest_byte = dest;
  const unsigned char *src_byte = src;

  while (n--)
    *dest_byte++ = *src_byte++;

  return dest;
}
