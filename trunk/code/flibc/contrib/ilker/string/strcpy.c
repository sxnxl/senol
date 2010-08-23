/*  strcpy - copy a string

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

char *
strcpy (char *toHere, const char *fromHere)
{
  int i = 0;

  while (fromHere[i] != '\0')
    {
      toHere[i] = fromHere[i];
      i++;
    }

  toHere[i] = '\0';

  return toHere;
}
