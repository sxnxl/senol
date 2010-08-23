/*  tst-memchr - Tests function memchr

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
*/

/* TODO: Implement random input test feature */

#include <stdio.h>
#include <stdlib.h>

#define DIFF_MEMCHR(S,C,N) (    \
	(memchr(S,C,N)==NULL) ? \
			NULL  : \
	(void *)( ((const char *)memchr(S,C,N)) - (const char *)S ) )

/* prototype : void *memchr(const void *s, int c, size_t n); */
#define FTEST(S,C,N) 						   \
  fprintf(stderr, "memchr( %s:\"%s\", %s:'%c', %s=%d) = %p\n"      \
  			,#S, S, #C, C, #N, N, DIFF_MEMCHR(S,C,N)); \
  fprintf(stdout,"%p\n",DIFF_MEMCHR(S,C,N))

void
ftest ()
{
  /* strings to be tested */
  char *str35 = "This is a 35 character long string.";
  const char *strNull = "\0";
  const char *strSpace = " ";

  /* a null-character */
  const char chrNull = '\0';
  const char chrA = 'A';
  const char chra = 'a';
  const char chrNewLine = '\n';

  /* call the test macro */

  FTEST (str35, chrA, 35);
  FTEST (str35, chra, 8);
  FTEST (str35, chra, 9);
  FTEST (str35, chra, 10);
  FTEST (str35, chra, 35);

  FTEST (str35, chrNewLine, 35);
  FTEST (str35, chrNull, 34);
  FTEST (str35, chrNull, 35);
  FTEST (str35, chrNull, 36);

  FTEST (strNull, chrNull, 0);
  FTEST (strNull, chrNull, 1);
  FTEST (strSpace, ' ', 0);
  FTEST (strSpace, ' ', 1);
  FTEST (strSpace, ' ', 2);
  FTEST (strSpace, chrNull, 2);

  /* reference to a null-character */
  FTEST (&chrNull, chrA, 0);
  FTEST (&chrNull, chrA, 1);
  FTEST (&chrNull, chrA, 100);
  FTEST (&chrNull, chrNull, 0);
  FTEST (&chrNull, chrNull, 1);
  FTEST (&chrNull, chrNull, 100);

  FTEST ("Hello, test!", 'l', 2);
  FTEST ("Hello, test!", 'l', 3);
  FTEST ("Hello, test!", 'l', 4);

  FTEST ("This string contains \n new line", '\n', 30);
  FTEST ("This string contains a smile :)", ')', 31);

  /* uncomment the line below to produce a "Run Failed!" error with test.py */
  /* FTEST (NULL,'A',100); */

  /* uncomment the line below to produce a "Build Failed!" error with test.py */
  /* FTEST (BUILD_ERROR_PLEASE,'X',100); */

  return;
}

int
main (int argc, char **argv)
{
  /* inform which file is being tested */
  fprintf (stderr, "TESTING: %s\n", __FILE__);

  /* call the test */
  ftest ();

  /* if we reached here then return success */
  exit (EXIT_SUCCESS);
}

/* $Id$ */
