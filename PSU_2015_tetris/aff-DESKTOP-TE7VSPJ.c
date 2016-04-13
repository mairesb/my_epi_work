/*
** aff.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 16:47:18 2016 baptiste mairesse
** Last update Sun Mar 20 21:46:10 2016 baptiste mairesse
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
my_printf("Tetriminos : %d\n", all->list_tetri.first->nb + 1);
  comp_tetris(all);
  my_putstr("Press a key to start Tetris\n");
  read(0, NULL, 1);
}

void 		debug_mod(t_all *all)
{
  my_putstr("*** DEBUG MODE ***\n");
  my_printf("Key Left : %s\n", print_key(all->param.left));
  my_printf("Key Right : %s\n", print_key(all->param.right));
  my_printf("Key Turn : %s\n", print_key(all->param.turn));
  my_printf("Key Drop : %s\n", print_key(all->param.drop));
  my_printf("Key Quit : %s\n", all->param.quit);
  my_printf("Key Pause : %s\n", all->param.pause);
  my_printf("Next : %s\n", ((all->param.next == 0) ? "Yes" : "No"));
  my_printf("Level : %d\n", all->param.level);
  my_printf("Size : %d*%d\n", all->param.rows, all->param.cols);
  aff_tetrimino(all);
}
