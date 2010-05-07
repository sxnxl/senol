/*  strncat - concatenate two strings

    Copyright © 2010 Şenol Korkmaz <mail@senolkorkmaz.info>
    Copyright © 2010 Sarı Çizmeli Mehmet Ağa (aka. John Doe) <scma@senolkorkmaz.info>

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
_f_strncat (char *dest, const char *src, size_t n)
{
  char *dest_byte = dest;

  /* move pointer to null-terminator of dest */
  while (*dest_byte != '\0')
    dest_byte++;

  do
    /* append current byte from src to dest */
    /* move pointers to next bytes */
    *dest_byte++ = *src++;
  /* exit from loop when null-terminator appended or n character appended */
  while (*src != '\0' && n--);

  /* append a null-terminator if it is not appended */
  if (*dest_byte != '\0')
    *++dest_byte = '\0';

  /* return pointer to destination string */
  return dest;
}

/* $Id$ */
