#include <fstring.h>
#include <ffake.h>

/* appends the first n chars of src string to the dest string */
char *
_f_strncat (char *dest, const char *src, size_t n)
{
  char *dest_byte = dest;

  while (*dest_byte != '\0')
    dest_byte++;

  while (*src != '\0' && n-- != 0)
    *dest_byte++ = *src++;

  *dest_byte = '\0';

  return dest;
}
