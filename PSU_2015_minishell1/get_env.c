/*
** get_env.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Mon Mar 14 14:30:21 2016 baptiste mairesse
** Last update Wed Mar 16 10:56:20 2016 baptiste mairesse
*/

#include 	"mysh.h"
#include 	<stdlib.h>

char 		**get_env_arg(char **env)
{
  char		**env_tab;
  t_var 	var;
  int		nb_ddtab;

  var.j = 0;
  var.i = -1;
  nb_ddtab = 0;
  while (env[var.j])
    var.j++;
  if (!env)
    exit (84);
  env_tab = my_malloc(sizeof(char *) * (var.j + 1));
  while (env[++var.i])
    env_tab[var.i] = my_strdup(env[var.i]);
  env_tab[var.i] = NULL;
  return (env_tab);
}
