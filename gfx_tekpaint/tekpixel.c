/*
** tekpixel.c for tekpixel in /home/morel_j/Antoine/annee_1/semestre_1/infographie/iconofsin_2020
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Wed Nov 18 09:32:53 2015 Antoine MOREL
** Last update Sun Nov 22 16:51:58 2015 Antoine MOREL
*/

#include	<lapin.h>
#include	<lapin_enum.h>
#include	"./my.h"

void		tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos,
			 t_color *color)
{
  char		*pixel;

  if (pos->x < pix->clipable.clip_width && pos->y < pix->clipable.clip_height
      && pos->x >= 0 && pos->y >= 0)
    {
      pixel = pix ->pixels;
      pixel[(pos->y * pix->clipable.clip_width + pos->x) * 4] =
	color[0].argb[0];
      pixel[(pos->y * pix->clipable.clip_width + pos->x) * 4 + 1] =
	color[0].argb[1];
      pixel[(pos->y * pix->clipable.clip_width + pos->x) * 4 + 2] =
	color[0].argb[2];
      pixel[(pos->y * pix->clipable.clip_width + pos->x) * 4 + 3] =
	color[0].argb[3];
    }
}
