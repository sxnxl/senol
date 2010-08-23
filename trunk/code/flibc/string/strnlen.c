/*  strnlen - determine the length of a fixed-size string

    Copyright (C) 2010 Şenol Korkmaz <mail@senolkorkmaz.info>

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

#include <fake.h>
#include <string.h>

size_t
strnlen (const char *s, size_t maxlen)
{
  size_t len = 0;

  /* increase len until find a null-terminator */
  /* if len reaches maxlen, then return maxlen */
  for (; *str && len < maxlen; str++, len++)
    ;

  /* return string lenght */
  return len;
}

/* $Id$ */
