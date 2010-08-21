/*  bcopy - copy byte sequence

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

/* This  function is deprecated (marked as LEGACY in POSIX.1-2001):
 * use memcpy() or memmove() in new programs.
 * Note that the first two arguments are interchanged for memcpy() and memmove(). */

void
bcopy (const void *src, void *dest, size_t n)
{
  /* The bcopy() function copies n bytes from src to dest.
   * The result should be correct, even when both areas overlap.
   * So we need to use memmove() to handle overlaps */
  memmove (dest, src, n);
}

/* $Id$ */
