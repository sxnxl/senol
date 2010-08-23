/*  strdup - duplicate a string

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
#include <malloc.h>
#include <string.h>

char *
strdup (const char *s)
{
  char *s_new = NULL;

  if (s)
    s_new = malloc (strlen (s) + 1);

  if (!s_new)
    return NULL;

  return (strcpy (s_new, s));
}

/* $Id$ */
