/*
** bunny_free.c for  in /home/pillon_m/rendu/rendu/gfx_tekpaint/pilloooon
** 
** Made by maxime pillon
** Login   <pillon_m@epitech.net>
** 
** Started on  Tue Jan 26 21:38:40 2016 maxime pillon
** Last update Tue Jan 26 22:01:18 2016 maxime pillon
*/

#include	<lapin.h>
#include	"base.h"

void		free_pixelarray(t_lapin *lapin)
{
  bunny_delete_clipable(&(lapin->font->clipable));
  bunny_delete_clipable(&(lapin->pixelarray_1->clipable));
  bunny_delete_clipable(&(lapin->pixelarray_2->clipable));
  bunny_delete_clipable(&(lapin->pixelarray_3->clipable));
  bunny_delete_clipable(&(lapin->pixelarray_4->clipable));
  bunny_delete_clipable(&(lapin->pixelarray_tmp->clipable));
  bunny_delete_clipable(&(lapin->pixelarray_tmp_2->clipable));
  bunny_delete_clipable(&(lapin->bmp.Brushs->clipable));
  bunny_delete_clipable(&(lapin->bmp.Buckets->clipable));
  bunny_delete_clipable(&(lapin->bmp.Erasers->clipable));
  bunny_delete_clipable(&(lapin->bmp.Brushs_select->clipable));
  bunny_delete_clipable(&(lapin->bmp.Buckets_select->clipable));
  bunny_delete_clipable(&(lapin->bmp.Erasers_select->clipable));
  bunny_delete_clipable(&(lapin->bmp.Brushs_small->clipable));
  bunny_delete_clipable(&(lapin->bmp.Brushs_med->clipable));
  bunny_delete_clipable(&(lapin->bmp.Brushs_large->clipable));
  bunny_delete_clipable(&(lapin->bmp.Color_select->clipable));
  bunny_delete_clipable(&(lapin->bmp.Color->clipable));
  bunny_delete_clipable(&(lapin->bmp.Circle_select->clipable));
  bunny_delete_clipable(&(lapin->bmp.Circle->clipable));
  bunny_delete_clipable(&(lapin->bmp.Traces->clipable));
  bunny_delete_clipable(&(lapin->bmp.Traces_select->clipable));
  bunny_delete_clipable(&(lapin->bmp.Box->clipable));
}

void		free_all(t_lapin *lapin)
{
  bunny_delete_clipable(&(lapin->bmp.Save->clipable));
  bunny_delete_clipable(&(lapin->bmp.Save_select->clipable));
  bunny_delete_clipable(&(lapin->bmp.Palette->clipable));
  bunny_delete_clipable(&(lapin->bmp.Palette_select->clipable));
  bunny_delete_clipable(&(lapin->bmp.Brushs->clipable));
  bunny_delete_clipable(&(lapin->bmp.filter_select->clipable));
  bunny_delete_clipable(&(lapin->bmp.filter->clipable));
  bunny_delete_clipable(&(lapin->bmp.baw->clipable));
  bunny_delete_clipable(&(lapin->bmp.blurs->clipable));
  bunny_delete_clipable(&(lapin->bmp.invert->clipable));
  free_pixelarray(lapin);
  bunny_stop(lapin->window_1);
}
