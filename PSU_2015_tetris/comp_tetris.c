/*
** comp_tetris.c for C:\Users\bapti\Documents\Dropbox\rendu\PSU_2015_tetris\Baptiste in C:\Users\bapti\Documents\Dropbox\rendu\PSU_2015_tetris\Baptiste
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Tue Mar 08 22:42:20 2016 baptiste mairesse
** Last update Wed Mar 09 11:02:03 2016 baptiste mairesse
*/

#include 	"tetris.h"
#include 	<stdlib.h>

int 		str_comp(char **tab, int i)
{
  char 		*tmp;
  int 		j;

  if (tab[i] && tab[i + 1])
    {
      j = -1;
      while (tab[i][++j] && tab[i + 1][j])
	{
	  if (tab[i][j] < tab[i + 1][j])
	    return (++i);
	  else if (tab[i][j] > tab[i + 1][j])
	    {
	      tmp = my_strdup(tab[i]);
	      tab[i] = my_strcopy(tab[i], tab[i + 1]);
	      tab[i + 1] = my_strcopy(tab[i + 1], tmp);
	      free(tmp);
	      return (0);
	    }
	}
      return (0);
    }
  else
    return (++i);
}

void		tab_sort(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    {
      i = str_comp(tab, i);
    }
}

void		aff_sort_tetri(t_all *all, char **tab)
{
  t_tetri 	*list;
  int 		i;

  i = 0;
  if (all->list_tetri.first == NULL && all->list_tetri.last == NULL)
    exit(0);
  list = all->list_tetri.last;
  while (tab[i])
    {
      if (my_strcmp(tab[i], list->name) == 0)
	{
	  aff_tetrimino_info(list);
	  list = all->list_tetri.last;
	  i++;
	}
      if (tab[i] && my_strcmp(tab[i], list->name) != 0)
      list = list->prev;
    }
}

void		comp_tetris(t_all *all)
{
  t_tetri 	*list;
  int 		i;
  char 		**tab;

  i = 0;
  if (all->list_tetri.first == NULL && all->list_tetri.last == NULL)
    exit(0);
  list = all->list_tetri.last;
  tab = malloc(sizeof(char *) * (all->list_tetri.first->nb + 2));
  while (list != NULL)
    {
      tab[i] = my_strdup(list->name);
      list = list->prev;
      i++;
    }
  tab_sort(tab);
  aff_sort_tetri(all, tab);
}
