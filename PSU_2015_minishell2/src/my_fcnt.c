/*
** my_fcnt.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by	Baptiste Mairesse
** Login	maires_b
**
** Started on	Sun Apr 03 12:13:15 2016 Baptiste Mairesse
** Last update	Thu Apr 07 09:47:13 2016 Baptiste Mairesse
*/

#include 	"mysh.h"
#include 	<stdlib.h>
#include 	<unistd.h>

void		my_write(int fd, const void *buf, int len)
{
  int		ret;

  ret = write(fd, buf, len);
  if (ret == -1)
    {
      my_putstr("Error write\n");
      exit(84);
    }
}

void		my_close(int fd)
{
  int		ret;

  ret = close(fd);
  if (ret == -1)
    {
      my_putstr("Error close\n");
      exit(84);
    }
}
