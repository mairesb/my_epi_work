/*
** tools.c for fdf2 in Documents/annee_1/semestre_1/infographie/Projets/Fdf2/gfx_fdf2
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Thu Dec 17 10:09:07 2015 Antoine MOREL
** Last update Thu Dec 17 10:09:07 2015 Antoine MOREL
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#include		"my.h"
#include		"base.h"

void			tekpixel_uns(t_bunny_pixelarray *pix, t_bunny_position *pos,
				     unsigned int color)
{
  if (pos->x < pix->clipable.clip_width && pos->y < pix->clipable.clip_height
      && pos->x >= 0 && pos->y >= 0)
    ((unsigned int*)pix->pixels)
      [pos->y * pix->clipable.clip_width + pos->x] = color;
}
