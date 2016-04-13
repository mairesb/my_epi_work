/*
** multi_comand.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by	Baptiste Mairesse
** Login	maires_b
**
** Started on	Sat Apr 02 13:32:01 2016 Baptiste Mairesse
** Last update	Tue Apr 12 15:49:17 2016 Baptiste Mairesse
*/

#include 	"mysh.h"
#include 	<unistd.h>
#include 	<sys/types.h>
#include	<stdlib.h>
#include 	<sys/types.h>
#include 	<sys/stat.h>
#include 	<fcntl.h>
#include	<wait.h>

void 		clean_mem(t_mysh *mysh)
{
  int 		ret;

  ret = mysh->ret_val;
  free_list(&mysh->tab_sel_ctrl);
  free_command(mysh);
  free_struct(mysh);
  exit(ret);
}

void		exec_multi_command(t_mysh *mysh, char *com)
{
  if (com)
    {
      mysh->tab_com = get_command(com);
      if (comp_str(com, "<<") || comp_str(com, ">>") || comp_str(com, "<")
	  || comp_str(com, ">") || comp_str(com, "|"))
	{
	  my_putstr("Ambiguous output redirect.\n");
	  clean_mem(mysh);
	  exit(42);
	}
      my_builtins(mysh);
      exec_command(mysh);
    }
  else
    clean_mem(mysh);
}

void		my_waitpid(int param, int *ret_val)
{
  int 		sig;
  if (param == 0)
    waitpid(0, &sig, WNOHANG);
  if (param == 1)
    waitpid(0, &sig, WUNTRACED);
  check_ret_sig(sig, ret_val);
}

void 		forker(int fd_sauvg, int fd, t_mysh *mysh, t_com *elem)
{
  pid_t 	pid;

  if ((pid = fork()) == -1)
    exit(84);
  if (pid == 0)
    {
      if (fd != 1)
	{
	  dup2(fd, 1);
	  close(fd);
	}
      if (fd_sauvg != 0)
	{
	  dup2(fd_sauvg, 0);
	  close(fd_sauvg);
	}
      if (elem->prev->type != 1 && elem->prev->type != 2)
	exec_multi_command(mysh, elem->com);
      else
	clean_mem(mysh);
      clean_mem(mysh);
    }
  else
    my_waitpid(0, &mysh->ret_val);
}

void		redir_multi_com(t_mysh *mysh)
{
  t_com		*elem;
  int     	fd[2];
  int		fd_sauvg;
  pid_t		pid;

  elem = mysh->tab_sel_ctrl.last;
  fd_sauvg = 0;
  pid = fork();
  if (pid == 0)
    {
      while (elem && elem->prev)
	{
	  pipe(fd);
	  forker(fd_sauvg, fd[1], mysh, elem);
	  elem = do_redir(elem, fd, mysh);
          close(fd[1]);
          fd_sauvg = fd[0];
	}
      if (fd_sauvg != 0)
	dup2(fd_sauvg, 0);
      exec_multi_command(mysh, (elem) ? elem->com : NULL);
  }
  else
    my_waitpid(1, &mysh->ret_val);
}
