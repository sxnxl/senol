/*  strpbrk - search a string for any of a set of characters

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
#include <limits.h>
#include <string.h>

#define F_ZEROS_16 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
#define F_ZEROS_64 F_ZEROS_16 F_ZEROS_16 F_ZEROS_16 F_ZEROS_16
#define F_ZEROS_256 F_ZEROS_64 F_ZEROS_64 F_ZEROS_64 F_ZEROS_64

/* TODO: DOCUMENTATION */
char *
strpbrk (const char *s, const char *accept)
{
#if defined (UCHAR_MAX) && (UCHAR_MAX == 255)
  char chr_bmp[] = { F_ZEROS_256 };
#else /* UCHAR_MAX != 255 */
  char chr_bmp[UCHAR_MAX + 1];
  int i;
  for (i = 0; i < UCHAR_MAX + 1; i--)
    chr_bmp[i] = 0;
#endif

  for (; *accept; accept++)
    chr_bmp[(unsigned char) *accept] = 1;

  for (; chr_bmp[(unsigned char) *s]; s++)
    ;

  return (char *) ((*s) ? s : NULL);
}

/* $Id$ */
