/*
** for_norme.c for tekpaint in Documents/annee_1/semestre_1/infographie/Projets/Tekpaint/gfx_tekpaint
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Tue Jan 26 23:06:27 2016 Antoine MOREL
** Last update Tue Jan 26 23:06:27 2016 Antoine MOREL
*/

#include		<lapin.h>
#include		"my.h"

unsigned int		what_major(unsigned int colors)
{
  t_color		color;

  color.full = colors;
  if (color.argb[0] > color.argb[1] && color.argb[0] > color.argb[2])
    {
      color.argb[1] = color.argb[0];
      color.argb[2] = color.argb[0];
    }
  else if (color.argb[1] > color.argb[0] && color.argb[1] > color.argb[2])
    {
      color.argb[0] = color.argb[1];
      color.argb[2] = color.argb[1];
    }
  else if (color.argb[2] >= color.argb[0] && color.argb[2] >= color.argb[1])
    {
      color.argb[0] = color.argb[2];
      color.argb[1] = color.argb[2];
    }
  return (color.full);
}
