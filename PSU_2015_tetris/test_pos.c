/*
** inv_tab.c for C:\Users\bapti\Documents\Dropbox\rendu in C:\Users\bapti\Documents\Dropbox\rendu\PSU_2015_tetris\Baptiste
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Thu Mar 03 17:00:40 2016 baptiste mairesse
** Last update Thu Mar 10 14:57:14 2016 baptiste mairesse
*/

#include 	"tetris.h"
#include 	<stdlib.h>
#include	<ncurses.h>

int		test_pos(t_all *all, int height, int width, char **tab)
{
  int 		check;
  int 		i;
  int 		j;

  i = -1;
  check = 1;
  while (++i < height)
    {
      j = -1;
      while (++j < width)
	{
	  if (height + all->pos_cur_tet.y <= all->param.rows &&
	      width + all->pos_cur_tet.x <= all->param.cols)
	    {
	      if (tab[i][j] != '0' &&
		  all->param.map_tmp[i + all->pos_cur_tet.y][j + all->pos_cur_tet.x] != '0')
		check = 0;
	    }
	  else
	    check = 0;
	}
    }
  super_free(tab);
  return (check);
}

int		test_pos_turn_inv(t_all *all)
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
  return(test_pos(all, all->pos_cur_tet.width, all->pos_cur_tet.height,
		  tab));
}

int		test_pos_clean_inv(t_all *all)
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
  return(test_pos(all, all->pos_cur_tet.height, all->pos_cur_tet.width,
		  tab));
}

int 		test_pos_clean(t_all *all)
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
  return(test_pos(all, all->pos_cur_tet.height, all->pos_cur_tet.width,
		  tab));
}

int 		test_pos_turn(t_all *all)
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
  return(test_pos(all, all->pos_cur_tet.width, all->pos_cur_tet.height,
		  tab));
}
