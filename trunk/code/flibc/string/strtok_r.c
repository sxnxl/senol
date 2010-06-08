/*  strtok_r - extract tokens from strings (reentrant version)

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

#include <fake.h>
#include <string.h>

/* TODO: DOCUMENTATION */

/* strtok_r() is reentrant version of function strtok.
 * The strtok() function parses a string into a sequence of tokens.
 * Tokens are delimited substrings of a string. 
 * */
char *
strtok_r (char *str, const char *delim, char **saveptr)
{
  if (str)
    *saveptr = str;

  do
    {
      char *s = *saveptr;
      char *e;
      if (s){
          e = strpbrk (s, delim);
          if (e)
              *e++ = '\0';
          *saveptr = e;
      }
      str = s;
    }
  while (str && !*str);

  return str;
}

/* $Id$ */
