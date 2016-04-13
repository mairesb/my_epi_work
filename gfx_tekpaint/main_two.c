/*
** main_two.c for tekpaint in Documents/annee_1/semestre_1/infographie/Projets/Tekpaint/gfx_tekpaint
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue Jan 26 23:29:48 2016 Antoine MOREL
** Last update Tue Jan 26 23:29:48 2016 Antoine MOREL
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#include		"my.h"
#include		"base.h"
#include		<unistd.h>
#include		<math.h>

void			trace_square(t_lapin *lapin, 
				     t_bunny_position *pos_fin, unsigned int colore)
{
  t_bunny_position	pos[2];

  background(lapin->pixelarray_tmp, WHITE);
  if (lapin->pos_mouse_tmp.x == 0 && lapin->pos_mouse_tmp.y == 0)
    {
      lapin->pos_mouse_tmp.x = pos_fin->x;
      lapin->pos_mouse_tmp.y = pos_fin->y;
    }
  pos[0].x =  lapin->pos_mouse_tmp.x;
  pos[0].y =  lapin->pos_mouse_tmp.y;
  pos[1].x = pos_fin->x;
  pos[1].y = pos_fin->y;
  rectangular_withpos(pos, lapin->pixelarray_tmp, colore);
}

void			cpy_tmp_2(t_bunny_pixelarray *pix_1,
				  t_bunny_pixelarray *pix_2)
{
  int			i;
  unsigned		*pixel_1;
  unsigned		*pixel_2;

  i = 0;
  pixel_1 = (unsigned *)pix_1->pixels;
  pixel_2 = (unsigned *)pix_2->pixels;
  while (i != pix_1->clipable.clip_width * pix_1->clipable.clip_height)
    {
      pixel_1[i] = pixel_2[i];
      i++;
    }
}

void			cpy_tmp_to_file(t_lapin *lapin, int sel)
{
  int			i;
  int			leng;
  unsigned		*pixel_tmp;
  unsigned		*pixel;

  cpy_tmp_2(lapin->pixelarray_tmp_2, lapin->pixelarray_2);
  pixel_tmp = (unsigned *)lapin->pixelarray_tmp->pixels;
  if (sel == 1)
    pixel = (unsigned *)lapin->pixelarray_tmp_2->pixels;
  else if (sel == 0)
    pixel = (unsigned *)lapin->pixelarray_2->pixels;
  leng = lapin->pixelarray_tmp->clipable.clip_width *
    lapin->pixelarray_tmp->clipable.clip_height;
  i = 0;
  while (i != leng)
    {
      if (pixel_tmp[i] == lapin->color)
        {
          pixel[i] = pixel_tmp[i];
        }
      i++;
    }
  bunny_free(pixel);
  bunny_free(pixel_tmp);
}

void			trace_line(t_lapin *lapin,
				   t_bunny_position *pos_fin, unsigned int colore)
{
  t_bunny_position	pos[2];
  t_color		color;

  color.full = colore;
  background(lapin->pixelarray_tmp, WHITE);
  if (lapin->pos_mouse_tmp.x == 0 && lapin->pos_mouse_tmp.y == 0)
    {
      lapin->pos_mouse_tmp.x = pos_fin->x;
      lapin->pos_mouse_tmp.y = pos_fin->y;
    }
  pos[0].x =  lapin->pos_mouse_tmp.x;
  pos[0].y =  lapin->pos_mouse_tmp.y;
  pos[1].x = pos_fin->x;
  pos[1].y = pos_fin->y;
  tekline(lapin->pixelarray_tmp, pos, &color, lapin->size);
}

void			action_button_bis(t_lapin *lp,
					  t_bunny_position p_fin, t_bunny_position p)
{
  if (p.x > 50 && p.x < 200 && p.y > 600 && p.y < 650 && lp->option == 2)
    new_size(lp, &p);
  else if (p.x > 50 && p.x < 200 && p.y > 500 && p.y < 550 && lp->option == 4)
    effect(lp, &p);
  else if (p.x > 50 && lp->tools == 2)
    {
      do_peinture(lp->pixelarray_2, p_fin, lp->color);
      lp->tools = 0;
    }
  else
    lp->option = 0;
}
