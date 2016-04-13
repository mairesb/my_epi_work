/*
** flag.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 15:16:59 2016 baptiste mairesse
** Last update Sun Mar 20 23:24:37 2016 baptiste mairesse
*/

#include 	"tetris.h"
#include 	<stdlib.h>

int 		test_str(const char *str, const char *str2)
{
  int 		i;

  i = -1;
  while (str2[++i])
    {
      if (str2[i] != str[i])
	return (-1);
    }
  return (1);
}

char 		*get_str_info(const char *str)
{
  int 		i;
  int 		j;
  char		*key;

  i = 0;
  j = 0;
  key = malloc(sizeof(char) * 5);
  while (str[i] && str[i] != '=')
    i++;
  i++;
  if (!str[i])
    return (NULL);
  if (str[i] && str[i] == '\'')
    i++;
  while (str[i] && str[i] != '\'')
    {
      key[j] = str[i];
      i++;
      j++;
    }
  key[j] = 0;
  return (key);
}

int 		check_arg_second(t_all *all, const char *av[], int *i)
{
  if (test_str(av[*i], "--level=") == 1 || test_str(av[*i], "--map-size=") == 1)
    {
      (*i)++;
      return (0);
    }
  else if (test_str(av[*i], "--key-left=") == 1)
    all->param.left = get_str_info(av[*i]);
  else if (test_str(av[*i], "--key-right=") == 1)
    all->param.right = get_str_info(av[*i]);
  else if (test_str(av[*i], "--key-turn=") == 1)
    all->param.turn = get_str_info(av[*i]);
  else if (test_str(av[*i], "--key-quit=") == 1)
    all->param.quit = get_str_info(av[*i]);
  else if (test_str(av[*i], "--key-pause=") == 1)
    all->param.pause = get_str_info(av[*i]);
  else if (test_str(av[*i], "--key-drop=") == 1)
    all->param.drop = get_str_info(av[*i]);
  else
    return (-1);
  (*i)++;
  if (!all->param.drop || !all->param.left || !all->param.right ||
      !all->param.turn || !all->param.quit || !all->param.pause)
    return (-1);
  return (0);
}

int 		check_arg(t_all *all, const char *av[], int *i)
{
  if (my_strcmp(av[*i], "--help") == 0)
    all->param.help = '1';
  else if (my_strcmp(av[*i], "-kl") == 0 && av[*i + 1])
    all->param.left = my_strcopy(all->param.left, av[++(*i)]);
  else if (my_strcmp(av[*i], "-kr") == 0 && av[*i + 1])
    all->param.right = my_strcopy(all->param.right, av[++(*i)]);
  else if (my_strcmp(av[*i], "-kt") == 0 && av[*i + 1])
    all->param.turn = my_strcopy(all->param.turn, av[++(*i)]);
  else if (my_strcmp(av[*i], "-kd") == 0 && av[*i + 1])
    all->param.drop = my_strcopy(all->param.drop, av[++(*i)]);
  else if (my_strcmp(av[*i], "-kq") == 0 && av[*i + 1])
    all->param.quit = my_strcopy(all->param.quit, av[++(*i)]);
  else if (my_strcmp(av[*i], "-kp") == 0 && av[*i + 1])
    all->param.pause = my_strcopy(all->param.pause, av[++(*i)]);
  else if (my_strcmp(av[*i], "-w") == 0 || my_strcmp(av[*i], "--without-next")
	   == 0)
    all->param.next = 1;
  else if (my_strcmp(av[*i], "-d") == 0 || my_strcmp(av[*i], "-debug") == 0)
    all->param.debug = 1;
  else if (my_strcmp(av[*i], "-l") == 0)
    all->param.level = my_getnbr(av[++(*i)]);
  else
    return (check_arg_second(all, av, i));
  (*i)++;
  return (0);
}

int		parse_arg(t_all *all, int ac, const char *av[])
{
  int 		i;

  i = 1;
  (void)ac;
  (void)all;
  while (i < ac)
    {
      if (check_arg(all, av, &i) == -1)
	{
	  return (-1);
	}
    }
  return (0);
}
