/*  atoi, atol, atoll - convert a string to an integer

    Copyright © 2010 Şenol Korkmaz <mail@senolkorkmaz.info>

    This file is part of flibc.

    flibc is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    flibc is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with flibc.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <limits.h>
#include <ctype.h>
#include <fake.h>
#include <stdlib.h>


#if !defined _atox_t || !defined _atox_type || !defined _atox_func
#  error "Do not compile atox.c directly; atoi, atol, atoll instead."
#endif

#define _ATOX_DIGIT _atox_type##_DIGIT
#define _ATOX_MAX _atox_type##_MAX
#define _ATOX_MIN _atox_type##_MIN

_atox_t
_atox_func (const char *nptr)
{
  int sign = 1;
  int retval = 0;
  int digits = _ATOX_DIGIT;

  /* ignore preceding white spaces */
  while (isspace (*nptr))
    nptr++;

  /* handle preceding sign if there is any */
  if (*nptr == '-' || *nptr == '+')
    sign = (*nptr++ == '+') ? 1 : -1;

  /* add digits to number (retval),
   * but not more than one less than the number of digits of INT_MAX */
  for (; isdigit (*nptr) && digits; nptr++, digits--)
    retval = retval * 10 + (*nptr - '0');

  if (!isdigit (*nptr))
    return sign * retval;
  else
    {
      if (retval > _ATOX_MAX / 10)
	goto overflow;
      else if (retval < _ATOX_MAX / 10)
	goto normal;
      else if (*nptr - '0' >
	       abs ((int) (((sign == 1) ? _ATOX_MAX : _ATOX_MIN) % 10)))
	goto overflow;
      else
	goto normal;
    }

normal:
  if (isdigit (*(nptr + 1)))
    goto overflow;
  else
    return sign * (retval * 10 + (*nptr - '0'));

overflow:
  return ((sign == 1) ? _ATOX_MAX : _ATOX_MIN);
}

/* $Id$ */
