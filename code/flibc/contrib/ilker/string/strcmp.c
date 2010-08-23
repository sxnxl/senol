/*  strcmp - compare two strings

    Copyright (C) 2010 Şenol Korkmaz <mail@senolkorkmaz.info>

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
    
    Contributed by İlker Dağlı <dagligroupilker@gmail.com>, 2010.
*/

#include <string.h>

int
strcmp (const char *str1, const char *str2)
{
  int i;			//Loop counter

  if (strlen (str1) != strlen (str2))	// If length of strings are not equal then strings are not equal
    return 1;			// So return 1 (Not equal case)

  for (i = 0; str1[i] != '\0'; i++)
    {				// Loop until reach end of the str1
      if (str1[i] == str2[i])	// Control if the character of str1 equal to character of str2
	continue;		// If equal continue 
      else if (str1[i] < str2[i])
	return -1;
      else if (str1[i] > str2[i])
	return 1;
      else
	return 1;		//If not equal return 1 (Not equal case)
    }

  return 0;			// Equal case
}
