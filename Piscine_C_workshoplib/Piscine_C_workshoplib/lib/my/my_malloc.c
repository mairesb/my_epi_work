#include <stdlib.h>


void	*my_malloc(size_t size)
{
  void	*ptr;

  if (ptr = malloc(size))
    return (ptr);
  else
    exit(84);
}
