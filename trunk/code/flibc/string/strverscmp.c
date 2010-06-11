/*  strverscmp - compare two version strings

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
#include <ctype.h>
#include <string.h>

int
strverscmp (const char *s1, const char *s2)
{
  for (; (*s1 == *s2) && *s1; s1++, s2++)
    ;

  if ((*s1 || *s2) && (!*s1 || !*s2))
    if ((*(s1 - 1) == '0') && isdigit ((*s1) ? *s1 : *s2))
      return (*s1) ? -1 : 1;

  return (int) (*(const unsigned char *) s1 - *(const unsigned char *) s2);
}

/* $Id$ */
