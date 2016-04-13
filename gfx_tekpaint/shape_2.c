/*
** fdf2.c for fdf2 in /home/poinss_y/Infographie/gfx_fdf2
**
** Made by yan poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Mon Dec 14 12:14:16 2015 yan poinssot
** Last update Tue Jan 12 16:14:06 2016 Yan Poinssot
*/

#include		<unistd.h>
#include		<lapin.h>
#include		<math.h>
#include		"my.h"

void			paint_circle(t_bunny_position *pos, int radius,
				     t_bunny_pixelarray *pix, t_color *color)
{
  int			x;
  int			y;
  int			corr;
  t_bunny_position	*coord;

  y = -radius;
  coord = bunny_malloc(sizeof(coord));
  while (y <= radius)
    {
      x = -radius - 1;
      corr = 0;
      while (++x <= radius)
	{
	  if (x * x + y * y <= radius * radius)
	    {
	      corr = 1;
	      coord->x = pos->x + x;
	      coord->y = pos->y + y;
	      tekpixel(pix, coord, color);
	    }
	  else if (corr == 1)
	    x = radius;
	}
      y++;
    }
}

void			paint_square(t_bunny_position *pos, int radius,
				     t_bunny_pixelarray *pix, unsigned int color)
{
  int			x;
  int			y;
  t_bunny_position	*coord;

  y = 0;
  coord = bunny_malloc(sizeof(coord));
  while (y <= radius)
    {
      x = 0;
      while (x <= radius)
	{
	  coord->x = pos->x + x;
	  coord->y = pos->y + y;
	  tekpixel_uns(pix, coord, color);
	  x++;
	}
      y++;
    }
}
