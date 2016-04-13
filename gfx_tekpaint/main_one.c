/*
** main_one.c for tekpaint in Documents/annee_1/semestre_1/infographie/Projets/Tekpaint/gfx_tekpaint
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue Jan 26 23:26:33 2016 Antoine MOREL
** Last update Tue Jan 26 23:26:33 2016 Antoine MOREL
*/

#include                <lapin.h>
#include                <lapin_enum.h>
#include                "my.h"
#include                "base.h"
#include                <unistd.h>
#include                <math.h>

void			rubber(t_lapin *lapin, t_bunny_position *pos_fin)
{
  t_bunny_position	pos_square;
  int			i;
  int			j;

  j = 0;
  i = 0;
  pos_square.x = pos_fin->x - 10;
  pos_square.y = pos_fin->y - 10;
  while (i != 21 || j != 20)
    {
      tekpixel_uns(lapin->pixelarray_2, &pos_square, WHITE);
      if (j == 20)
        {
          j = 0;
          i++;
          pos_square.x = pos_fin->x - 10;
          pos_square.y++;
        }
      else
        pos_square.x++;
      j++;
    }
}

void			palette(t_lapin *lapin,
				t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  unsigned		*pixels;
  t_bunny_position	pos_mouse;
  int			i;

  pos_mouse = pos_img(*pos);
  pixels = (unsigned *)pix->pixels;
  lapin->color = pixels[pos_mouse.x + (pos_mouse.y * pix->clipable.clip_width)];
  pixels = (unsigned *)lapin->pixelarray_1->pixels;
  i = 50 * 700;
  while (i != 50 * 768)
    {
      pixels[i] = lapin->color;
      i++;
    }
}

void			change_color(t_lapin *lapin,
				     t_bunny_pixelarray *pix, t_bunny_position *pos)
{
  unsigned		*pixels;
  t_bunny_position	pos_mouse;
  int			i;

  pos_mouse = pos_img_color(*pos);
  pixels = (unsigned *)pix->pixels;
  lapin->color = pixels[pos_mouse.x + (pos_mouse.y * pix->clipable.clip_width)];
  pixels = (unsigned *)lapin->pixelarray_1->pixels;
  i = 50 * 700;
  while (i != 50 * 768)
    {
      pixels[i] = lapin->color;
      i++;
    }
}

void			effect(t_lapin *lapin, t_bunny_position *pos)
{
  if (pos->x > 50 && pos->x < 100)
    sepia(lapin->pixelarray_2, 's');
  else if (pos->x > 100 && pos->x < 150)
    sepia(lapin->pixelarray_2, 'c');
  else if (pos->x > 150 && pos->x < 200)
    black_and_white(lapin->pixelarray_2);
  lapin->option = 0;
}


void			new_size(t_lapin *lapin, t_bunny_position *pos)
{
  if (pos->x > 50 && pos->x < 100)
    lapin->size = 0;
  else if (pos->x > 100 && pos->x < 150)
    lapin->size = 1;
  else if (pos->x > 150 && pos->x < 200)
    lapin->size = 2;
  lapin->option = 0;
}
