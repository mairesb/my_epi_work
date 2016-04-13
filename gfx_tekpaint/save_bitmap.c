/*
** save_bitmap.c for tekpaint in Documents/annee_1/semestre_1/infographie/Projets/Tekpaint/gfx_tekpaint
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue Jan 12 11:20:55 2016 Antoine MOREL
** Last update Tue Jan 12 11:20:55 2016 Antoine MOREL
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#include		<sys/types.h>
#include		<sys/stat.h>
#include		<fcntl.h>
#include		<unistd.h>
#include		"base.h"

void			my_saving(int fd, t_bunny_pixelarray *pix,
				  t_hbmp *hbmp)
{
  t_bunny_position	pos;
  t_color		g_color;
  unsigned int		save;

  pos.y = hbmp->height;
  while (pos.y > 0)
    {
      pos.x = 0;
      while (pos.x < hbmp->width)
	{
	  g_color.full = ((unsigned int *)pix->pixels)
	    [(pos.y - 1) * hbmp->width + pos.x];
	  save = g_color.argb[0];
	  g_color.argb[0] = g_color.argb[2];
	  g_color.argb[2] = save;
	  write(fd, (char *) &(g_color.full), 4);
	  pos.x++;
	}
      pos.y--;
    }
}

t_hbmp			*complete_hbmp(t_bunny_pixelarray *pix, t_hbmp *hbmp)
{
  hbmp->id = 0x4D42;
  hbmp->size = (pix->clipable.clip_width *
		pix->clipable.clip_height * 32) / 8 + 54 ;
  hbmp->useless = 0;
  hbmp->pos_pix = 54;
  hbmp->head_size = 40;
  hbmp->width = pix->clipable.clip_width;
  hbmp->height = pix->clipable.clip_height;
  hbmp->p_bit = 1;
  hbmp->bits_pix = 32;
  hbmp->cprs = 0;
  hbmp->oct_size = 0;
  hbmp->pix_width = 0;
  hbmp->pix_height = 0;
  hbmp->color_pal = 0;
  hbmp->color_imp = 0;
  return (hbmp);
}

int			save_bitmap(const char *name_file,
				    t_bunny_pixelarray *pix)
{
  int			fd;
  t_hbmp		*hbmp;

  if ((fd = open(name_file, O_CREAT | O_RDONLY | O_WRONLY |
		 O_TRUNC | O_APPEND, S_IWUSR | S_IRUSR | S_IRGRP
		 | S_IWGRP | S_IROTH)) == -1)
    return (-1);
  if ((hbmp = bunny_malloc(sizeof(t_hbmp))) == NULL)
    return (-1);
  hbmp = complete_hbmp(pix, hbmp);
  if (write(fd, hbmp, sizeof(t_hbmp)) == -1)
    return (-1);
  my_saving(fd, pix, hbmp);
  bunny_free(hbmp);
  close(fd);
  return (0);
}
