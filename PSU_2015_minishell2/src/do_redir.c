/*
** do_redir.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by	Baptiste Mairesse
** Login	maires_b
**
** Started on	Sun Apr 03 12:46:54 2016 Baptiste Mairesse
** Last update	Thu Apr 07 20:03:10 2016 Baptiste Mairesse
*/

#include 	"mysh.h"
#include 	<unistd.h>
#include 	<sys/types.h>
#include	<stdlib.h>
#include 	<sys/types.h>
#include 	<sys/stat.h>
#include 	<fcntl.h>

void 		put_in_stdout(char *com, int fd[2], int type)
{
  char 		*buf;
  char		**tab;
  int		file;

  tab = get_command(com);
  my_close(fd[1]);
  if (type == 3)
    file = open(tab[0], O_WRONLY | O_APPEND | O_CREAT, 0644);
  else
    file = open(tab[0], O_WRONLY | O_CREAT | O_TRUNC, 0644);
  if (file == -1)
    {
      my_putstr("Error open file\n");
      return;
    }
  while ((buf = get_next_line(fd[0])))
    {
      my_write(file, buf, my_strlen(buf));
      my_write(file, "\n", 1);
      free(buf);
    }
  free_tab(tab);
  my_close(file);
}

void		put_in_stdin(char *com, int fd, t_com *elem)
{
  char		**tab;
  char		*tmp;
  int		file;

  tab = get_command(com);
  tmp = my_strdup(elem->com);
  free(elem->com);
  elem->com = my_strdup(elem->prev->prev->com);
  free(elem->prev->prev->com);
  elem->prev->prev->com = my_strdup(tmp);
  free(tmp);
  file = open(tab[0], O_RDONLY, 0644);
  if (file == -1)
    my_putstr("Error open file\n");
  if (file == -1)
    elem->prev = NULL;
  if (file == -1)
    return;
  while ((tmp = get_next_line(file)))
    {
      my_write(fd, tmp, my_strlen(tmp));
      my_write(fd, "\n", 1);
      free(tmp);
    }
  free_tab(tab);
}

void		put_in_stdin_dd_redir_left(char *com, int fd, t_com *elem)
{
  char		**tab;
  char		*tmp;

  tab = get_command(com);
  my_putstr("? ");
  while ((tmp = get_next_line(0)) && comp_str(tmp, tab[0]) == 0)
    {
      my_write(fd, tmp, my_strlen(tmp));
      my_write(fd, "\n", 1);
      free(tmp);
      my_putstr("? ");
    }
  free_tab(tab);
  tmp = my_strdup(elem->com);
  free(elem->com);
  elem->com = my_strdup(elem->prev->prev->com);
  free(elem->prev->prev->com);
  elem->prev->prev->com = my_strdup(tmp);
  free(tmp);
}

t_com		*do_redir(t_com *elem, int fd[2], t_mysh *mysh)
{
  (void)mysh;
  if (elem->prev->type == 4 || elem->prev->type == 3)
    {
      put_in_stdout(elem->prev->prev->com, fd, elem->prev->type);
      if (elem && elem->prev && elem->prev->prev && elem->prev->prev->prev)
	elem = elem->prev->prev->prev;
      else
	elem = NULL;
    }
  else if (elem->prev->type == 1 || elem->prev->type == 2)
    {
      if (elem->prev->type == 2)
	put_in_stdin(elem->prev->prev->com, fd[1], elem);
      else
	put_in_stdin_dd_redir_left(elem->prev->prev->com, fd[1], elem);
      if (elem && elem->prev && elem->prev->prev)
	elem = elem->prev->prev;
      else
	elem = NULL;
    }
  else if (elem && elem->prev && elem->prev->prev)
    elem = elem->prev->prev;
  else
    elem = NULL;
  return (elem);
}
