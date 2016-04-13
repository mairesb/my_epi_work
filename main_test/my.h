/*
** gfx_tekgui.h for gfx_tekgui in /home/maires_b/Dropbox/rendu/gfx_tekgui
**
** Made by Mairesse Baptiste
** Login   <maires_b@epitech.net>
**
** Started on  Tue Feb  2 11:20:04 2016 Mairesse Baptiste
** Last update Thu Feb 11 09:55:59 2016 baptiste mairesse
*/
#ifndef		GFX_TEKGUI_H_
# define	GFX_TEKGUI_H_
#include	<lapin.h>

typedef struct 		s_bunny_circle
{
  t_bunny_position 	position;
  double 		radius;
  unsigned int 		color;
} 			t_bunny_circle;


void			tekpixel(t_bunny_pixelarray *pix, t_bunny_position
				     *pos, unsigned int color);

void 			tekcircle(t_bunny_pixelarray *pix,
				  t_bunny_position *pos,
				  double radius,
				  unsigned int color);

void 			mystic_clock(t_bunny_pixelarray *pix,
				     const t_bunny_circle *circle,
				     double angle,
				     size_t depth);

#endif		/* !GFX_TEKGUI_H_ */
