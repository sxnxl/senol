#include <fstring.h>
#include <ffake.h>

/* returns a pointer to the first occurrence of the character c in the string s. */
char *
_f_strchr (const char *s, int c)
{
  while (*s != '\0')
    if (*s == c)
      return (char *) s;
    else
      s++;

  return (c == '\0') ? (char *) s : NULL;
}
