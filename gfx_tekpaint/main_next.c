/*
** main_next.c for tekpaint in Documents/annee_1/semestre_1/infographie/Projets/Tekpaint/gfx_tekpaint
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue Jan 26 23:23:21 2016 Antoine MOREL
** Last update Tue Jan 26 23:23:21 2016 Antoine MOREL
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#include		"my.h"
#include		"base.h"
#include		<unistd.h>
#include		<math.h>

void			set_max_heap_size(size_t);

void			size_bar(t_bunny_window *win,
				 t_bunny_pixelarray *pix, int x, int y)
{
  t_bunny_position	pos;
  pos.x = x;
  pos.y = y;
  bunny_blit(&win->buffer, &pix->clipable, &pos);
}


t_bunny_position	pos_img(t_bunny_position pos)
{
  t_bunny_position	pos_fin;

  pos_fin.x = pos.x - 50;
  pos_fin.y = pos.y;
  return (pos_fin);
}

t_bunny_position	pos_img_color(t_bunny_position pos)
{
  t_bunny_position	pos_fin;

  pos_fin.x = pos.x - 50;
  pos_fin.y = pos.y - 513;
  return (pos_fin);
}

void			pencil_draw(t_lapin *lapin,
				    t_bunny_position *pos_fin, unsigned int colore)
{
  t_bunny_position	pos_line[2];
  t_color		color;

  color.full = colore;
  if (lapin->pos_mouse_tmp.x == 0 && lapin->pos_mouse_tmp.y == 0)
    {
      lapin->pos_mouse_tmp.x = pos_fin->x;
      lapin->pos_mouse_tmp.y = pos_fin->y;
    }
  pos_line[0].x = lapin->pos_mouse_tmp.x;
  pos_line[0].y = lapin->pos_mouse_tmp.y;
  pos_line[1].x = pos_fin->x;
  pos_line[1].y = pos_fin->y;
  tekline(lapin->pixelarray_2, pos_line, &color, lapin->size);
  lapin->pos_mouse_tmp.x = pos_fin->x;
  lapin->pos_mouse_tmp.y = pos_fin->y;
}
