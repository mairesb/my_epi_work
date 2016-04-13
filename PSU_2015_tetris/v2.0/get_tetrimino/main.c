/*
** main.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_bstetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 10:27:17 2016 baptiste mairesse
** Last update Mon Feb 29 17:52:21 2016 baptiste mairesse
*/

#include 	<sys/types.h>
#include 	<sys/stat.h>
#include 	<fcntl.h>
#include 	<stdlib.h>
#include 	"main.h"

int 		check_str(char *str)
{
  int 		i;
  int 		nb_nbr;

  i = 0;
  nb_nbr = 0;
  while (str[i])
    {
      if ((str[i] < '0' || str[i] > '9') && str[i] != ' ')
	{
	 my_putstr("Bad format\n");
	  return (-1);
	}
      else if (str[i] >= '0' && str[i] <= '9')
	{
	  nb_nbr++;
	  while ((str[i] >= '0' && str[i] <= '9') && str[i])
	    i++;
	}
      if (str[i])
	i++;
    }
  if (nb_nbr != 3)
    return (-1);
  return (0);
}

int 		update_str(char *str)
{
  int 		i;
int 		i_tmp;

  i = 0;
  while (str[i] == ' ' && str[i])
    i++;
  i_tmp = i;
  while (str[i] != ' ' && str[i])
    str[i++] = ' ';
  if (i - i_tmp > 5)
    return (-1);
  return (0);
}

void		aff_info(char *str, int param, t_t_info *info)
{
  int 		ret;

  ret = 0;
  if (param == 0)
    {
      if (check_str(str) == -1)
	info->error = '1';
      if (info->error == '1')
	return ;
      info->width = my_getnbr(str);
      ret += update_str(str);
      info->height = my_getnbr(str);
      ret += update_str(str);
      info->color = my_getnbr(str);
      ret += update_str(str);
      if (ret < 0)
	{
	  info->error = '1';
	  return ;
	}
      info->tetri = malloc(sizeof(char *) * (info->height + 1));
      info->tetri[info->height] = NULL;
    }
  else
    make_to_tab(str, info, param);
}

t_t_info	get_tetrimino_data(const char *file)
{
  int 		fd;
  int 		i;
  char		*str;
  t_t_info	info;

  i = 0;
  info.error = '0';
  str = my_strdup("tetriminos/");
  str = my_strcat(str, file);
  fd = open(str, O_RDONLY);
  my_printf("%s\n", str);
  info.name = get_name(file, &info);
  if (fd == -1 || info.name == NULL)
    {
      my_putstr("file don't exit\n");
      info.error = '1';
      return (info);
    }
  while ((str = get_next_line(fd)))
    {
      aff_info(str, i++, &info);
      free(str);
    }
  return(info);
}
