/*
** flag.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 15:16:59 2016 baptiste mairesse
** Last update Thu Feb 25 23:15:14 2016 baptiste mairesse
*/

#include 	"tetris.h"

int 		check_arg(t_all *all, const char *av[], int *i)
{
  if (my_strcmp(av[*i], "--help") == 0)
    all->param.help = '1';
  else if (my_strcmp(av[*i], "-kl") == 0)
    all->param.left = my_strcopy(all->param.left, av[++(*i)]);
  else if (my_strcmp(av[*i], "-kr") == 0)
    all->param.right = my_strcopy(all->param.right, av[++(*i)]);
  else if (my_strcmp(av[*i], "-kt") == 0)
    all->param.turn = my_strcopy(all->param.turn, av[++(*i)]);
  else if (my_strcmp(av[*i], "-kd") == 0)
    all->param.drop = my_strcopy(all->param.drop, av[++(*i)]);
  else if (my_strcmp(av[*i], "-kq") == 0)
    all->param.quit = my_strcopy(all->param.quit, av[++(*i)]);
  else if (my_strcmp(av[*i], "-kp") == 0)
    all->param.pause = my_strcopy(all->param.pause, av[++(*i)]);
  else if (my_strcmp(av[*i], "-w") == 0)
    all->param.next = 1;
  else if (my_strcmp(av[*i], "-d") == 0)
    all->param.debug = 1;
  else if (my_strcmp(av[*i], "-l") == 0)
    all->param.level = my_getnbr(av[++(*i)]);
  else
    return (-1);
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
	  my_printf("What is this parameter %s ??", av[i]);
	  return (-1);
	}
    }
  return (0);
}
