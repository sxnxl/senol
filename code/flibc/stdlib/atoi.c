/*  atoi - convert a string to an integer

    Copyright © 2010 Şenol Korkmaz <mail@senolkorkmaz.info>
    Copyright © 2010 Sarı Çizmeli Mehmet Ağa (a.k.a. John Doe) <scma@senolkorkmaz.info>

    This file is part of flibc.

    flibc is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    flibc is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with flibc.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <limits.h>
#include <ctype.h>
#include <stdlib.h>

int
atoi (const char *nptr)
{
  int sign = 1;
  int retval = 0;
  int int_bound = INT_MAX / 10;

  /* ignore preceding white spaces */
  while (isspace (*nptr))
    nptr++;

  /* handle preceding sign if there is any */
  if (*nptr == '-' || *nptr == '+')
    sign = (*nptr++ == '+') ? 1 : -1;

  /* add digits to number (retval),
   * but not more than one less than the number of digits of INT_MAX */
  while (isdigit (*nptr) && int_bound)
    {
      retval = retval * 10 + (*nptr - '0');
      int_bound /= 10;
      nptr++;
    }

  if (!isdigit (*nptr))
    return sign * retval;
  else
    {
      if (retval > INT_MAX / 10)
	goto overflow;
      else if (retval < INT_MAX / 10)
	goto normal;
      else if (*nptr - '0' > abs (((sign == 1) ? INT_MAX : INT_MIN) % 10))
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
  return ((sign == 1) ? INT_MAX : INT_MIN);
}

/* $Id$ */
