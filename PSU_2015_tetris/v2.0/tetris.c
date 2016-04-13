/*
** tetris.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 14:40:01 2016 baptiste mairesse
** Last update Thu Mar 03 16:13:10 2016 baptiste mairesse
*/

#include 	"tetris.h"
#include 	<stdlib.h>

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
  all->update = '0';
}

void		init_tab(t_all *all, char ***map)
{
  unsigned int 	i;
  unsigned int 	j;

  i = 0;
  (*map) = malloc(sizeof(char *) * all->param.rows + 1);
  while (i < all->param.rows)
    {
      j = 0;
      (*map)[i] = malloc(sizeof(char) * all->param.cols + 1);
      while (j < all->param.cols)
	{
	  (*map)[i][j] = '0';
	  j++;
	}
      (*map)[i][all->param.cols] = '\0';
      i++;
    }
  (*map)[all->param.rows] = NULL;
}

int 		main(int argc, char const *argv[])
{
  t_all 	all;

  init_struct(&all);
  parse_arg(&all, argc, argv);
  get_tetri(&all);
  init_tab(&all, &all.param.map);
  init_tab(&all, &all.param.map_tmp);
  if (all.param.help == '1')
    {
      my_putstr(HELP);
      my_putstr(HELP2);
      return (0);
    }
  if (all.param.debug == 1)
    debug_mod(&all);
  start_game(&all);
  return (0);
}
