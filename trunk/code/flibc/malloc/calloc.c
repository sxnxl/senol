#ifdef L_calloc
void *
calloc (size_t nmemb, size_t lsize)
{
  void *result;
  size_t size = lsize * nmemb;

  /* guard vs integer overflow, but allow nmemb
   * to fall through and call malloc(0) */
  if (nmemb && lsize != (size / nmemb))
    {
      __set_errno (ENOMEM);
      return NULL;
    }
  result = malloc (size);
#if 0
  /* Standard unix mmap using /dev/zero clears memory so calloc
   * doesn't need to actually zero anything....
   */
  if (result != NULL)
    {
      memset (result, 0, size);
    }
#endif
  return result;
}
#endif
