/*
** aff_tetris.c for C:\Users\Quentin\Documents\VM\epi\PSU_2015_tetris in C:\Users\Quentin\Documents\VM\epi\PSU_2015_tetris
**
** Made by qentin le bars
** Login   <le-bar_b@epitech.net>
**
** Started on  Fri Feb 26 16:38:37 2016
** Last update Sat Feb 27 01:14:23 2016 Quentin
*/

#include      <ncurses.h>
#include      <stdlib.h>
#include      <stdio.h>

int     scoreboard()
{
  int     hight_score;
  int     score;
  int     lines;
  int     lvl;
  int     timer;

  hight_score = 0;
  score = 0;
  lines = 0;
  lvl = 0;
  timer = 0;
  WINDOW *score_board;
  score_board = subwin(stdscr, LINES - 47, COLS - 170, 7, 0);
  init_pair(4, COLOR_GREEN, COLOR_BLACK);
  wattron(score_board, COLOR_PAIR(4));
  wborder(score_board, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wattroff(score_board, COLOR_PAIR(4));
  init_pair(2, COLOR_YELLOW, COLOR_BLACK);
  wattroff(score_board, COLOR_PAIR(2));
  mvwprintw(score_board, 1, 2, " -Score Board-");
  wattron(score_board, COLOR_PAIR(2));
  mvwprintw(score_board, 3, 1, "High Score:  %d", hight_score);
  mvwprintw(score_board, 4, 1, "Score:       %d", score);
  mvwprintw(score_board, 6, 1, "Lines:       %d", lines);
  mvwprintw(score_board, 7, 1, "Level :      %d", lvl);
  mvwprintw(score_board, 9, 1, "Timer:       %d", timer);
  wrefresh(score_board);
  free(score_board);
  return (0);
}

int     aff_next()
{
  WINDOW *next;
  next = subwin(stdscr, LINES - 50, COLS - 170, 20, 0);
  init_pair(6, COLOR_GREEN, COLOR_BLACK);
  wattron(next, COLOR_PAIR(6));
  wborder(next, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wattroff(next, COLOR_PAIR(6));
  mvwprintw(next, 1, 2, "-Piece Suivante-");
  wrefresh(next);

  return (0);
}

int     aff_boardgame()
{
  int     l_l_bg;
  int     l_c_bg;

  l_l_bg = 20;
  l_c_bg = 10;
  WINDOW *board_game;
  board_game = subwin(stdscr, LINES - (59 - l_l_bg), COLS - (190 - l_c_bg), 7, 23);
  init_pair(5, COLOR_GREEN, COLOR_BLACK);
  wattron(board_game, COLOR_PAIR(5));
  wborder(board_game, '|', '|', '-', '-', '/', '\\', '\\', '/');
  wattroff(board_game, COLOR_PAIR(5));
  wrefresh(board_game);
  return (0);
}

int     aff_tetris()
{
  WINDOW *tetris_aff;
  initscr();
  start_color();
  tetris_aff = subwin(stdscr, LINES - 52, COLS - 167, 0, 7);
  init_pair(3, COLOR_GREEN, COLOR_BLACK);
  wattron(tetris_aff, COLOR_PAIR(3));
  wborder(tetris_aff, '|', '|', '~', '~', '/', '\\', '\\', '/');
  wattroff(tetris_aff, COLOR_PAIR(3));
  init_pair(1, COLOR_RED, COLOR_BLACK);
  wattron(tetris_aff, COLOR_PAIR(1));
  mvwprintw(tetris_aff, 1, 1, "*** *** *** *** * ***");
  mvwprintw(tetris_aff, 2, 1, " *  *    *  * *   *  ");
  mvwprintw(tetris_aff, 3, 1, " *  **   *  **  * ***");
  mvwprintw(tetris_aff, 4, 1, " *  *    *  * * *   *");
  mvwprintw(tetris_aff, 5, 1, " *  ***  *  * * * ***");
  wattroff(tetris_aff, COLOR_PAIR(1));
  wrefresh(tetris_aff);
  scoreboard();
  aff_next();
  aff_boardgame();
  getch();
  endwin();
  /*free(tetris_aff);*/
  return 0;
  }
