/*
** super_free.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Mon Mar 14 14:38:51 2016 baptiste mairesse
** Last update Tue Mar 15 13:22:06 2016 baptiste mairesse
*/

#include 	"mysh.h"
#include 	<stdlib.h>

void		free_command(t_mysh *mysh)
{
  int 		i;

  i = 0;
  while (mysh->tab_com[i])
    i++;
  while (--i >= 0)
    free(mysh->tab_com[i]);
  free(mysh->tab_com);
  free(mysh->command);
}

void 		free_struct(t_mysh *mysh)
{
  int 		i;

  i = 0;
  while (mysh->env[i])
    i++;
  while (--i >= 0)
    free(mysh->env[i]);
  free(mysh->env);
  i = 0;
  while (mysh->path[i])
    i++;
  while (--i >= 0)
    free(mysh->path[i]);
  free(mysh->path);
  free(mysh);
}
