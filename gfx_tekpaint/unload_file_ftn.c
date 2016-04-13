/*
** unload_file_ftn.c for  in /home/pillon_m/rendu/rendu/gfx_tekpaint/pilloooon
** 
** Made by maxime pillon
** Login   <pillon_m@epitech.net>
** 
** Started on  Mon Jan 25 16:33:28 2016 maxime pillon
** Last update Mon Jan 25 17:22:36 2016 maxime pillon
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<unistd.h>
#include		"base.h"
#include		"my.h"

t_bunny_pixelarray	*complete_load(t_bunny_pixelarray *pix,
				       int fd)
{
  t_bunny_position	pos;
  char			buf[4];

  pos.x = 0;
  while (pos.y < pix->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < pix->clipable.clip_width)
	{
	  if (read(fd, buf, 4) != 4)
	    return (pix);
	  ((unsigned int *)pix->pixels)
	    [pos.y * pix->clipable.clip_width + pos.x] =
	    (*(unsigned int *)buf);
	  pos.x++;
	}
      pos.y++;
    }
  close(fd);
  return (pix);
}

t_bunny_pixelarray	*load_ftn(const char *file)
{
  int			fd;
  t_bunny_pixelarray	*pix;
  char			buff[15];
  int			width;
  int			height;

  if ((fd = open(file, O_RDONLY)) == -1)
    return (NULL);
  if ((read(fd, buff, 15)) != 15)
    return (NULL);
  if (my_strcmp(buff, "AZE123'(-==*$\n") == -1)
    return (NULL);
  read(fd, &width, 4);
  read(fd, &height, 4);
  pix = bunny_new_pixelarray(width, height);
  pix->clipable.clip_x_position = 0;
  pix->clipable.clip_y_position = 0;
  pix->clipable.clip_width = width;
  pix->clipable.clip_height = height;
  pix = complete_load(pix, fd);
  return (pix);
}
