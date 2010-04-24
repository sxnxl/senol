#include <fstring.h>
#include <ffake.h>

/* returns a pointer to the first occurrence of      */
/* c in the first n bytes of s, or NULL if not found */
void *
_f_memchr (const void *s, char c, size_t n)
{
  char *chr = (unsigned char *) s;
  void *ret = NULL;

  while (n--)			/* loop n times for first n bytes */
    {
      if (*chr == c)
	{
	  ret = (void *) chr;	/* found, set return value to chr pointer */
	  break;		/* found, let's break */
	}
      else if (*chr == '\0')	/* null-terminator so we've reached end of string */
	break;			/* not found, lets break */
      chr++;
    }

  return ret;
}
