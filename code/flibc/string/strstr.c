/*  strstr - locate a substring

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

#include <fake.h>
#include <string.h>

/* TODO: DOCUMENTATION */

char *
strstr (const char *haystack, const char *needle)
{
  const char *haystack_last = haystack;
  const char *haystack_p = haystack;
  const char *needle_p;

  for (; *haystack_last; haystack_last++)
    {
      needle_p = needle;
      for (; *haystack_p == *needle_p && *needle_p; haystack_p++, needle_p++)
	;
      if (!*needle_p)
	return (char *) haystack_last;
    }

  return NULL;
}

/* $Id$ */
