/*
** unset_env.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2 in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Wed Mar 16 11:31:37 2016 baptiste mairesse
** Last update Wed Mar 16 12:17:57 2016 baptiste mairesse
*/

#include 	"mysh.h"
#include 	<stdlib.h>

int 		where_in_env(char **env, char *name)
{
  int 		i;

  i = 0;
  while (env[i] && src_str(env[i], name) != 1)
    i++;
  return (i);
}

void		del_env(t_mysh *mysh, int line_del)
{
  char		**env_tmp;
  t_var		var;

  var.i = 0;
  env_tmp = get_env_arg(mysh->env);
  while (mysh->env[var.i])
    var.i++;
  var.j = var.i;
  var.k = -1;
  while (var.j >= 0)
    free(mysh->env[var.j--]);
  free(mysh->env);
  mysh->env = my_malloc(sizeof(char *) * (var.i));
  while (++var.k < var.i)
    {
      if (var.k != where_in_env(env_tmp, mysh->tab_com[line_del]))
	mysh->env[++var.j] = my_strdup(env_tmp[var.k]);
    }
  mysh->env[var.i - 1] = NULL;
  while (--var.i >= 0)
    free(env_tmp[var.i]);
  free(env_tmp);
}

void		my_unset_env(t_mysh *mysh)
{
  char 		*env_or_not;
  int 		i;
  int 		j;

  i = 0;
  while (mysh->tab_com[i])
    i++;
  if (comp_str(mysh->tab_com[0], "unsetenv") == 1 && mysh->tab_com[1] && i > 1)
    {
      j = 0;
      while (++j < i)
	{
	  if ((env_or_not = src_env(mysh->env, mysh->tab_com[j])))
	    del_env(mysh, j);
	  if (env_or_not)
	    free (env_or_not);
	}
    }
  else if (comp_str(mysh->tab_com[0], "unsetenv") == 1 && i == 1)
    my_error("unsetenv: Too many arguments.\n");
}
