/*
** builtins.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Tue Mar 15 11:30:46 2016 baptiste mairesse
** Last update	Tue Apr 12 14:49:37 2016 Baptiste Mairesse
*/

#include 	"mysh.h"
#include 	<unistd.h>
#include 	<stdlib.h>
#include 	<stdio.h>

void		add_env_pwd(t_mysh *mysh, char *str)
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
  mysh->env[var.j] = my_strdup(str);
  mysh->env[var.j + 1] = NULL;
  while (--var.i >= 0)
    free(env_tmp[var.i]);
  free(env_tmp);
}

void		update_env_pwd(t_mysh *mysh, char *str)
{
  int 		i;

  i = 0;
  while (src_str(mysh->env[i], str) != 1)
    i++;
  free(mysh->env[i]);
  mysh->env[i] = my_strdup(str);
}

void 		update_pwd(t_mysh *mysh, char *pwd)
{
  char 		*param_in_env;
  char		*tmp;

  tmp = my_strdup("PWD=");
  tmp = my_strcat_free(tmp, getcwd(NULL, 1000));
  if ((param_in_env = src_env(mysh->env, pwd)))
    update_env_pwd(mysh, pwd);
  else
    add_env_pwd(mysh, pwd);
  if (param_in_env)
    free (param_in_env);
  if ((param_in_env = src_env(mysh->env, tmp)))
    update_env_pwd(mysh, tmp);
  else
    add_env_pwd(mysh, tmp);
  if (param_in_env)
    free (param_in_env);
  free(tmp);
}

void 		my_cd(t_mysh *mysh)
{
  char 		*pwd;

  pwd = my_strdup("OLDPWD=");
  pwd = my_strcat_free(pwd, getcwd(NULL, 1000));
  if (comp_str(mysh->tab_com[0], "cd") == 1)
    updatepwd(mysh, pwd);
  free (pwd);
}

void 		my_exit(t_mysh *mysh)
{
  int 		exite;

  exite = (mysh->tab_com[1]) ? check_str(mysh->tab_com[1]) : 0;
  if (comp_str(mysh->tab_com[0], "exit") == 1)
    {
      if (aff_prompt() == 1)
	my_putstr("exit\n");
      free_list(&mysh->tab_sel_ctrl);
      free_tab(mysh->tab_com);
      free_command(mysh);
      free_struct(mysh);
      exit(exite);
    }
}
