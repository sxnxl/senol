#include <fstring.h>
#include <ffake.h>

/* returns a pointer to the last occurrence of the character c in the string s. */
char *
_f_strrchr (const char *s, int c)
{
  const char *last = NULL;

  while (*s != '\0')
    if (*s == c)
      last = s;
    else
      s++;

  if (c == '\0')
    last = s;

  return (char *) last;
}
