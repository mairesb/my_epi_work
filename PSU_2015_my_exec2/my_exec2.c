/*
** my_exec2.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_my_exec2 in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_my_exec2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Thu Mar 17 09:12:03 2016 baptiste mairesse
** Last update	Sat Apr 02 13:22:59 2016 Baptiste Mairesse
*/

#include 	"my_exec2.h"

#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<sys/types.h>

void 		forker(int fd_sauvg, int fd, char **tab, char **env)
{
  pid_t 	pid;

  if((pid = fork()) == -1)
    exit(84);
  if (pid == 0)
    {
      if (fd_sauvg != 0)
	{
	  dup2(fd_sauvg, 0);
	  close(fd_sauvg);
	}
      if (fd != 1)
	{
	  dup2(fd, 1);
	  close(fd);
	}
      execve(tab[0], tab, env);
    }
}

int		 main(int ac, char **av, char **env)
{
  int     	fd[2];
  char		***com;
  int		fd_sauvg;
  int 		i;

  com = malloc(sizeof(char **) * ac);
  com[ac - 1] = NULL;
  i = 0;
  while (i != ac - 1)
    {
      com[i] = get_command(av[i + 1]);
      i++;
    }
  i = -1;
  fd_sauvg = 0;
  while (com[++i + 1])
    {
      pipe(fd);
      forker(fd_sauvg, fd[1], com[i], env);
      close(fd[1]);
      fd_sauvg = fd[0];
    }
  if (fd_sauvg != 0)
    dup2 (fd_sauvg, 0);
  execve(com[i][0], com[i], env);
  return(0);
}
