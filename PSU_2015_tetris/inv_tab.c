/*
** inv_tab.c for C:\Users\bapti\Documents\Dropbox\rendu in C:\Users\bapti\Documents\Dropbox\rendu\PSU_2015_tetris\Baptiste
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Thu Mar 03 17:00:40 2016 baptiste mairesse
** Last update Thu Mar 10 11:25:49 2016 baptiste mairesse
*/

#include 	"tetris.h"
#include 	<stdlib.h>
#include	<ncurses.h>

void		put_in_tab(t_all *all, int height, int width, char **tab)
{
  int		i;
  int		j;

  i = -1;
  while (++i < height)
    {
      j = -1;
      while (++j < width)
	{
	  if (tab[i][j] != '0')
	    all->param.map[i + all->pos_cur_tet.y][j + all->pos_cur_tet.x] =
	  tab[i][j];
	  if (i + 1 + all->pos_cur_tet.y >= all->param.rows ||
	      (all->param.map[i + all->pos_cur_tet.y][j + all->pos_cur_tet.x] !=
	       '0' && all->param.map[i + 1 + all->pos_cur_tet.y]
	       [j + all->pos_cur_tet.x] != '0'))
	    all->update = '1';
	}
    }
}

void		tab_turn_inv(t_all *all)
{
  char 		**tab;
  int 		i;
  int 		j;
  int 		j_tab;

  j = -1;
  j_tab = all->pos_cur_tet.width - 1;
  tab = malloc(sizeof(char *) * (all->pos_cur_tet.width + 1));
  while (++j < (int)all->pos_cur_tet.width)
    {
      i = -1;
      tab[j_tab] = malloc(sizeof(char) * (all->pos_cur_tet.height + 1));
      while (++i < (int)all->pos_cur_tet.height)
	{
	  if (all->pos_cur_tet.tetri[i][j] == '*')
	    tab[j_tab][i] = all->pos_cur_tet.color;
	  else
	    tab[j_tab][i] = '0';
	}
      tab[j_tab][i] = '\0';
      j_tab--;
    }
  tab[j] = NULL;
  put_in_tab(all, all->pos_cur_tet.width, all->pos_cur_tet.height, tab);
  super_free(tab);
}

void		tab_clean_inv(t_all *all)
{
  char 		**tab;
  int 		i;
  int 		j;
  int 		j_tab;
  int 		i_tab;

  j = -1;
  j_tab = all->pos_cur_tet.height - 1;
  tab = malloc(sizeof(char *) * (all->pos_cur_tet.height + 1));
  while (++j < (int)all->pos_cur_tet.height)
    {
      i = -1;
      i_tab = all->pos_cur_tet.width - 1;
      tab[j_tab] = malloc(sizeof(char) * (all->pos_cur_tet.width + 1));
      while (++i < (int)all->pos_cur_tet.width)
	{
	  tab[j_tab][i_tab] = (all->pos_cur_tet.tetri[j][i] == '*') ?
	       all->pos_cur_tet.color: '0';
	  i_tab--;
	}
      tab[j_tab--][all->pos_cur_tet.width] = '\0';
    }
  tab[all->pos_cur_tet.height] = NULL;
  put_in_tab(all, all->pos_cur_tet.height, all->pos_cur_tet.width, tab);
  super_free(tab);
}

void 		tab_clean(t_all *all)
{
  char 		**tab;
  int 		i;
  int 		j;

  i = -1;
  tab = malloc(sizeof(char *) * (all->pos_cur_tet.height + 1));
  while (++i < (int)all->pos_cur_tet.height)
    {
      j = -1;
      tab[i] = malloc(sizeof(char) * (all->pos_cur_tet.width + 1));
      while (++j < (int)all->pos_cur_tet.width)
	{
	  tab[i][j] = (all->pos_cur_tet.tetri[i][j] == '*') ?
	      all->pos_cur_tet.color : '0';
	}
      tab[i][j] = '\0';
    }
  tab[i] = NULL;
  put_in_tab(all, all->pos_cur_tet.height, all->pos_cur_tet.width, tab);
  super_free(tab);
}

void 		tab_turn(t_all *all)
{
  char 		**tab;
  int 		i;
  int 		j;
  int 		i_tab;

  j = -1;
  tab = malloc(sizeof(char *) * (all->pos_cur_tet.width + 1));
  while (++j < (int)all->pos_cur_tet.width)
    {
      i = -1;
      i_tab = all->pos_cur_tet.height - 1;
      tab[j] = malloc(sizeof(char) * (all->pos_cur_tet.height + 1));
      while (++i < (int)all->pos_cur_tet.height)
	{
	  if (all->pos_cur_tet.tetri[i][j] == '*')
	    tab[j][i_tab] = all->pos_cur_tet.color;
	  else
	    tab[j][i_tab] = '0';
	  i_tab--;
	}
      tab[j][i_tab] = '\0';
    }
  tab[j] = NULL;
  put_in_tab(all, all->pos_cur_tet.width, all->pos_cur_tet.height, tab);
  super_free(tab);
}
