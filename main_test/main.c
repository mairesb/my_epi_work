/*
** main.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\mystic_2020
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 11 09:14:06 2016 baptiste mairesse
** Last update Thu Feb 11 10:50:10 2016 baptiste mairesse
*/
#include <lapin.h>
#include "my.h"

typedef struct s_truc
{
  t_bunny_circle circle;
  t_bunny_window *win;
  t_bunny_pixelarray *pix;
  double angle;
}t_truc;

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

t_bunny_response	refresh(void *data)
{
  t_truc *tr;

  tr = data;
  if (tr->angle >= 360.0)
    tr->angle = 0.0;
  background(tr->pix, BLACK);
  mystic_clock(tr->pix, &tr->circle, tr->angle, 6);
  blit_to_window(tr->win, tr->pix);
  bunny_display(tr->win);
  tr->angle += 0.1;
  usleep(9999);
  return (GO_ON);
}

int main()
{
  t_truc tr;
  tr.win = bunny_start(800, 600, 0, "coucuo");
  tr.pix = bunny_new_pixelarray(800, 600);
  tr.angle = 0.0;
  tr.circle.radius = 100;
  tr.circle.color = RED;
  tr.circle.position.x = 400;
  tr.circle.position.y = 400;
  background(tr.pix, BLACK);
  bunny_set_loop_main_function(&refresh);

  bunny_loop(tr.win, 13, &tr);
  return 0;

}
