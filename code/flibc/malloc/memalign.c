#ifdef L_memalign

#include <bits/uClibc_mutex.h>
__UCLIBC_MUTEX_INIT (__malloc_lock, PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP);
#define __MALLOC_LOCK		__UCLIBC_MUTEX_LOCK(__malloc_lock)
#define __MALLOC_UNLOCK		__UCLIBC_MUTEX_UNLOCK(__malloc_lock)

/* List of blocks allocated with memalign or valloc */
struct alignlist
{
  struct alignlist *next;
  __ptr_t aligned;		/* The address that memaligned returned.  */
  __ptr_t exact;		/* The address that malloc returned.  */
};
struct alignlist *_aligned_blocks;

/* Return memory to the heap. */
int
__libc_free_aligned (void *ptr)
{
  struct alignlist *l;

  if (ptr == NULL)
    return 0;

  __MALLOC_LOCK;
  for (l = _aligned_blocks; l != NULL; l = l->next)
    {
      if (l->aligned == ptr)
	{
	  /* Mark the block as free */
	  l->aligned = NULL;
	  ptr = l->exact;
	  ptr -= sizeof (size_t);
	  munmap (ptr, *(size_t *) ptr + sizeof (size_t));
	  return 1;
	}
    }
  __MALLOC_UNLOCK;
  return 0;
}

void *
memalign (size_t alignment, size_t size)
{
  void *result;
  unsigned long int adj;

  result = malloc (size + alignment - 1);
  if (result == NULL)
    return NULL;

  adj =
    (unsigned long
     int) ((unsigned long int) ((char *) result - (char *) NULL)) % alignment;
  if (adj != 0)
    {
      struct alignlist *l;
      __MALLOC_LOCK;
      for (l = _aligned_blocks; l != NULL; l = l->next)
	if (l->aligned == NULL)
	  /* This slot is free.  Use it.  */
	  break;
      if (l == NULL)
	{
	  l = (struct alignlist *) malloc (sizeof (struct alignlist));
	  if (l == NULL)
	    {
	      free (result);
	      result = NULL;
	      goto DONE;
	    }
	  l->next = _aligned_blocks;
	  _aligned_blocks = l;
	}
      l->exact = result;
      result = l->aligned = (char *) result + alignment - adj;
    DONE:
      __MALLOC_UNLOCK;
    }

  return result;
}
#endif
