/*
** get_path.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Tue Mar 15 08:55:42 2016 baptiste mairesse
** Last update	Thu Apr 07 09:30:20 2016 Baptiste Mairesse
*/

#include 	"mysh.h"
#include 	<stdlib.h>

int		src_point(char *path, int i)
{
  int		leng;

  leng = 0;
  i--;
  while (path[++i] != ':' && path[i])
      leng++;
  return (leng);
}

char		*put_path_elem(t_var *var, char *path_line)
{
  char		*path_elem;
  int 		i;
  int		tmp;

  tmp = (var->j == -1) ? var->j : var->j - 1;
  i = 0;
  while (path_line[++var->j] != '\0' && path_line[var->j] != ':')
      i++;
  path_elem = my_malloc(sizeof(char) * (i + 3));
  i = -1;
  while (++tmp != var->j)
    path_elem[++i] = path_line[tmp];
  path_elem[i + 1] = '/';
  path_elem[i + 2] = '\0';
  if (path_line[var->j] == ':')
    var->j++;
  return (path_elem);
}

int 		nb_path(char *line)
{
  int 		nb_line;
  int 		i;

  i = -1;
  nb_line = 0;
  if (!line)
    return (0);
  while (line[++i])
    {
      if (line[i] == ':' || line[i + 1] == '\0')
	nb_line++;
    }
  return (nb_line);
}

char		**get_path(char **env)
{
  t_var var;
  char		**path;
  char		*path_line;

  var.i = 0;
  var.j = -1;
  var.k = 0;
  var.l = 0;
  if (!env[0])
    return (NULL);
  if (!(path_line = src_env(env, "PATH")))
      free(path_line);
  path = my_malloc(sizeof(char *) * (nb_path(path_line) + 2));
  while (path_line && (var.j == -1 || path_line[var.j] != '\0'))
    {
      path[var.k] = put_path_elem(&var, path_line);
      var.k++;
    }
  path[var.k] = NULL;
  free(path_line);
  return (path);
}
