/*  strncmp - compare two strings
    Based on P.J. Plauger's implementation. (The Standard C Library, 1992)

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

int
strncmp (const char *s1, const char *s2, size_t n)
{
  /* loop until find first non-matching characters of s1 and s2 */
  /* or until n characters compared */
  for (; *s1 == *s2 && *s1 && n; s1++, s2++, n--)
    ;

  /* After loop, we have first-non matching characters or all characters are matched.
   * If all characters are matched, substraction and return will be zero.
   * If loop ends with first non-matching characters, substraction of bytes will be
   * less than or greater than zero if first non-matching character of s1 is found,
   * respectively, to be less than or be greater than first non-matching character of s2 */
  return (int) (*(const unsigned char *) s1 - *(const unsigned char *) s2);
}

/* $Id$ */
