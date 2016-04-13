/*
** fdf2.c for fdf2 in /home/poinss_y/Infographie/gfx_fdf2
**
** Made by yan poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Mon Dec 14 12:14:16 2015 yan poinssot
** Last update Tue Jan 26 20:52:35 2016 Yan Poinssot
*/

#include		<lapin.h>
#include		"my.h"

void			black_and_white(t_bunny_pixelarray *pix)
{
  t_bunny_position	pos;

  pos.y = 0;
  while (pos.y < pix->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < pix->clipable.clip_width)
	{
	  ((unsigned int *)pix->pixels)[pos.y * pix->clipable.clip_width + pos.x] =
	    what_major(((unsigned int *)pix->pixels)
		       [pos.y * pix->clipable.clip_width + pos.x]);
	  pos.x++;
	}
      pos.y++;
    }
}

void			set_cold(t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  t_color		color;

  color.full = ((unsigned int *)pix->pixels)
    [pos->y * pix->clipable.clip_width + pos->x];
  if (color.argb[2] + 50 < 255)
    color.argb[2] += 50;
  else
    color.argb[2] = 255;
  ((unsigned int *)pix->pixels)
    [pos->y * pix->clipable.clip_width + pos->x] = color.full;
}

void			set_sepia(t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  t_color		color;

  color.full = ((unsigned int *)pix->pixels)
    [pos->y * pix->clipable.clip_width + pos->x];
  if (color.argb[0] + 50 < 255)
    color.argb[0] += 50;
  else
    color.argb[0] = 255;
  ((unsigned int *)pix->pixels)
    [pos->y * pix->clipable.clip_width + pos->x] = color.full;
}

void			set_coord(t_bunny_position *pos, int x, int y)
{
  pos->x = x;
  pos->y = y;
}

void			sepia(t_bunny_pixelarray *pix, char c)
{
  t_bunny_position	pos;
  int			y;
  int			x;

  y = 0;
  while (y < pix->clipable.clip_height)
    {
      x = 0;
      while (x < pix->clipable.clip_width)
	{
	  set_coord(&pos, x, y);
	  if (c == 's')
	    set_sepia(pix, &pos);
	  if (c == 'c')
	    set_cold(pix, &pos);
	  x++;
	}
      y++;
    }
}
