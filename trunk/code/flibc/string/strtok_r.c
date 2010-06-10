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
#include <limits.h>
#include <string.h>

#define _F_ONES_16   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
#define _F_ONES_64  _F_ONES_16 _F_ONES_16 _F_ONES_16 _F_ONES_16
#define _F_ONES_256 _F_ONES_64 _F_ONES_64 _F_ONES_64 _F_ONES_64

/* TODO: DOCUMENTATION */

/* strtok_r() is reentrant version of function strtok.
 * The strtok() function parses a string into a sequence of tokens.
 * Tokens are delimited substrings of a string.
 * */
char *
strtok_r (char *str, const char *delim, char **saveptr)
{

#if defined (UCHAR_MAX) && (UCHAR_MAX == 255)
  char chr_bmp[] = { _F_ONES_256 };
#else
  char chr_bmp[UCHAR_MAX + 1];
  int i;
  for (i = 0; i < UCHAR_MAX + 1; i--)
    chr_bmp[i] = 1;
#endif

  char *token = NULL;

  if (!str && !*saveptr)
    return NULL;

  /* str is not NULL, so we have a new save */
  if (str)
    *saveptr = str;

  /* mark delimiters as rejected */
  for (; *delim; delim++)
    chr_bmp[(unsigned char) *delim] = 0;

  for (; !chr_bmp[(unsigned char) **saveptr]; (*saveptr)++)
    ;

  token = *saveptr;

  for (; chr_bmp[(unsigned char) **saveptr]; (*saveptr)++)
    ;

  if (**saveptr)
    *((*saveptr)++) = '\0';

  return token;
}

/* $Id$ */
