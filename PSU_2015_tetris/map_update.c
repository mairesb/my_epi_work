/*
** map_update.c for C:\Users\bapti\Documents\Dropbox\rendu in C:\Users\bapti\Documents\Dropbox\rendu\PSU_2015_tetris\Baptiste
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Tue Mar 01 15:25:42 2016 baptiste mairesse
** Last update Thu Mar 17 14:42:15 2016 baptiste mairesse
*/

#include 	"tetris.h"
#include	<ncurses.h>
#include	<stdlib.h>
#include 	<unistd.h>
#include 	<sys/types.h>
#include 	<sys/stat.h>
#include 	<fcntl.h>

void 		update_tab(t_all *all)
{
  unsigned int 	i;
  unsigned int 	j;

  i = -1;
  line_or_not(all);
  while (all->param.map[++i])
    {
      j = -1;
      while(all->param.map[i][++j])
	 all->param.map_tmp[i][j] = all->param.map[i][j];
    }
  if (all->pos_cur_tet.y > 1)
    game_play(all);
  else
    {
      if (all->game.score > all->game.h_score)
	{
	  my_put_in_file(all->game.score, "hs.txt");
	}
      end_window();
      exit(0);
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
  if (all->pos_cur_tet.turn == -2)
    tab_turn(all);
  else if (all->pos_cur_tet.turn == 1)
    tab_turn_inv(all);
  else if (all->pos_cur_tet.turn == -1)
    tab_clean_inv(all);
  else if (all->pos_cur_tet.turn == 2)
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
  all->pos_cur_tet.turn = 2;
  make_xy_tab(all);
}

void		print_next(char **tab, WINDOW *next, unsigned int color)
{
  int 		i;
  int 		j;

  i = -1;
  wclear(next);
  wborder(next, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wattron(next, COLOR_PAIR(color));
  while (tab[++i])
    {
      j = -1;
      while (tab[i][++j])
	{
	  if (tab[i][j] != ' ')
	    mvwprintw(next, i + 1, j + 1, "%c", tab[i][j]);
	}
    }
  wattroff(next, COLOR_PAIR(color));
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
  print_next(list->tetri, all->game.next, list->color);
  if (all->param.next == 0)
    wrefresh(all->game.next);
}
