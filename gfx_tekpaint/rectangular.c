/*
** rectangular.c for  in /home/pillon_m/rendu/rendu/gfx_tekpaint/pilloooon
** 
** Made by maxime pillon
** Login   <pillon_m@epitech.net>
** 
** Started on  Mon Jan 11 10:42:52 2016 maxime pillon
** Last update Tue Jan 12 15:23:28 2016 maxime pillon
*/

#include		<lapin.h>
#include		"my.h"

void			rectangular_withpos(t_bunny_position *pos,
					    t_bunny_pixelarray *pix_palet,
					    unsigned int     color)
{
  t_bunny_position	*line_square;
  t_color		color_square;

  color_square.full = color;
  line_square = bunny_malloc(sizeof(t_bunny_position) * 2);
  line_square[0].x = pos[0].x;
  line_square[0].y = pos[0].y;
  line_square[1].x = pos[0].x;
  line_square[1].y = pos[1].y;
  tekline(pix_palet, line_square, &color_square, 0);
  line_square[0].x = pos[1].x;
  line_square[0].y = pos[1].y;
  tekline(pix_palet, line_square, &color_square, 0);
  line_square[1].x = pos[1].x;
  line_square[1].y = pos[0].y;
  tekline(pix_palet, line_square, &color_square, 0);
  line_square[0].x = pos[0].x;
  line_square[0].y = pos[0].y;
  tekline(pix_palet, line_square, &color_square, 0);
}
