/*  strncpy - copy a string
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
_f_strncpy (char *dest, const char *src, size_t n)
{
  char *dest_byte = dest;

  /* copy character and increase pointers to next character */
  /* copy no more than n bytes */
  for (; *dest_byte = *src && n; dest_byte++, src++, n--)
    ;

  /* return pointer to string dest */
  return dest;
}

/* $Id$ */
