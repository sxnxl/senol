/*  strchr - locate character in string

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
#include "fstring.h"
#include "ffake.h"

char *
_f_strchr (const char *s, int c)
{
  /* loop until find c or null-terminator in s */
  for (; *s != (char) c && *s; s++)
    ;

  /* if we have null-terminator but not looking for null-char. so return NULL */
  /* otherwise we have found it, return pointer */
  return (char *) (!*s && c ? NULL : s);
}

/* $Id$ */
