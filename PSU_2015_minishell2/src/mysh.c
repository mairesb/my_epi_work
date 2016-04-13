/*
** mysh.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Mon Mar 14 14:19:57 2016 baptiste mairesse
** Last update	Tue Apr 12 15:50:46 2016 Baptiste Mairesse
*/

#include 	"mysh.h"
#include 	<stdlib.h>
#include 	<signal.h>
#include 	<sys/types.h>
#include 	<unistd.h>
#include 	<sys/wait.h>

int 		toto = 0;

int 		non_exec_command(t_mysh *mysh)
{
  if (comp_str(mysh->tab_com[0], "cd") == 1)
    return (0);
  else if (comp_str(mysh->tab_com[0], "setenv") == 1)
    return (0);
  else if (comp_str(mysh->tab_com[0], "unsetenv") == 1)
    return (0);
  else
    return (1);
}

void 		exec_command(t_mysh *mysh)
{
  int 		exe_test;
  int 		i;

  exe_test = 0;
  i = -1;
  if (comp_str(mysh->tab_com[0], "exit") != 1)
    {
      signal(SIGINT, ctrl_c_f);
      if (comp_str(mysh->tab_com[0], "env") == 1)
	{
	  while (++i < my_strlen_tab(mysh->env))
	    my_printf("%s\n", mysh->env[i]);
	}
      else if (non_exec_command(mysh) == 1)
	{
	  exe_test = my_exe(mysh);
	  if (exe_test == -1)
	    my_error(mysh->tab_com[0]);
	  if (exe_test == -1)
	    my_error(": Command not found.\n");
	}
    }
  clean_mem(mysh);
}

void		prompt(t_mysh *mysh)
{
  while (42)
    {
      signal(SIGINT, ctrl_c_p);
      mysh->command = get_next_line(0);
      if (toto == 0 && mysh->command == 0)
	return;
      toto = 0;
      if (mysh->command && mysh->command[0] && comp_str(mysh->command, "\n")
	  == 0)
	{
	  parse_command(mysh);
	  free_command(mysh);
	}
      if (aff_prompt() == 1)
	my_putstr("$>");
    }
}

int 		main(int argc, char const *argv[], char **env)
{
  t_mysh 	*mysh;
  int		ret;

  mysh = my_malloc(sizeof(t_mysh));
  (void)argv;
  argc++;
  if (!mysh)
    exit (84);
  mysh->ret_val = 0;
  mysh->env = get_env_arg(env);
  mysh->path = get_path(env);
  if (aff_prompt() == 1)
    my_putstr("$>");
  prompt(mysh);
  if (aff_prompt() == 1)
    my_putstr("\nexit\n");
  ret = mysh->ret_val;
  free_struct(mysh);
  return (ret);
}
