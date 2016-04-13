/*
** palette.c for  in /home/pillon_m/rendu/rendu/gfx_tekpaint/pilloooon
**
** Made by maxime pillon
** Login   <pillon_m@epitech.net>
**
** Started on  Mon Jan 11 11:04:00 2016 maxime pillon
** Last update Tue Jan 12 15:28:56 2016 maxime pillon
*/

#include		<lapin.h>
#include		"my.h"

unsigned int		getcastfull(t_color *cast, int red, int green,
				    int blue)
{
  cast->argb[0] = red;
  cast->argb[1] = green;
  cast->argb[2] = blue;
  cast->argb[3] = 255;
  return (cast->full);
}

unsigned int		*do_palet(int i, int j,
				  unsigned int *color_256)
{
  t_color		cast;

  while (i < 256)
    {
      if (i <= 42)
	color_256[i] = getcastfull(&cast, 255, (j * 6), 0);
      else if (i <= 84)
	color_256[i] = getcastfull(&cast, 255 - (j * 6), 255, 0);
      else if (i <= 126)
	color_256[i] = getcastfull(&cast, 0, 255, (j * 6));
      else if (i <= 168)
	color_256[i] = getcastfull(&cast, 0, 255 - (j * 6), 255);
      else if (i <= 210)
	color_256[i] = getcastfull(&cast, (j * 6), 0, 255);
      else if (i >= 255)
	color_256[i] = getcastfull(&cast, 255, 0, 255 - (j * 5));
      j++;
      i++;
      if ((j == 43 || j == 85 || j == 127 || j == 211) && i < 220)
	j = 1;
    }
  return (color_256);
}

void			aff_palet(unsigned int *color_256,
				  t_bunny_pixelarray *pix_palet)
{
  t_bunny_position	*pos;
  int			i;
  t_color		color;

  i = 0;
  pos = bunny_malloc(sizeof(t_bunny_position) * 2);
  pos[0].x = 0;
  pos[0].y = 0;
  pos[1].x = 0;
  pos[1].y = 150;
  while (pos[1].x <= 512)
    {
      color.full = color_256[i];
      tekline(pix_palet, pos, &color);
      pos[0].x++;
      pos[1].x++;
    }
  return ;
}

t_bunny_pixelarray	*palet()
{
  unsigned int		*color_256;
  t_bunny_pixelarray	*pix_palet;

  pix_palet = bunny_new_pixelarray(512, 512);
  color_256 = bunny_malloc(sizeof(unsigned int) * 256);
  color_256 = do_palet(0, 0, color_256);
  aff_palet(color_256, pix_palet);
  return (pix_palet);
}
