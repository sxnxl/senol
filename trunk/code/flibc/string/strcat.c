#include <fstring.h>
#include <ffake.h>

/* appends the src string to the dest string */
char *
_f_strcat (char *dest, const char *src)
{
  char *dest_byte = dest;

  while (*dest_byte != '\0')
    dest_byte++;

  while (*src != '\0')
    *dest_byte++ = *src++;

  *dest_byte = '\0';

  return dest;
}
