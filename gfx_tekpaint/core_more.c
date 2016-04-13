/*
** core_more.c for tekpaint in Documents/annee_1/semestre_1/infographie/Projets/Tekpaint/gfx_tekpaint
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue Jan 26 23:19:59 2016 Antoine MOREL
** Last update Tue Jan 26 23:19:59 2016 Antoine MOREL
*/

#include	<lapin.h>
#include	<lapin_enum.h>
#include	"my.h"
#include	"base.h"

void		init_pixel_array(t_lapin *lapin)
{
  int		width;
  int		height;

  if (lapin->pixelarray_2 == NULL)
    {
      lapin->pixelarray_2 = bunny_new_pixelarray(1024, 768);
      background(lapin->pixelarray_2, WHITE);
    }
  width = lapin->pixelarray_2->clipable.clip_width;
  height = lapin->pixelarray_2->clipable.clip_height;
  lapin->pixelarray_1 = bunny_new_pixelarray(50, 768);
  lapin->font = bunny_new_pixelarray(1024, 768);
  lapin->pixelarray_tmp_2 = bunny_new_pixelarray(width, height);
  lapin->pixelarray_tmp = bunny_new_pixelarray(width, height);
  lapin->pixelarray_3 = bunny_new_pixelarray(255, 255);
  lapin->pixelarray_4 = bunny_new_pixelarray(150, 50);
  lapin->pixelarray_3 = load_bitmap("resoucre/Color_palette.bmp");
  background(lapin->pixelarray_tmp, WHITE);
  background(lapin->font, 0xBEBEBE);
  background(lapin->pixelarray_tmp_2, WHITE);
  background(lapin->pixelarray_1, 0x282828);
  background(lapin->pixelarray_4, 0x282828);
}
