/*
** get_tetri.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Fri Feb 26 17:37:03 2016 baptiste mairesse
** Last update Sun Mar 20 10:02:01 2016 baptiste mairesse
*/

#include 	"tetris.h"
#include 	<stdlib.h>
#include 	<sys/types.h>
#include 	<dirent.h>


void 		start_list(t_tetrictrl *l)
{
  l->first = NULL;
  l->last = NULL;
}

void 		 make_top(t_tetrictrl *l, t_t_info *info, int nb)
{
  t_tetri 	*elem;

  elem = malloc(sizeof(t_tetri));
  if (elem == NULL)
    exit(84);
  elem->name = info->name;
  elem->width = info->width;
  elem->height = info->height;
  elem->color = info->color;
  elem->tetri = info->tetri;
  elem->nb = nb;
  elem->error = info->error;
  elem->prev = NULL;
  if (l->first != NULL)
    l->first->prev = elem;
  else
    l->last = elem;
  l->first = elem;
}

void		get_tetri(t_all *all)
{
  DIR 		*dir_info;
  struct dirent	*file_info;
  t_t_info	*info;
  unsigned int  nb;

  nb = 0;
  dir_info = opendir("tetriminos");
  if (dir_info == NULL)
    exit(84);
  file_info = readdir(dir_info);
  file_info = readdir(dir_info);
  start_list(&all->list_tetri);
  while ((file_info = readdir(dir_info)))
    {
      info = malloc(sizeof(t_t_info));
      get_tetrimino_data(file_info->d_name, info);
      make_top(&all->list_tetri, info, nb);
      free(info);
      nb++;
    }
  if (!all->list_tetri.first && !all->list_tetri.last)
    exit(84);
}
