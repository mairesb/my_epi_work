/*
** main_three.c for tekpaint in Documents/annee_1/semestre_1/infographie/Projets/Tekpaint/gfx_tekpaint
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue Jan 26 23:33:01 2016 Antoine MOREL
** Last update Tue Jan 26 23:33:01 2016 Antoine MOREL
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#include		"my.h"
#include		"base.h"
#include		<unistd.h>
#include		<math.h>

void			action_button(t_lapin *lp,
				      t_bunny_position p_fin, t_bunny_position p)
{
  if (p.x > 360 && p.x < 533 && p.y > 379 && p.y < 435 && lp->option == 3)
    lp->save = 1;
  else if (p.x > 556 && p.x < 729 && p.y > 379 && p.y < 435 && lp->option == 3)
    lp->save = 2;
  else if (p.x > 50 && lp->tools == 3 && lp->option == 0)
    pencil_draw(lp, &p_fin, lp->color);
  else if (p.x > 50 && lp->tools == 6 && lp->option == 0)
    trace_line(lp, &p_fin, lp->color);
  else if (p.x > 50 && lp->tools == 5 && lp->option == 0)
    trace_square(lp, &p_fin, lp->color);
  else if (p.x > 50 && lp->tools == 4 && lp->option == 0)
    pencil_draw(lp, &p_fin, WHITE);
  else if (p.x > 50 && p.x < 255 && p.y > 513 && p.y < 768 && lp->option == 1)
    {
      change_color(lp, lp->pixelarray_3, &p);
      lp->option = 0;
    }
  else if (p.x > 50 && lp->tools == 7)
    {
      palette(lp, lp->pixelarray_2, &p);
      lp->tools = 0;
    }
  else
    action_button_bis(lp, p_fin, p);
}

void			touch_button(t_lapin *lapin,
				     t_bunny_position pos, t_bunny_position pos_fn)
{
  if (pos.x < 50 && pos.x > 0 && pos.y > 0 && pos.y < 50)
    lapin->tools = 2;
  else if (pos.x < 50 && pos.x > 0 && pos.y > 50 && pos.y < 100)
    lapin->tools = 3;
  else if (pos.x < 50 && pos.x > 0 && pos.y > 100 && pos.y < 150)
    lapin->tools = 4;
  else if (pos.x < 50 && pos.x > 0 && pos.y > 150 && pos.y < 200)
    lapin->tools = 5;
  else if (pos.x < 50 && pos.x > 0 && pos.y > 200 && pos.y < 250)
    lapin->tools = 6;
  else if (pos.x < 50 && pos.x > 0 && pos.y > 250 && pos.y < 300)
    lapin->tools = 7;
  else if (pos.x < 50 && pos.x > 0 && pos.y > 300 && pos.y < 350)
    lapin->tools = 0;
  else if (pos.x < 50 && pos.x > 0 && pos.y > 650 && pos.y < 700)
    lapin->option = 1;
  else if (pos.x < 50 && pos.x > 0 && pos.y > 600 && pos.y < 650)
    lapin->option = 2;
  else if (pos.x < 50 && pos.x > 0 && pos.y > 550 && pos.y < 600)
    lapin->option = 3;
  else if (pos.x < 50 && pos.x > 0 && pos.y > 500 && pos.y < 550)
    lapin->option = 4;
  else
    action_button(lapin, pos_fn, pos);
}

void			mouse_position(t_lapin *lapin)
{
  t_bunny_position	pos;
  const t_bunny_position	*pos_m;
  t_bunny_position	pos_fin;

  pos_m = bunny_get_mouse_position();
  pos = *pos_m;
  pos_fin.x = pos.x - 50;
  pos_fin.y = pos.y;
  if (lapin->mouse_click == 1)
    {
      touch_button(lapin, pos, pos_fin);
      init_pixel_1(lapin);
      cpy_tmp_to_file(lapin, 1);
    }
  else
    {
      lapin->pos_mouse_tmp.x = 0;
      lapin->pos_mouse_tmp.y = 0;
      cpy_tmp_to_file(lapin, 0);
    }
}
