/*
** core.c for entrainement in Documents/annee_1/semestre_1/infographie/Others/entrainement
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Mon Dec 14 14:53:55 2015 Antoine MOREL
** Last update Mon Dec 14 14:53:55 2015 Antoine MOREL
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#include		"my.h"
#include		"base.h"
#include		<unistd.h>
#include		<math.h>

t_bunny_response	mouse(t_bunny_event_state state,
			      t_bunny_mousebutton button, void *data)
{
  t_lapin		*lapin;

  lapin = data;
  (void)lapin;
  if (state == GO_DOWN && button == 0)
    {
      lapin->mouse_click = 1;
    }
  else if (state == GO_UP && button == 0)
    {
      if (lapin->tools == 3)
	{
	  lapin->pos_mouse_tmp.x = 0;
	  lapin->pos_mouse_tmp.y = 0;
	}
      lapin->mouse_click = 0;
    }
  return (GO_ON);
}

void			paint(t_lapin *lapin)
{
  if (lapin->interf_or_not == 1)
    background(lapin->pixelarray_1, PURPLE);
  else if (lapin->interf_or_not == 0)
    background(lapin->pixelarray_2, PURPLE);
}

void			print_bar(t_lapin *lapin)
{
  if (lapin->mouse_click == 1)
    size_bar(lapin->window_1, lapin->pixelarray_tmp_2, 50, 0);
  else
    size_bar(lapin->window_1, lapin->pixelarray_2, 50, 0);
  if (lapin->option == 1)
    {
      size_bar(lapin->window_1, lapin->pixelarray_3, 50, 513);
    }
  else if (lapin->option == 2)
    size_bar(lapin->window_1, lapin->pixelarray_4, 50, 600);
  else if (lapin->option == 3)
    size_bar(lapin->window_1, lapin->bmp.Box, 340, 300);
  else if (lapin->option == 4)
    size_bar(lapin->window_1, lapin->pixelarray_4, 50, 500);
  bunny_display(lapin->window_1);
}

t_bunny_response	refresh_my_game(void *data)
{
  t_lapin		*lapin;

  lapin = data;
  bunny_set_key_response(&key);
  bunny_set_click_response(&mouse);
  mouse_position(lapin);
  blit_to_window(lapin->window_1, lapin->pixelarray_1);
  size_bar(lapin->window_1, lapin->font, 50, 0);
  print_bar(lapin);
  if (lapin->save == 1)
    {
      save_bitmap(lapin->str, lapin->pixelarray_2);
      return (EXIT_SUCCESS);
    }
  else if (lapin->save == 2)
    {
      save_file_ftn(lapin->pixelarray_2, lapin->str);
      return (EXIT_SUCCESS);
    }
  return (GO_ON);
}

int			main(int ac, char **av)
{
  t_lapin		*lapin;
  t_bunny_pixelarray 	*tmp;

  set_max_heap_size(30);
  lapin = bunny_malloc(sizeof *lapin);
  if (lapin == NULL)
    return (84);
  lapin->format = parse(ac, av);
  if (lapin->format == 1)
    tmp = load_bitmap(av[1]);
  else if (lapin->format == 2)
    tmp = load_ftn(av[1]);
  if (lapin->format == -1)
    return (1);
  if (lapin->format != -1 && tmp == NULL)
    tmp = NULL;
  lapin->pixelarray_2 = tmp;
  lapin = set_lapin(lapin);
  lapin->str = av[1];
  if (lapin )
    bunny_set_loop_main_function(&refresh_my_game);
  bunny_loop(lapin->window_1, 250, lapin);
  free_all(lapin);
  return (0);
}
