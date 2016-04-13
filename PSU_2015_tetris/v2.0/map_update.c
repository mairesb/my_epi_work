/*
** map_update.c for C:\Users\bapti\Documents\Dropbox\rendu in C:\Users\bapti\Documents\Dropbox\rendu\PSU_2015_tetris\Baptiste
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Tue Mar 01 15:25:42 2016 baptiste mairesse
** Last update Thu Mar 03 16:26:51 2016 baptiste mairesse
*/

#include 	"tetris.h"
#include	<ncurses.h>
#include	<stdlib.h>

void 		update_tab(t_all *all)
{
  unsigned int 	i;
  unsigned int 	j;

  i = -1;
  while (all->param.map[++i])
    {
      j = -1;
      while(all->param.map[i][++j])
	 all->param.map_tmp[i][j] = all->param.map[i][j];
    }
  if (all->pos_cur_tet.y != 1)
    game_play(all);
  else
    {
      end_window();
      exit(0);
    }
}

void		tab_clean(t_all *all)
{
  unsigned int	i;
  unsigned int 	j;

  i = all->pos_cur_tet.y - 1;
  while (++i != all->pos_cur_tet.y + all->pos_cur_tet.height)
    {
      j = all->pos_cur_tet.x - 1;
      while (++j != all->pos_cur_tet.x + all->pos_cur_tet.width)
	{
	  if (all->pos_cur_tet.tetri[i - all->pos_cur_tet.y]
	      [j - all->pos_cur_tet.x] == '*')
	    all->param.map[i][j] = all->pos_cur_tet.color;
	  if (!all->param.map[i + 1] || ( all->param.map[i + 1][j]
					   && all->param.map[i][j] != '0'
					   && all->param.map[i + 1][j] != '0'))
	    all->update = '1';
	}
    }
}

void 		make_xy_tab(t_all *all)
{
  unsigned int	i;
  unsigned int 	j;

  i = -1;
  while (all->param.map_tmp[++i])
    {
      j = -1;
      while (all->param.map_tmp[i][++j])
	all->param.map[i][j] = all->param.map_tmp[i][j];
    }
  if (all->pos_cur_tet.turn == -1)
    tab_turn(all);
  else
    tab_clean(all);
}

void 		make_top_tab(t_all *all)
{
  unsigned int 	i;
  t_tetri 	*list;

  i = -1;
  if (all->list_tetri.first == NULL && all->list_tetri.last == NULL)
    exit(0);
  list = all->list_tetri.last;
  while (++i <= all->pos_cur_tet.next || list == NULL || list->error == '1')
    {
      list = list->prev;
      if (list == NULL)
	list = all->list_tetri.last;
    }
  i = -1;
  all->pos_cur_tet.x = all->param.cols / 2 - 2;
  all->pos_cur_tet.y = 0;
  all->pos_cur_tet.tetri = malloc(sizeof(char *) * list->height);
  while (++i != list->height)
    all->pos_cur_tet.tetri[i] = my_strdup(list->tetri[i]);
  all->pos_cur_tet.width = list->width;
  all->pos_cur_tet.height = list->height;
  all->pos_cur_tet.color = list->color;
  all->pos_cur_tet.turn = -1;
  make_xy_tab(all);
}

void		game_play(t_all *all)
{
  t_tetri 	*list;
  unsigned int  i;

  i = -1;
  make_top_tab(all);
  all->pos_cur_tet.next = rand() % (10 - 0) + 0;
  if (all->list_tetri.first == NULL && all->list_tetri.last == NULL)
    exit(0);
  list = all->list_tetri.last;
  while (++i <= all->pos_cur_tet.next || list == NULL || list->error == '1')
    {
      list = list->prev;
      if (list == NULL)
	list = all->list_tetri.last;
    }
  i = -1;
  wclear(all->game.next);
  while (list->tetri[++i])
    mvwprintw(all->game.next, i + 1, 1, "%s", list->tetri[i]);
  wborder(all->game.next, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wrefresh(all->game.next);
}
