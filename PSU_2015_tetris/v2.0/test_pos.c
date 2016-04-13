/*
** test_pos.c for C:\Users\bapti\Documents\Dropbox\rendu in C:\Users\bapti\Documents\Dropbox\rendu\PSU_2015_tetris\Baptiste
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Wed Mar 02 13:02:44 2016 baptiste mairesse
** Last update Thu Mar 03 16:15:33 2016 baptiste mairesse
*/

#include 	"tetris.h"

int		test_pos_norm(t_all *all, unsigned int y, unsigned int x)
{
  unsigned int	i;
  unsigned int	j;

  i = -1;
  while (++i != all->pos_cur_tet.height)
    {
      j = -1;
      while (++j != all->pos_cur_tet.width)
	{
	  if (i + y < all->param.rows && j + x < all->param.cols)
	    {
	      if (all->pos_cur_tet.tetri[i][j] == '*')
		{
		  if (all->param.map_tmp[i + y][j + x] != '0')
		    return (0);
		}
	    }
	  else
	    return (0);
	}
    }
  return (1);
}

int 		test_pos_turn(t_all *all, unsigned int y, unsigned int x)
{
  unsigned int	i;
  unsigned int	j;

  i = -1;
  while (++i != all->pos_cur_tet.height)
    {
      j = -1;
      while (++j != all->pos_cur_tet.width)
	{
	  if (j + y < all->param.rows && i + x < all->param.cols)
	    {
	      if (all->pos_cur_tet.tetri[i][j] == '*')
		{
		  if (all->param.map_tmp[j + y][i + x] != '0')
		    return (0);
		}
	    }
	  else
	    return (0);
	}
    }
  return (1);
}
