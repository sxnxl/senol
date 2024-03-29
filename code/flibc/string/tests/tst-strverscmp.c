 /* Test of strverscmp() function.
    Copyright (C) 2008 Free Software Foundation, Inc.

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3, or (at your option)
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software Foundation,
    Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.  */

 /* Written by Eric Blake <ebb9@byu.net>, 2008.  */


#include <string.h>

#include <stdio.h>
#include <stdlib.h>

#define ASSERT(expr) \
   do                                                                         \
     {                                                                        \
       if (!(expr))                                                           \
         {                                                                    \
           fprintf (stderr, "%s:%d: assertion failed\n", __FILE__, __LINE__); \
           fflush (stderr);                                                   \
           abort ();                                                          \
         }                                                                    \
     }                                                                        \
   while (0)
#undef strverscmp
#include "strverscmp.c"

int
main (int argc, char **argv)
{
  ASSERT (strverscmp ("", "") == 0);
  ASSERT (strverscmp ("a", "a") == 0);
  ASSERT (strverscmp ("a", "b") < 0);
  ASSERT (strverscmp ("b", "a") > 0);
  ASSERT (strverscmp ("000", "00") < 0);
  ASSERT (strverscmp ("00", "000") > 0);
  ASSERT (strverscmp ("a0", "a") > 0);
  ASSERT (strverscmp ("00", "01") < 0);
  ASSERT (strverscmp ("01", "010") < 0);
  ASSERT (strverscmp ("010", "09") < 0);
  ASSERT (strverscmp ("09", "0") < 0);
  ASSERT (strverscmp ("9", "10") < 0);
  ASSERT (strverscmp ("0a", "0") > 0);
  return 0;
}
