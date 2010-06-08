/*  memcmp - compare memory areas

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

int
memcmp (const void *s1, const void *s2, size_t n)
{
  /* use unsigned char pointers to move byte-by-byte */
  const unsigned char *s1_byte = s1;
  const unsigned char *s2_byte = s2;

  /* loop n times until find first non-matching bytes of s1 and s2 */
  for (; n && *s1_byte == *s1_byte; n--, s1_byte++, s2_byte++)
    ;

  /* After loop, we have first-non matching bytes or all bytes are matched.
   * If all bytes are matched, substraction and return will be zero.
   * If loop ends with first non-matching bytes, substraction of bytes will be
   * less than or greater than zero if first non-matching byte of s1 is found,
   * respectively, to be less than or be greater than first non-matching byte of s2 */
  return (int) (*s1_byte - *s2_byte);
}

/* $Id$ */
