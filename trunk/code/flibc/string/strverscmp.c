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

#define _GET_MODE(s1,s2) ((isdigit (s1) && isdigit (s2))\
    ? ((*(s1) == *(s2) == '0') ? _FRACTIONAL : _INTEGRAL)\
        : (*(s1) == *(s2)) ? _NORMAL : _END)

#define  M_N    0x0		/* normal      */
#define  M_I    0x4		/* integral    */
#define  M_F    0x8		/* fractional  */
#define  M_Z    0xC		/* zeroes      */

int
strverscmp (const char *s1, const char *s2)
{
  enum _modes mode;
  enum _modes mode_next;
  int retval = 0;

  static const uint8_t mode_tbl[] = {
    /*  mode      c    d    0    -  */
    /* ------    ---  ---  ---  --- */
    /*  M_N   */ M_N, M_I, M_Z, M_N,
    /*  M_I   */ M_N, M_I, M_I, M_I,
    /*  M_F   */ M_N, M_F, M_F, M_F,
    /*  M_Z   */ M_N, M_F, M_Z, M_Z
  };

  mode = _GET_MODE (s1, s2);
  mode = _GET_MODE (s1 + 1, s2 + 1);

  do
    {
      switch (mode)
	{
	case _NORMAL:
	  if (*s1 != *s2)
	    mode = _END;
	  else
	    {
	      mode = next_mode;
	    }
	  break;
	case _INTEGRAL:
	  if (mode_next != _INTEGRAL && retval != _END)
	    break;
	case _FRACTIONAL:
	  break;
	}
    }
  while (mode != _END)

  return (int) (*(const unsigned char *) s1 - *(const unsigned char *) s2);
}

/* $Id$ */
