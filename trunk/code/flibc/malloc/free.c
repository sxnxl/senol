#ifdef L_free
extern int weak_function __libc_free_aligned (void *ptr);
void
free (void *ptr)
{
  if (unlikely (ptr == NULL))
    return;
  if (unlikely (__libc_free_aligned != NULL))
    {
      if (__libc_free_aligned (ptr))
	return;
    }
  ptr -= sizeof (size_t);
  munmap (ptr, *(size_t *) ptr + sizeof (size_t));
}
#endif
