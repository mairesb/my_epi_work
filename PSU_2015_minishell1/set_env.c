/*
** set_env.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2 in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Wed Mar 16 10:16:31 2016 baptiste mairesse
** Last update Wed Mar 16 11:40:59 2016 baptiste mairesse
*/

#include 	"mysh.h"
#include 	<stdlib.h>

void		add_env(t_mysh *mysh)
{
  char		**env_tmp;
 t_var		var;

  var.i = 0;
  env_tmp = get_env_arg(mysh->env);
  while (mysh->env[var.i])
    var.i++;
  var.j = var.i;
  while (var.j >= 0)
    free(mysh->env[var.j--]);
  free(mysh->env);
  mysh->env = my_malloc(sizeof(char *) * (var.i + 2));
  while (++var.j < var.i)
    mysh->env[var.j] = my_strdup(env_tmp[var.j]);
  mysh->env[var.j] = my_strdup(mysh->tab_com[1]);
  mysh->env[var.j] = my_strcat(mysh->env[var.j], "=");
  if (mysh->tab_com[2])
    mysh->env[var.j] = my_strcat(mysh->env[var.j], mysh->tab_com[2]);
  mysh->env[var.j + 1] = NULL;
  while (--var.i >= 0)
    free(env_tmp[var.i]);
  free(env_tmp);
}

void		update_env(t_mysh *mysh)
{
  int 		i;

  i = 0;
  while (src_str(mysh->env[i], mysh->tab_com[1]) != 1)
    i++;
  free(mysh->env[i]);
  mysh->env[i] = my_strdup(mysh->tab_com[1]);
  mysh->env[i] = my_strcat(mysh->env[i], "=");
  if (mysh->tab_com[2])
    mysh->env[i] = my_strcat(mysh->env[i], mysh->tab_com[2]);
}

void 		my_set_env(t_mysh *mysh)
{
  char 		*param_in_env;
  int 		i;

  i = 0;
  while (mysh->tab_com[i])
    i++;
  if (comp_str(mysh->tab_com[0], "setenv") == 1 && mysh->tab_com[1] && i < 4)
    {
      if ((param_in_env = src_env(mysh->env, mysh->tab_com[1])))
	update_env(mysh);
      else
	add_env(mysh);
      if (param_in_env)
	free (param_in_env);
    }
  else if (comp_str(mysh->tab_com[0], "setenv") == 1 && i == 1)
    {
      i = -1;
      while (mysh->env && mysh->env[++i])
	my_printf("%s\n", mysh->env[i]);
    }
  else if (comp_str(mysh->tab_com[0], "setenv") == 1 && i >= 4)
    my_error("setenv: Too many arguments.\n");
}
