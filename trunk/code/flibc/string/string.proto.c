/* copies n bytes between two memory areas, which must not overlap */
void *memcpy (void *dest, const void *src, size_t n);

/* copies n bytes between two memory areas; unlike with memcpy the areas may overlap */
void *memmove (void *dest, const void *src, size_t n);

/* returns a pointer to the first occurrence of c in the first n bytes of s, or NULL if not found */
void *memchr (const void *s, char c, size_t n);

/* compares the first n characters of two memory areas */
int memcmp (const void *s1, const void *s2, size_t n);

/* overwrites a memory area with a byte pattern */
void *memset (void *, int, size_t);

/* appends the string src to dest */
char *strcat (char *dest, const char *src);

/* appends at most n characters of the string src to dest */
char *strncat (char *, const char *, size_t);

/* locates a character in a string, searching from the beginning */
char *strchr (const char *, int);

/* locates a character in a string, searching from the end */
char *strrchr (const char *, int);

/* compares two strings lexicographically */
int strcmp (const char *, const char *);

/* compares up to the first n bytes of two strings lexicographically */
int strncmp (const char *, const char *, size_t);

/* compares two strings using the current locale's collating order */
int strcoll (const char *, const char *);

/* copies a string from one location to another */
char *strcpy (char *toHere, const char *fromHere);

/* copies up to n bytes of a string from one location to another */
char *strncpy (char *toHere, const char *fromHere, size_t);

/* returns the string representation of an error number e.g. errno (not thread-safe) */
char *strerror (int);

/* finds the length of a C string */
size_t strlen (const char *);

/* determines the length of the maximal initial substring of s consisting entirely of characters in accept */
size_t strspn (const char *s, const char *accept);

/* determines the length of the maximal initial substring of s consisting entirely of characters not in reject */
size_t strcspn (const char *s, const char *reject);

/* finds the first occurrence of any character in accept in s */
char *strpbrk (const char *s, const char *accept);

/* finds the first occurrence of the string "needle" in the longer string "haystack". */
char *strstr (const char *haystack, const char *needle);

/* parses a string into a sequence of tokens; non-thread safe in the spec, non-reentrant */
char *strtok (char *, const char *);

/* transforms src into a collating form, such that the numerical sort order of the transformed string is equivalent to the collating order of src. */
size_t strxfrm (char *dest, const char *src, size_t n);

/* REFERENCE: <http://en.wikipedia.org/wiki/String.h#Functions> */
