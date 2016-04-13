/*
** save_file_ftn.c for  in /home/pillon_m/rendu/rendu/gfx_tekpaint/pilloooon
** 
** Made by maxime pillon
** Login   <pillon_m@epitech.net>
** 
** Started on  Mon Jan 25 10:20:36 2016 maxime pillon
** Last update Tue Jan 26 16:57:59 2016 maxime pillon
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<unistd.h>

void			write_all_screen(int fd, t_bunny_pixelarray * pix)
{
  t_bunny_position	pos;

  pos.y = 0;
  while (pos.y < pix->clipable.clip_height)
    {
      pos.x = 0;
      while (pos.x < pix->clipable.clip_width)
	{
	  write(fd, (char *) &((unsigned int *)pix->pixels)
		[pos.y *  pix->clipable.clip_width + pos.x], 4);
	  pos.x++;
	}
      pos.y++;
    }
  close(fd);
}

int			save_file_ftn(t_bunny_pixelarray *pix,
				      const char *name)
{
  int			fd;
  
  if ((fd = open(name, O_CREAT | O_RDONLY | O_WRONLY |
		 O_TRUNC | O_APPEND, S_IWUSR | S_IRUSR
		 | S_IRGRP | S_IWGRP | S_IROTH)) == -1)
    return (-1);
  write(fd, "AZE123'(-==*$\n", 15);
  write(fd, (char *) &(pix->clipable.clip_width), 4);
  write(fd, (char *) &(pix->clipable.clip_height), 4);
  write_all_screen(fd, pix);
  return (0);
}
