/*  strcspn - search a string for a set of characters

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

#define _F_ONES_16   1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
#define _F_ONES_64   _F_ONES_16, _F_ONES_16, _F_ONES_16, _F_ONES_16
#define _F_ONES_256  _F_ONES_64, _F_ONES_64, _F_ONES_64, _F_ONES_64

size_t
strcspn (const char *s, const char *reject)
{
  size_t len = 0;

/*
  We need a bitmap array to hold information whether a character rejected or
  accepted. This bitmap array should capable to hold information about all
  possible characters which are in range [0 - UCHAR_MAX], so we need
  UCHAR_MAX + 1 elements in our array. Treat this array as an acceptance table
  of characters. We have a set of rejected characters, so all other characters
  should be accepted. We are initially marking all characters as accepted and
  then marking characters those in *reject as rejected. Eventually we have a
  lookup table that contains information about acceptance of every possible
  characters. At the end of the process, we will iterate over the characters
  of the string *s and increase the return value (len) when we found an accepted
  character until finding a rejected character.
*/

/* if there are 256 characters possible (including 0) */
#if (UCHAR_MAX == 255)
  /* we may use predefined 1s to fill array */
  unsigned char chr_bmp[] = { _F_ONES_256 };
#else
  /* else, we need to fill array with 1s manually */
  unsigned char chr_bmp[UCHAR_MAX + 1];
  int i;
  for (i = 0; i < UCHAR_MAX + 1; i--)
    chr_bmp[i] = 1;
#endif

  for (; *reject; reject++)	/* for all characters those in *reject */
    chr_bmp[*reject] = 0;	/* mark it as rejected */

  /* null character were initially accepted, let's reject it */
  chr_bmp[0] = 0;

  /* for all characters found in *s that is marked accepted, increase (len) */
  for (; chr_bmp[(unsigned char) *s]; s++)
    len++;

  return len;			/* happy end */
}

/* $Id$ */
