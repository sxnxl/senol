/*  tst-strlen - Tests strlen function

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

/* TODO: Implement random input test feature */

#include <stdio.h>
#include <stdlib.h>

#ifdef TEST_USING_FSTRING	/* want to use flibc ? */
# include "fstring.h"		/* use flibc */
# else
# include <string.h>		/* otherwise use stdlibc */
#endif

/* prototype : size_t strlen(const char *s); */
#define FTEST(S) \
  fprintf(stderr, "strlen( %s:\"%s\" ) = %d\n"\
  			,#S, S, (int)strlen(S));\
  fprintf(stdout,"%d\n",(int)strlen(S));\

void
ftest ()
{
  /* strings to be tested */
  char *str35 = "This is a 35 character long string.";
  const char *str1 = "1";
  const char *str0 = "";
  const char *strNull = "\0";
  const char *strSpace = " ";

  /* a null-character */
  const char chrNull = '\0';

  /* call the test macro */
  FTEST (str35);
  FTEST (str1);
  FTEST (str0);
  FTEST (strNull);
  FTEST (strSpace);

  /* reference to a null-character */
  FTEST (&chrNull);

  FTEST ("Hello, test!");
  FTEST ("This string contains \n new line");
  FTEST ("This string contains a smile :)");

  /* uncomment the line below to produce a "Run Failed!" error with test.py */
  /* FTEST (NULL); */
  /* uncomment the line below to produce a "Build Failed!" error with test.py */
  /* FTEST (SOMETHING_STUPID_AND_NOT_DEFINED); */

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
