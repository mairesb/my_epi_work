/*
** aff.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_bstetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 11:19:38 2016 baptiste mairesse
** Last update Sat Mar 19 16:18:47 2016 baptiste mairesse
*/

#include 	<stdlib.h>
#include 	"main.h"

void		free_all(t_t_info *info)
{
  int		i;

  i = 0;
  free(info->name);
  while (i != info->height)
    free(info->tetri[i++]);
  free(info->tetri);
}

void 		make_to_tab(char *str, t_t_info *info, int i)
{
  if (my_strlen(str) > info->width || info->height < i)
    {
      info->error = '1';
      return ;
    }
  info->tetri[i - 1] = malloc(sizeof(char) * (my_strlen(str) + 1));
  info->tetri[i - 1] = my_strcopy(info->tetri[i - 1], str);
}

char 		*get_name(const char *file, t_t_info *info)
{
  int 		i;
  int 		k;
  char 		*str;

  i = 0;
  k = -1;
  str = my_strdup(".tetrimino");
  while (file[i] && file[i] != '.')
    i++;
  while (str[++k])
    {
      if (str[k] != file[i])
	info->error = '1';
      i++;
    }
  i = 0;
  while (file[i] && file[i] != '.')
    i++;
  free(str);
  str = malloc(sizeof(char) * (i + 1));
  str[i] = '\0';
  while (--i >= 0)
    str[i] = file[i];
  return (str);
}

void 		show_struct(t_t_info *info)
{
  int 		i;

  i = 0;
  if (!info->name)
    {
      return ;
    }
  if (info->error == '1')
    return ;
  my_putstr("Tetriminos : ");
  my_printf("Name %s : Size %d*%d : Color %d :\n", info->name, info->width,
	    info->height, info->color);
  while (info->tetri[i])
    {
      my_putstr(info->tetri[i]);
      my_putstr("\n");
      i++;
    }
}
