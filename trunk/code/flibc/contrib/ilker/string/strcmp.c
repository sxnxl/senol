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
