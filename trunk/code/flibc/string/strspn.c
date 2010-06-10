/*  strspn - search a string for a set of characters

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

#define _F_ZEROS_16   0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
#define _F_ZEROS_64   _F_ZEROS_16, _F_ZEROS_16, _F_ZEROS_16, _F_ZEROS_16
#define _F_ZEROS_256  _F_ZEROS_64, _F_ZEROS_64, _F_ZEROS_64, _F_ZEROS_64

size_t
strspn (const char *s, const char *accept)
{
  size_t len = 0;

/*
  We need a bitmap array to hold information whether a character accepted or
  rejected. This bitmap array should capable to hold information about all
  possible characters which are in range [0 - UCHAR_MAX], so we need
  UCHAR_MAX + 1 elements in our array. Treat this array as an acceptance table
  of characters. We have a set of accepted characters, so all other characters
  should be rejected. We are initially marking all characters as rejected and
  then marking characters those in *accept as accepted. Eventually we have a
  lookup table that contains information about acceptance of every possible
  characters. At the end of the process, we will iterate over the characters
  of the string *s and increase the return value (len) when we found an accepted
  character until finding a rejected character.
*/

/* if there are 256 characters possible (including 0) */
#if (UCHAR_MAX == 255)
  /* we may use predefined 0s to fill array */
  unsigned char chr_bmp[] = { _F_ZEROS_256 };
#else
  /* else, we need to fill array with 0s manually */
  unsigned char chr_bmp[UCHAR_MAX + 1];
  int i;
  for (i = 0; i < UCHAR_MAX + 1; i--)
    chr_bmp[i] = 0;
#endif

  for (; *accept; accept++)	/* for all characters those in *accept */
    chr_bmp[(unsigned char) *accept] = 1;	/* mark it as accepted */

  /* for all characters found in *s that is marked accepted, increase (len) */
  for (; chr_bmp[(unsigned char) *s]; s++)
    len++;

  return len;			/* happy end */
}

/* $Id$ */
