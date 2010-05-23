#ifdef L_realloc
void *
realloc (void *ptr, size_t size)
{
  void *newptr = NULL;

  if (!ptr)
    return malloc (size);
  if (!size)
    {
      free (ptr);
      return malloc (0);
    }

  newptr = malloc (size);
  if (newptr)
    {
      size_t old_size = *((size_t *) (ptr - sizeof (size_t)));
      memcpy (newptr, ptr, (old_size < size ? old_size : size));
      free (ptr);
    }
  return newptr;
}
#endif
