/*
** exe_sub_command.c for C:\Users\bapti\Documents\OneDrive Entreprise\Epitech\Documents\rendu\PSU_2015_minishell2 in C:\Users\bapti\Documents\OneDrive Entreprise\Epitech\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Thu Mar 24 15:30:17 2016 baptiste mairesse
** Last update	Tue Apr 12 23:14:43 2016 Baptiste Mairesse
*/
#include 	"mysh.h"
#include 	<stdlib.h>
#include 	<sys/types.h>
#include 	<unistd.h>
#include 	<sys/wait.h>

void		check_ret_sig(int sig, int *ret_val)
{
  if (WIFSIGNALED(sig))
    {
      if (WTERMSIG(sig))
	{
	  if (sig == 11)
	    {
	      my_putstr("Segmentation fault\n");
	      *ret_val = 139;
	    }
	}
      #ifdef WCOREDUMP
      if (WCOREDUMP(sig))
	{
	  my_putstr("Segmentation fault (core dumped)\n");
	  *ret_val = 139;
	}
      #endif
  }
}

int		test_redir(t_comctrl *list)
{
  t_com 	*elem;
  int		type;
  int		type_tmp;

  type_tmp = 0;
  type = 0;
  if (list->first == NULL && list->last == NULL)
    return (0);
  elem = list->last;
  while (elem != NULL)
    {
      if (elem->com[0] == '<' || elem->com[0] == '>' || elem->com[0] == '|')
	type = 1;
      else
	type = 2;
      if ((type_tmp == 0 && type == 1) || (type == 1 && type_tmp == 1))
	return (-1);
      type_tmp = type;
      elem = elem->prev;
    }
  if (type == 1)
    return (-1);
  return (1);
}

int		one_command(t_comctrl *list)
{
  t_com		*elem;
  int		nb;

  nb = 0;
  if (list->first == NULL && list->last == NULL)
    return (-1);
  elem = list->last;
  while (elem != NULL)
    {
      nb++;
      elem = elem->prev;
    }
  return (nb);
}

void		exec_one_command(t_mysh *mysh)
{
  pid_t		pid;
  int 		sig;

  mysh->tab_com = get_command(mysh->tab_sel_ctrl.last->com);
  pid = fork();
  if (pid == 0)
    exec_command(mysh);
  waitpid(0, &sig, WUNTRACED);
  check_ret_sig(sig, &mysh->ret_val);
  my_builtins(mysh);
  free_tab(mysh->tab_com);
}

void		exec_sub_command(t_mysh *mysh)
{
  int 		ret;

  ret = test_redir(&mysh->tab_sel_ctrl);
  if (ret == 1)
    {
      if (one_command(&mysh->tab_sel_ctrl) == 1)
	exec_one_command(mysh);
      else
	redir_multi_com(mysh);
    }
  else if (ret == -1)
    my_putstr("error pipe\n");
  free_list(&mysh->tab_sel_ctrl);
}
