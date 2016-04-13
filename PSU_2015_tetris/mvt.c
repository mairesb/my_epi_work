/*
** mvt.c for C:\Users\bapti\Documents\Dropbox\rendu in C:\Users\bapti\Documents\Dropbox\rendu\PSU_2015_tetris\Baptiste
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Tue Mar 01 19:31:53 2016 baptiste mairesse
** Last update Thu Mar 10 15:21:03 2016 baptiste mairesse
*/

#include 	"tetris.h"
#include 	<stdlib.h>

void		mvt_left(t_all *all)
{
  if (all->pos_cur_tet.x > 0)
    {
      --all->pos_cur_tet.x;
      if (all->pos_cur_tet.turn == -2 && test_pos_turn(all) == 0)
	all->pos_cur_tet.x++;
      else if (all->pos_cur_tet.turn == -1 && test_pos_clean_inv(all) == 0)
	all->pos_cur_tet.x++;
      else if (all->pos_cur_tet.turn == 1 && test_pos_turn_inv(all) == 0)
	all->pos_cur_tet.x++;
      else if (all->pos_cur_tet.turn == 2 && test_pos_clean(all) == 0)
	all->pos_cur_tet.x++;
    }
}

void		mvt_right(t_all *all)
{
  ++all->pos_cur_tet.x;
  if (all->pos_cur_tet.turn == -2 && test_pos_turn(all) == 0)
    --all->pos_cur_tet.x;
  else if (all->pos_cur_tet.turn == -1 && test_pos_clean_inv(all) == 0)
    --all->pos_cur_tet.x;
  else if (all->pos_cur_tet.turn == 1 && test_pos_turn_inv(all) == 0)
    --all->pos_cur_tet.x;
  else if (all->pos_cur_tet.turn == 2 && test_pos_clean(all) == 0)
    --all->pos_cur_tet.x;
}

void		mvt_drop(t_all *all)
{
  ++all->pos_cur_tet.y;
  if (all->pos_cur_tet.turn == -2 && test_pos_turn(all) == 0)
    all->pos_cur_tet.y--;
  else if (all->pos_cur_tet.turn == -1 && test_pos_clean_inv(all) == 0)
    all->pos_cur_tet.y--;
  else if (all->pos_cur_tet.turn == 1 && test_pos_turn_inv(all) == 0)
    all->pos_cur_tet.y--;
  else if (all->pos_cur_tet.turn == 2 && test_pos_clean(all) == 0)
    all->pos_cur_tet.y--;
}

void		mvt_turn(t_all *all)
{
  if (all->pos_cur_tet.turn == -2)
    all->pos_cur_tet.turn = 2;
  else if (all->pos_cur_tet.turn == -1)
    all->pos_cur_tet.turn = -2;
  else if (all->pos_cur_tet.turn == 1)
    all->pos_cur_tet.turn = -1;
  else if (all->pos_cur_tet.turn == 2)
    all->pos_cur_tet.turn = 1;

  if (all->pos_cur_tet.turn == -2 && test_pos_turn(all) == 0)
    all->pos_cur_tet.turn = -1;
  else if (all->pos_cur_tet.turn == -1 && test_pos_clean_inv(all) == 0)
    all->pos_cur_tet.turn = 1;
  else if (all->pos_cur_tet.turn == 1 && test_pos_turn_inv(all) == 0)
    all->pos_cur_tet.turn = 2;
  else if (all->pos_cur_tet.turn == 2 && test_pos_clean(all) == 0)
    all->pos_cur_tet.turn = -2;
}
