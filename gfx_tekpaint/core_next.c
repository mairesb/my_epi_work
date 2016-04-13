/*
** core_next.c for tekpaint in Documents/annee_1/semestre_1/infographie/Projets/Tekpaint/gfx_tekpaint
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue Jan 26 23:14:30 2016 Antoine MOREL
** Last update Tue Jan 26 23:14:30 2016 Antoine MOREL
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#include		"my.h"
#include		"base.h"

t_bunny_response	key(t_bunny_event_state state,
                            t_bunny_keysym keysysm, void *data)
{
  t_lapin		*lapin;

  lapin = data;
  (void)lapin;
  if (state == GO_DOWN && keysysm == BKS_ESCAPE)
    {
      return (EXIT_ON_SUCCESS);
    }
  return (GO_ON);
}

t_color			*set_color(int red, int green, int blue, int alpha)
{
  t_color		*color;

  color = bunny_malloc(sizeof *color);
  if (color != NULL)
    {
      color->argb[0] = red;
      color->argb[1] = green;
      color->argb[2] = blue;
      color->argb[3] = alpha;
    }
  return (color);
}

t_lapin			*set_lapin(t_lapin *lapin)
{
  if (lapin != NULL)
    {
      lapin->window_1 = bunny_start(1074, 768, 0, "My_tekpaint");
      if (lapin->window_1 == 0)
        return (NULL);
      init_pixel_array(lapin);
      init_bmp(lapin);
    }
  lapin->interf_or_not = 2;
  lapin->tools = 0;
  lapin->mouse_click = 0;
  lapin->pos_mouse_tmp.x = 0;
  lapin->pos_mouse_tmp.y = 0;
  lapin->color = BLACK;
  lapin->size = 1;
  lapin->option = 0;
  lapin->save = 0;
  init_pixel_1(lapin);
  return (lapin);
}

void			background(t_bunny_pixelarray *pixelarray,
                                   unsigned int color)
{
  int			i;
  int			total;
  unsigned		*pixels;

  i = 0;
  total = pixelarray->clipable.clip_width * pixelarray->clipable.clip_height;
  pixels = (unsigned *)pixelarray->pixels;
  while (i < total)
    {
      pixels[i] = color;
      i++;
    }
}

void			blit_to_window(t_bunny_window *window,
                                       t_bunny_pixelarray *pixelarray)
{
  t_bunny_position	position;

  position.x = 0;
  position.y = 0;
  bunny_blit(&window->buffer, &pixelarray->clipable, &position);
}
