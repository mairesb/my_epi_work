#include <stdlib.h>

void	my_free(void *prt)
{
  if (prt)
    free(prt);
}
