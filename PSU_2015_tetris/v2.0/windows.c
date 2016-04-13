/*
** windows.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris\Baptiste
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Sat Feb 27 16:28:23 2016 baptiste mairesse
** Last update Thu Mar 03 16:15:46 2016 baptiste mairesse
*/

#include 	<ncurses.h>
#include 	<stdlib.h>
#include 	"tetris.h"

void		init_win()
{
  SCREEN  	*win;

  win = newterm(NULL, stderr, stdin);
  noecho();
  curs_set(0);
  cbreak();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  start_color();
}

void		init_windowss(t_all *all)
{
  all->game.score = 0;
  all->game.tetris = newwin(all->param.rows + 2, all->param.cols + 2, 1, 32);
  wborder(all->game.tetris, '|', '|', '-', '-', '-', '-', '-', '-');
  wrefresh(all->game.tetris);
  all->game.panel = newwin(6 , 25, 1, 1);
  wattron(all->game.panel, COLOR_PAIR(1));
  mvwprintw(all->game.panel, 1, 1, "*** *** *** *** * ***");
  mvwprintw(all->game.panel, 2, 1, " *  *    *  * *   *  ");
  mvwprintw(all->game.panel, 3, 1, " *  **   *  **  * ***");
  mvwprintw(all->game.panel, 4, 1, " *  *    *  * * *   *");
  mvwprintw(all->game.panel, 5, 1, " *  ***  *  * * * ***");
  wattroff(all->game.panel, COLOR_PAIR(1));
  wrefresh(all->game.panel);
  all->game.next = newwin(10, 10, 1, 32 + all->param.rows);
  wborder(all->game.next, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wrefresh(all->game.next);
  all->game.board = newwin(11, 20, 15, 1);
  wborder(all->game.board, '|', '|', '-', '-', '-', '-', '-', '-');

}

void		end_window()
{
  clrtoeol();
  refresh();
  endwin();
}
