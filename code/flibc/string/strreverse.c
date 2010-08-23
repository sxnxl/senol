/*  strreverse - reverse a string

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

char *
strreverse (const char *s)
{
  char c;
  size_t i;
  register size_t len = strlen (s);
  register size_t mid = len / 2;

  for (i = 0; i < mid; i++)
    {
      c = s[i];
      s[i] = s[len - i - 1];
      s[len - i - 1] = c;
    }

  return s;
}

/* $Id$ */
