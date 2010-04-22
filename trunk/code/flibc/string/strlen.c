#include <fstring.h>
#include <ffake.h>

/* Return the length of the null-terminated string STR.  Scan for */
/* the null terminator quickly by testing four bytes at a time.   */
size_t
_f_strlen (const char *str)
{
  size_t ret = 0;

  while (*str++ != '\0')
    ret++;

  return ret;
}
