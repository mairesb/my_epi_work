/*
** game.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris\Baptiste
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Sat Feb 27 16:47:16 2016 baptiste mairesse
** Last update Thu Mar 03 16:33:50 2016 baptiste mairesse
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
  unsigned int	j;

  i = -1;
  mvwprintw(all->game.board, 1, 1, "Hight Score");
  mvwprintw(all->game.board, 2, 1, "Score %d", all->game.score);
  wrefresh(all->game.board);
  wborder(all->game.tetris, '|', '|', '-', '-', '-', '-', '-', '-');
  wrefresh(all->game.tetris);
  while (++i < all->param.rows)
    {
      j = -1;
      while (++j != all->param.cols)
	{
	      wattron(all->game.tetris, COLOR_PAIR(all->param.map[i][j]));
	      mvwprintw(all->game.tetris, i + 1, j + 1, (all->param.map[i][j]
							 == '0') ? " " : "*");
	      wattroff(all->game.tetris, COLOR_PAIR(all->param.map[i][j]));
	}
    }
  wrefresh(all->game.tetris);
}

void 		fall_token(t_all *all)
{
  mvt_drop(all);
  make_xy_tab(all);
  if (all->update == '1')
    {
      all->update = '0';
      update_tab(all);
    }
  print_game_info(all);
}

void 		get_key_ch(t_all *all, int ch)
{
  int		y;
  int		x;

  getmaxyx(stdscr, y, x);
  if (y < 26 || x < 86)
    {
     endwin();
     exit(84);
    }
  if (ch == all->param.left[0])
    mvt_left(all);
  else if (ch == all->param.right[0])
    mvt_right(all);
  else if (ch == all->param.turn[0])
    mvt_turn(all);
  else if (ch == all->param.drop[0])
    mvt_drop(all);
  make_xy_tab(all);
  print_game_info(all);
}

void		init_coloo(void)
{
  init_pair(0, COLOR_BLACK, COLOR_BLACK);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

void 		start_game(t_all *all)
{
  int 		ch;
  int 		frozen;

  frozen = -1;
  init_win();
  refresh();
  init_windowss(all);
  ch = wgetch(stdscr);
  all->time_tmp = time(NULL);
  init_coloo();
  game_play(all);
  while ((int)ch != all->param.quit[0])
    {
      ch = wgetch(stdscr);
      if ((int)ch == all->param.pause[0])
	frozen *= -1;
      get_key_ch(all, ch);
      if (frozen < 0 && all->time_tmp - time(NULL) <= -1)
	{
	  all->time_tmp = time(NULL);
	  fall_token(all);
	}
      line_or_not(all);
    }
  end_window();
}
