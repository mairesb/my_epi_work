/*
** get_env.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Mon Mar 14 14:30:21 2016 baptiste mairesse
** Last update	Tue Apr 12 15:21:01 2016 Baptiste Mairesse
*/

#include 	"mysh.h"
#include 	<stdlib.h>

char 		**get_env_arg(char **env)
{
  char		**env_tab;
  t_var 	var;

  var.j = -1;
  var.j = 0;
  while (env[0] && env[var.j])
    var.j++;
  env_tab = my_malloc(sizeof(char *) * (var.j + 1));
  var.i = 0;
  while (env[0] && env[var.i])
    {
      env_tab[var.i] = my_strdup(env[var.i]);
      var.i++;
    }
  env_tab[var.i] = NULL;
  return (env_tab);
}
