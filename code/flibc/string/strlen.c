#include <fstring.h>
#include <ffake.h>

/* Return the length of the null-terminated string STR. */
size_t
_f_strlen (const char *str)
{
  size_t len = 0;

  while (*str++ != '\0')
    len++;

  return len;
}
