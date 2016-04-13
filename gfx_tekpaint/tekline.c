/*
** tekline.c for tekline in /home/morel_j/Antoine/annee_1/semestre_1/infographie/iconofsin_2020
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Wed Nov 18 09:59:20 2015 Antoine MOREL
** Last update Sun Nov 22 16:22:42 2015 Antoine MOREL
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#include		<math.h>
#include		"./my.h"

int			abscisse(int c)
{
  if (c < 0)
    return (-c);
  return (c);
}

void			initline(t_bunny_position *stylo, t_bunny_position *pos,
				 int *a, int *b)
{
  stylo->x = pos[0].x;
  stylo->y = pos[0].y;
  *a = abscisse(pos[1].x - stylo->x);
  *b = abscisse(pos[1].y - stylo->y);
}

void			circle_draw(t_bunny_pixelarray *pix,
				    t_bunny_position *pos, t_color *color, int size)
{
  int			lenght;

  if (size == 0)
    lenght = 1;
  if (size == 1)
    lenght = 20;
  if (size == 2)
    lenght = 40;
  paint_circle(pos, lenght, pix, color);
}

void			tekline(t_bunny_pixelarray *pix, t_bunny_position *pos,
				t_color *color, int size)
{
  t_bunny_position	stylo;
  int			a;
  int			b;
  int			err;
  int			e2;

  circle_draw(pix, &pos[1], color, size);
  initline(&stylo, pos, &a, &b);
  err = (a > b ? a / 2 : -b / 2);
  while (stylo.x != pos[1].x || stylo.y != pos[1].y)
    {
      circle_draw(pix, &stylo, color, size);
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
