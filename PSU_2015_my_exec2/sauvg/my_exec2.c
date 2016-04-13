/*
** my_exec2.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_my_exec2 in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_my_exec2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Thu Mar 17 09:12:03 2016 baptiste mairesse
** Last update Thu Mar 17 11:38:58 2016 baptiste mairesse
*/

#include 	"my_exec2.h"

#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<sys/types.h>

void 		pipe_1(int fd[2], char **com2, char **com3, char **env)
{
  pid_t   	childpid_2;
  int     	fd_2[2];

  close(fd[1]);
  pipe(fd_2);
  if((childpid_2 = fork()) == -1)
    {
      perror("fork");
      exit(1);
    }
  if(childpid_2 == 0)
    {
      close(fd_2[0]);
      dup2(fd[0], 0);
      dup2(fd_2[1], 1);
      execve(com2[0], com2, env);
    }
  else
    {
      close(fd_2[1]);
      dup2(fd_2[0], 0);
      execve(com3[0], com3, env);
    }
}

int		 main(int ac, char **av, char **env)
{
  int     	fd[2];
  char		**com1;
  char		**com2;
  char		**com3;
  pid_t   	childpid;

  pipe(fd);
  if (ac != 4)
    exit (84);
  com1 = get_command(av[1]);
  com2 = get_command(av[2]);
  com3 = get_command(av[3]);
  if((childpid = fork()) == -1)
    exit(1);
  if(childpid == 0)
    {
      close(fd[0]);
      dup2(fd[1], 1);
      execve(com1[0], com1, env);
      exit(0);
    }
    pipe_1(fd, com2, com3, env);
  return(0);
}
