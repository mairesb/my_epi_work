/*
** super_free.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Mon Mar 14 14:38:51 2016 baptiste mairesse
** Last update	Thu Apr 07 09:08:32 2016 Baptiste Mairesse
*/

#include 	"mysh.h"
#include 	<stdlib.h>

void		free_list(t_comctrl *list)
{
  t_com		*elem;
  t_com		*tmp;

  if (list->last)
    elem = list->last;
  else
    return;
  while (elem)
    {
      tmp = elem->prev;
      if (elem->com)
	free(elem->com);
      free(elem);
      elem = tmp;
    }
}

void		free_tab(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    free(tab[i++]);
  free(tab);
}

void		free_command(t_mysh *mysh)
{
  if (mysh->command)
    free(mysh->command);
  if (mysh->command_sel)
    free(mysh->command_sel);
}

void 		free_struct(t_mysh *mysh)
{
  free_tab(mysh->env);
  if (mysh->path)
    free_tab(mysh->path);
  free(mysh);
}
