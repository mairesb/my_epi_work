/*
** fctn.c for C:\Users\bapti\Documents\Dropbox\rendu in C:\Users\bapti\Documents\Dropbox\rendu\PSU_2015_tetris\Baptiste
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Tue Mar 01 16:32:45 2016 baptiste mairesse
** Last update Tue Mar 01 16:44:16 2016 baptiste mairesse
*/

#include 	"tetris.h"
#include 	<stdlib.h>

void		super_free(char **tab)
{
  int		i;

  i = 0;
  if (tab && tab[0])
    {
      while (tab[i])
	i++;
      while (tab[i])
	free(tab[i--]);
      free(tab);
    }
}
