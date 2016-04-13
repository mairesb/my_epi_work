/*
** core.c for entrainement in Documents/annee_1/semestre_1/infographie/Others/entrainement
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Mon Dec 14 16:00:18 2015 Antoine MOREL
** Last update Mon Dec 14 16:00:18 2015 Antoine MOREL
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#include		"my.h"
#include		"base.h"

void			cpy_pixel(t_bunny_pixelarray *bmp,
				  t_bunny_pixelarray *pixelarray_1, int x, int y)
{
  int			i;
  int			j;
  int			k;
  int			f;
  unsigned		*pixels;
  unsigned		*pixels_bmp;

  pixels = (unsigned *)pixelarray_1->pixels;
  pixels_bmp = (unsigned *)bmp->pixels;
  i = bmp->clipable.clip_width * bmp->clipable.clip_height;
  j = x + (pixelarray_1->clipable.clip_width * y);
  k = 0;
  f = 0;
  while(k < i)
    {
      if (f == bmp->clipable.clip_width)
	{
	  f = 0;
	  j += pixelarray_1->clipable.clip_width - bmp->clipable.clip_width;
	}
      pixels[j] = pixels_bmp[k];
      j++;
      f++;
      k++;
    }
}

void			init_pixel_3(t_lapin *lapin)
{
  if (lapin->option == 4)
    {
      cpy_pixel(lapin->bmp.filter_select, lapin->pixelarray_1, 5, 505);
      cpy_pixel(lapin->bmp.invert, lapin->pixelarray_4, 5, 5);
      cpy_pixel(lapin->bmp.baw, lapin->pixelarray_4, 55, 5);
      cpy_pixel(lapin->bmp.blurs, lapin->pixelarray_4, 105, 5);
    }
  else
    cpy_pixel(lapin->bmp.filter, lapin->pixelarray_1, 5, 505);
}

void			init_pixel_2(t_lapin *lapin)
{
  if (lapin->tools == 6)
    cpy_pixel(lapin->bmp.Traces_select, lapin->pixelarray_1, 5, 205);
  else
    cpy_pixel(lapin->bmp.Traces, lapin->pixelarray_1, 5, 205);
  if (lapin->tools == 7)
    cpy_pixel(lapin->bmp.Palette_select, lapin->pixelarray_1, 5, 255);
  else
    cpy_pixel(lapin->bmp.Palette, lapin->pixelarray_1, 5, 255);
  if (lapin->size == 0)
    cpy_pixel(lapin->bmp.Brushs_small, lapin->pixelarray_1, 5, 605);
  if (lapin->size == 1)
    cpy_pixel(lapin->bmp.Brushs_med, lapin->pixelarray_1, 5, 605);
  if (lapin->size == 2)
    cpy_pixel(lapin->bmp.Brushs_large, lapin->pixelarray_1, 5, 605);
  if (lapin->option == 2)
    {
      cpy_pixel(lapin->bmp.Brushs_small, lapin->pixelarray_4, 5, 5);
      cpy_pixel(lapin->bmp.Brushs_med, lapin->pixelarray_4, 55, 5);
      cpy_pixel(lapin->bmp.Brushs_large, lapin->pixelarray_4, 105, 5);
    }
  init_pixel_3(lapin);
}

void			init_pixel_1(t_lapin *lapin)
{
  if (lapin->tools == 1 || lapin->tools == 2)
    cpy_pixel(lapin->bmp.Buckets_select, lapin->pixelarray_1, 5, 5);
  else
    cpy_pixel(lapin->bmp.Buckets, lapin->pixelarray_1, 5, 5);
  if (lapin->tools == 3)
    cpy_pixel(lapin->bmp.Brushs_select, lapin->pixelarray_1, 5, 55);
  else
    cpy_pixel(lapin->bmp.Brushs, lapin->pixelarray_1, 5, 55);
  if (lapin->tools == 4)
    cpy_pixel(lapin->bmp.Erasers_select, lapin->pixelarray_1, 5, 105);
  else
    cpy_pixel(lapin->bmp.Erasers, lapin->pixelarray_1, 5, 105);
  if (lapin->option == 1)
    cpy_pixel(lapin->bmp.Color_select, lapin->pixelarray_1, 5, 655);
  else
    cpy_pixel(lapin->bmp.Color, lapin->pixelarray_1, 5, 655);
  if (lapin->option == 3)
    cpy_pixel(lapin->bmp.Save_select, lapin->pixelarray_1, 5, 555);
  else
    cpy_pixel(lapin->bmp.Save, lapin->pixelarray_1, 5, 555);
  if (lapin->tools == 5)
    cpy_pixel(lapin->bmp.Circle_select, lapin->pixelarray_1, 5, 155);
  else
    cpy_pixel(lapin->bmp.Circle, lapin->pixelarray_1, 5, 155);
  init_pixel_2(lapin);
}

void			init_bmp(t_lapin *lapin)
{
  lapin->bmp.Buckets_select = load_bitmap("resoucre/Buckets_select.bmp");
  lapin->bmp.Buckets = load_bitmap("resoucre/Buckets.bmp");
  lapin->bmp.Brushs_select = load_bitmap("resoucre/Brushs_select.bmp");
  lapin->bmp.Brushs = load_bitmap("resoucre/Brushs.bmp");
  lapin->bmp.Erasers_select = load_bitmap("resoucre/Erasers_select.bmp");
  lapin->bmp.Erasers = load_bitmap("resoucre/Erasers.bmp");
  lapin->bmp.Color_select = load_bitmap("resoucre/Color_select.bmp");
  lapin->bmp.Color = load_bitmap("resoucre/Color.bmp");
  lapin->bmp.Brushs_small = load_bitmap("resoucre/Brushs_small.bmp");
  lapin->bmp.Brushs_med = load_bitmap("resoucre/Brushs_med.bmp");
  lapin->bmp.Brushs_large = load_bitmap("resoucre/Brushs_large.bmp");
  lapin->bmp.Circle = load_bitmap("resoucre/Squares.bmp");
  lapin->bmp.Circle_select = load_bitmap("resoucre/Squares_select.bmp");
  lapin->bmp.Traces = load_bitmap("resoucre/Traces.bmp");
  lapin->bmp.Traces_select = load_bitmap("resoucre/Traces_select.bmp");
  lapin->bmp.Box = load_bitmap("resoucre/Box.bmp");
  lapin->bmp.Save_select = load_bitmap("resoucre/Saves_select.bmp");
  lapin->bmp.Save = load_bitmap("resoucre/Saves.bmp");
  lapin->bmp.Palette_select = load_bitmap("resoucre/Palettes_select.bmp");
  lapin->bmp.Palette = load_bitmap("resoucre/Palettes.bmp");
  lapin->bmp.filter = load_bitmap("resoucre/Filters.bmp");
  lapin->bmp.filter_select = load_bitmap("resoucre/Filters_select.bmp");
  lapin->bmp.baw = load_bitmap("resoucre/BandWs.bmp");
  lapin->bmp.invert = load_bitmap("resoucre/Inverts.bmp");
  lapin->bmp.blurs = load_bitmap("resoucre/Blurs.bmp");
}
