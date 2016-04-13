/*
** pwd.c for C:\Users\bapti\Documents\OneDrive Entreprise\Epitech\Documents\rendu\PSU_2015_minishell2 in C:\Users\bapti\Documents\OneDrive Entreprise\Epitech\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Tue Mar 22 19:04:48 2016 baptiste mairesse
** Last update Tue Mar 22 19:13:46 2016 baptiste mairesse
*/

#include 	"mysh.h"
#include 	<unistd.h>
#include 	<stdlib.h>
#include 	<stdio.h>

void 		updatepwd(t_mysh *mysh, char *pwd)
{
  char 		*tmp;
  int		ret;

  if (mysh->tab_com[1] && mysh->tab_com[1][0] == '-')
    {
      tmp = src_env(mysh->env, "OLDPWD");
      ret = chdir(tmp);
      free(tmp);
    }
  else if (!mysh->tab_com[1])
    {
      tmp = src_env(mysh->env, "HOME");
      ret = chdir(tmp);
      free(tmp);
    }
  else
    ret = chdir(mysh->tab_com[1]);
  if (ret == -1)
    {
      my_error(mysh->tab_com[1]);
      my_error(": Aucun fichier ou dossier de ce type.\n");
    }
  else
    update_pwd(mysh, pwd);
}
