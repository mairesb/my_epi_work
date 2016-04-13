/*
** game.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris\Baptiste
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Sat Feb 27 16:47:16 2016 baptiste mairesse
** Last update Tue Mar 01 19:18:49 2016 baptiste mairesse
*/
 #include 	"tetris.h"
#include 	<ncurses.h>
#include 	<stdio.h>
#include 	<stdlib.h>
#include 	<unistd.h>
#include 	<time.h>

void		print_game_info(t_all *all)
{
  unsigned int	i;

  i = 0;
  mvwprintw(all->game.board, 1, 1, "Hight Score");
  mvwprintw(all->game.board, 2, 1, "Score %d", all->game.score);
  wrefresh(all->game.board);
  wborder(all->game.tetris, '|', '|', '-', '-', '-', '-', '-', '-');
  wrefresh(all->game.tetris);
  while (i < all->param.rows)
    {
      mvwprintw(all->game.tetris, i + 1, 1, "%s", all->param.map[i]);
      i++;
    }
  wrefresh(all->game.tetris);
}

void 		fall_token(t_all *all)
{
  if (all->pos_cur_tet.tetri)
    {
      all->pos_cur_tet.y++;
      make_xy_tab(all);
      if (all->update == '1')
	{
	  all->update = '0';
	  update_tab(all);
	}
    }
}

void		get_key(t_all *all, int ch)
{
 if ((int)ch == all->param.left[0])
    game_play(&all);

 /* if ((int)ch == all->param.right[0])

  if ((int)ch == all->param.turn[0])

  if ((int)ch == all->param.drop[0])

  if ((int)ch == all->param.pause[0])*/

}

void 		start_game(t_all *all)
{
  int 		ch;
  unsigned int  frozen;

  frozen = 1;
  init_win();
  refresh();
  init_windowss(all);
  ch = getch();
  all->time_tmp = time(NULL);
  while ((int)ch != all->param.quit[0])
    {
      ch = getch();
      if (ch == 'a')
	game_play(&all);
      if ((int)ch == all->param.quit[0])
	frozen *= -1;
      if (frozen > 0 && all->time_tmp - time(NULL) <= -1)
	{
	  all->time_tmp = time(NULL);
	  fall_token(all);
	}
      else if (frozen > 0)
	get_key(all, ch);
      print_game_info(all);
    }
  end_window();
}
