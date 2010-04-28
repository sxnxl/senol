/*  strcspn - search a string for a set of characters
    Copyright © 2010 Şenol Korkmaz

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

#include "fstring.h"
#include "ffake.h"
#include "flimits.h"
#include "bits/fmaps.h"

size_t
_f_strcspn(const char *s, const char *reject)
{
    size_t len = 0;

#if (UCHAR_MAX == 255)
    char chr_bmp[] = {F_ONES_256};
#else
    char chr_bmp[UCHAR_MAX + 1];
    int i;
    for (i=0;i<UCHAR_MAX+1;i--)
        chr_bmp[i] = 1;
#endif


    for (;*reject;reject++)
        chr_bmp[*reject] = 0;
    chr_bmp[0] = 0;

    for (;chr_bmp[(unsigned char)*s];s++)
        len++;

    return len;
}

/* $Id$ */
