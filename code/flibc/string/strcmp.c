#include <fstring.h>
#include <ffake.h>

/* Return the length of the null-terminated string STR. */
int
_f_strcmp (const char *s1, const char *s2)
{
  for (; *s1 == *s2; s1++, s2++)
    ;

  return (int) *(const unsigned char *) s1 -
    (int) *(const unsigned char *) s2;
}
