/*
** aff.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 16:47:18 2016 baptiste mairesse
** Last update Mon Feb 29 17:52:15 2016 baptiste mairesse
*/

#include 	"tetris.h"
#include 	<stdlib.h>
#include	<unistd.h>

void		aff_tetrimino_info(t_tetri *elem)
{
  int 		i;

  i = 0;
  my_putstr("Tetriminos : ");
  my_printf("Name %s : ", elem->name);
  if (elem->error == '1')
    my_putstr("Error\n");
  else
    {
      my_printf("Size %d*%d : Color %d :\n", elem->width, elem->height,
		elem->color);
      while (elem->tetri[i])
	{
	  my_putstr(elem->tetri[i]);
	  my_putchar('\n');
	  i++;
	}
    }
}

void		aff_tetrimino(t_all *all)
{
  t_tetri 	*list;

  if (all->list_tetri.first == NULL && all->list_tetri.last == NULL)
    exit(0);
  list = all->list_tetri.last;
  while (list != NULL)
    {
      aff_tetrimino_info(list);
      list = list->prev;
    }
  my_putstr("Press a key to start Tetris\n");
  read(0, NULL, 1);
}

void 		debug_mod(t_all *all)
{
  my_putstr("*** DEBUG MODE ***\n");
  my_printf("Key Left : %s\n", all->param.left);
  my_printf("Key Right : %s\n", all->param.right);
  my_printf("Key Turn : %s\n", all->param.turn);
  my_printf("Key Drop : %s\n", all->param.drop);
  my_printf("Key Quit : %s\n", all->param.quit);
  my_printf("Key Pause : %s\n", all->param.pause);
  my_printf("Next : %s\n", ((all->param.next == '1') ? "Yes" : "No"));
  my_printf("Level : %d\n", all->param.level);
  my_printf("Size : %d*%d\n", all->param.cols, all->param.rows);
  aff_tetrimino(all);
}
