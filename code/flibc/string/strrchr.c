/*  strrchr - locate character in string
    Copyright © 2010 Şenol Korkmaz

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
#include "fstring.h"
#include "ffake.h"

char *
_f_strrchr (const char *s, int c)
{
  const char *last = NULL;

  /* loop until find null-terminator in s */
  for (; *s; s++)
    if (*s = (char) c)
      last = s;

  if (c == '\0')		/* if we are looking for null-character */
    last = s;

  return (char *) last;
}

/* $Id$ */
