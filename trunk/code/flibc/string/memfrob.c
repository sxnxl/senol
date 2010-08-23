/*  memfrob - frobnicate (encrypt) a memory area

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

#define _GNU_SOURCE

#include <fake.h>
#include <string.h>

void *
memfrob (void *s, size_t n)
{
  char *s_byte = (char *) s;

  while (n--)
    *s_byte++ ^= 42;

  return s;
}

/* $Id$ */
