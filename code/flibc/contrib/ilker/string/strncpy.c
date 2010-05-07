char *
strncpy (char *toHere, const char *fromHere, size_t n)
{
  int i = 0;

  while (i < n)
    {
      toHere[i] = fromHere[i];
      i++;
    }

  toHere[n] = '\0';

  return toHere;
}
