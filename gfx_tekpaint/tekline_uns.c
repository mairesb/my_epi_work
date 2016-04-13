/*
** tekline_uns.c for fdf2 in Documents/annee_1/semestre_1/infographie/Projets/Fdf2/gfx_fdf2
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Thu Dec 17 10:49:11 2015 Antoine MOREL
** Last update Thu Dec 17 10:49:11 2015 Antoine MOREL
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#include		"my.h"

int			abscisse_uns(int c)
{
  if (c < 0)
    return (-c);
  return (c);
}

void			initline_uns(t_bunny_position *stylo,
				     t_bunny_position *pos, int *a, int *b)
{
  stylo->x = pos[0].x;
  stylo->y = pos[0].y;
  *a = abscisse_uns(pos[1].x - stylo->x);
  *b = abscisse_uns(pos[1].y - stylo->y);
}

void			tekline_uns(t_bunny_pixelarray *pix, t_bunny_position *pos,
				    unsigned int color)
{
  t_bunny_position	stylo;
  int			a;
  int			b;
  int			err;
  int			e2;

  tekpixel_uns(pix, &pos[1], color);
  initline_uns(&stylo, pos, &a, &b);
  err = (a > b ? a / 2 : -b / 2);
  while (stylo.x != pos[1].x || stylo.y != pos[1].y)
    {
      tekpixel_uns(pix, &stylo, color);
      e2 = err;
      if (e2 > -a)
	{
	  err = err - b;
	  stylo.x = stylo.x + (stylo.x < pos[1].x ? 1 : -1);
	}
      if (e2 < b)
	{
	  err = err + a;
	  stylo.y = stylo.y + (stylo.y < pos[1].y ? 1 : -1);
	}
    }
}
