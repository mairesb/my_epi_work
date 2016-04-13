/*
** line_or_not.c for C:\Users\bapti\Documents\Dropbox\rendu in C:\Users\bapti\Documents\Dropbox\rendu\PSU_2015_tetris\Baptiste
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Wed Mar 02 11:54:03 2016 baptiste mairesse
** Last update Thu Mar 03 16:13:56 2016 baptiste mairesse
*/

#include 	"tetris.h"

void		have_line(unsigned int i_line, t_all *all)
{
 unsigned int 		j;

  all->game.score += 100;
  while (i_line != 1)
    {
      j = -1;
      while (++j != all->param.cols)
	{
	  all->param.map[i_line][j] = all->param.map[i_line - 1][j];
	}
      i_line--;
    }
}

void		line_or_not(t_all *all)
{
 unsigned int		i;
 unsigned int		j;
  int 		stars;

  i = -1;
  while (++i != all->param.rows)
    {
      stars = 0;
      j = -1;
      while (++j != all->param.cols)
	{
	  if (!(all->param.map[i][j] != '0'))
	    stars = 1;
	}
      if (stars == 0)
	have_line(i, all);
    }
}
