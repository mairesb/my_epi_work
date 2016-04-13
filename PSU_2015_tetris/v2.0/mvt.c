/*
** mvt.c for C:\Users\bapti\Documents\Dropbox\rendu in C:\Users\bapti\Documents\Dropbox\rendu\PSU_2015_tetris\Baptiste
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Tue Mar 01 19:31:53 2016 baptiste mairesse
** Last update Thu Mar 03 16:17:37 2016 baptiste mairesse
*/

#include 	"tetris.h"
#include 	<stdlib.h>

void		mvt_left(t_all *all)
{
  if (all->pos_cur_tet.x > 0)
    all->pos_cur_tet.x--;
}

void		mvt_right(t_all *all)
{
  if (all->pos_cur_tet.turn > 0 && test_pos_norm(all, all->pos_cur_tet.y,
						 all->pos_cur_tet.x + 1) == 1)
    all->pos_cur_tet.x++;
  if (all->pos_cur_tet.turn < 0 && test_pos_turn(all, all->pos_cur_tet.y,
						 all->pos_cur_tet.x + 1) == 1)
    all->pos_cur_tet.x++;
}

void		mvt_drop(t_all *all)
{
  if (all->pos_cur_tet.turn > 0 && test_pos_norm(all, all->pos_cur_tet.y + 1,
						 all->pos_cur_tet.x) == 1)
    all->pos_cur_tet.y++;
  if (all->pos_cur_tet.turn < 0 && test_pos_turn(all, all->pos_cur_tet.y + 1,
						 all->pos_cur_tet.x) == 1)
    all->pos_cur_tet.y++;
}

void		mvt_turn(t_all *all)
{
  if (all->pos_cur_tet.turn > 0 && test_pos_turn(all, all->pos_cur_tet.y,
						 all->pos_cur_tet.x) == 1)
  all->pos_cur_tet.turn *= -1;
  else if (all->pos_cur_tet.turn < 0 && test_pos_norm(all, all->pos_cur_tet.y,
						      all->pos_cur_tet.x) == 1)
  all->pos_cur_tet.turn *= -1;
}

void		tab_turn(t_all *all)
{
  unsigned int 	i;
  unsigned int 	j;
  unsigned int 	k;
  unsigned int 	l;

  i = all->pos_cur_tet.x;
  j = all->pos_cur_tet.y;
  k = -1;
  while (++k != all->pos_cur_tet.height && k + all->pos_cur_tet.x <
	 all->param.cols)
    {
      l = -1;
      while (++l != all->pos_cur_tet.width && l + all->pos_cur_tet.y <
	     all->param.rows)
	{
	  if (all->param.map[j + l][i + k] && all->pos_cur_tet.tetri[k][l] ==
	      '*')
	    all->param.map[j + l][i + k] = all->pos_cur_tet.color;
	  if (l + 1 + all->pos_cur_tet.y >= all->param.rows ||
	      (all->param.map[j + l + 1][i + k] != '0'
	       && all->param.map[j + l][i + k] != '0'))
	    all->update = '1';
	}
    }
}
