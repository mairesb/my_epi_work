/*
** fctn_prompt.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Tue Mar 15 09:51:08 2016 baptiste mairesse
** Last update Wed Mar 16 11:49:36 2016 baptiste mairesse
*/

#include 	"mysh.h"
#include 	<sys/types.h>
#include 	<sys/stat.h>
#include 	<unistd.h>
#include 	<stdlib.h>

int 		toto;

void 		my_error(char *str)
{
  write(2, str, my_strlen(str));
}

void 		ctrl_c_f()
{
  exit(0);
}

void 		ctrl_c_p()
{
  toto = 1;
  my_putchar('\n');
}

int 		aff_prompt()
{
  struct stat 	buf;

  fstat(0, &buf);
  if (S_ISCHR(buf.st_mode))
    return (1);
  else
    return (-1);
}

void my_builtins(t_mysh *mysh)
{
  my_exit(mysh);
  my_cd(mysh);
  my_set_env(mysh);
  my_unset_env(mysh);
}
