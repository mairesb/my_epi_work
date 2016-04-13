/*
** aff.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 16:47:18 2016 baptiste mairesse
** Last update Thu Feb 25 17:03:07 2016 baptiste mairesse
*/

#include "tetris.h"

void 		debug_mod(t_all *all)
{
  my_putstr("*** DEBUG MODE ***\n");
  my_printf("Key Left : %s\n", all->param.left);
  my_printf("Key Right : %s\n", all->param.right);
  my_printf("Key Turn : %s\n", all->param.turn);
  my_printf("Key Drop : %s\n", all->param.drop);
  my_printf("Key Quit : %s\n", all->param.quit);
  my_printf("Key Pause : %s\n", all->param.pause);

}
