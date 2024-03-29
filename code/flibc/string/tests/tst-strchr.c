/*  tst-strchr - Tests function strchr

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

#define DIFF_STRCHR(S,C) (	\
	(strchr(S,C)==NULL) ? 	\
		      NULL  : 	\
	(void *)( ((const char *)strchr(S,C)) - S ) )

/* prototype : char *strchr(const char *s, int c); */
#define FTEST(S,C) 					  \
  fprintf(stderr, "strchr( %s:\"%s\", %s:'%c') = %p\n"	  \
  			,#S, S, #C, C, DIFF_STRCHR(S,C)); \
  fprintf(stdout,"%p\n",DIFF_STRCHR(S,C))

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

  FTEST (str35, chrA);
  FTEST (str35, chra);

  FTEST (str35, chrNewLine);
  FTEST (str35, chrNull);

  FTEST (strNull, chrNull);
  FTEST (strSpace, ' ');
  FTEST (strSpace, chrNull);

  /* reference to a null-character */
  FTEST (&chrNull, chrA);
  FTEST (&chrNull, chrNull);

  FTEST ("Hello, test!", 'l');

  FTEST ("This string contains \n new line", '\n');
  FTEST ("This string contains a smile :)", ')');

  /* uncomment the line below to produce a "Run Failed!" error with test.py */
  /* FTEST ((const char *)NULL,'A'); */

  /* uncomment the line below to produce a "Build Failed!" error with test.py */
  /* FTEST (BUILD_ERROR_PLEASE,'X'); */

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
