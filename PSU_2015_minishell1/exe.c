/*
** exe.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Tue Mar 15 16:09:26 2016 baptiste mairesse
** Last update Wed Mar 16 09:53:37 2016 baptiste mairesse
*/

#include 	"mysh.h"
#include 	<unistd.h>
#include 	<stdlib.h>
#include 	<stdio.h>

char 		*src_good_path(t_mysh *mysh, char *bin)
{
  int 		i;
  char 		*path;

  i = 0;
  if (access(bin, F_OK) != -1)
    path = my_strdup(bin);
  else
    path = my_strdup(bin);
  if (src_str("./", bin) == 1)
    return (bin);
  free(path);
  while (mysh->path[i])
    {
      path = my_strdup(mysh->path[i]);
      path = my_strcat(path, bin);
      if (access(path, F_OK) != -1)
	return (path);
      free(path);
      i++;
    }
  return (NULL);
}

int 		my_exe(t_mysh *mysh)
{
  char 		*path;
  int 		ret;

  ret = -1;
  path = src_good_path(mysh, mysh->tab_com[0]);
  if (path)
    ret = execve(path, mysh->tab_com, (mysh->env));
  if (path)
    free(path);
  if (ret == -1)
    return (-1);
  else
    return (0);
}
