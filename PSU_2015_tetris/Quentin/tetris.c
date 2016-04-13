/*
** tetris.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 14:40:01 2016 baptiste mairesse
** Last update Fri Feb 26 17:11:02 2016 Quentin
*/

#include 	"tetris.h"
#include  <ncurses.h>

void 		init_struct(t_all *all)
{
  all->param.left = my_strdup("q");
  all->param.right = my_strdup("d");
  all->param.turn = my_strdup("z");
  all->param.drop = my_strdup("s");
  all->param.quit = my_strdup("t");
  all->param.pause = my_strdup("p");
  all->param.rows = 20;
  all->param.cols = 10;
  all->param.next = '0';
  all->param.debug = '0';
  all->param.level = 1;
  all->param.help = '0';
}

int 		main(int argc, char const *argv[])
{
  t_all 	all;

  aff_tetris();
  init_struct(&all);
  parse_arg(&all, argc, argv);
  if (all.param.debug == 1)
    debug_mod(&all);
  return (0);
}
