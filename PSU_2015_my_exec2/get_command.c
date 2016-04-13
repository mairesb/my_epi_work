/*
** get_command.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Tue Mar 15 11:37:56 2016 baptiste mairesse
** Last update Thu Mar 17 11:03:27 2016 baptiste mairesse
*/

#include 	"my_exec2.h"
#include 	<stdlib.h>

char		**make_to_tab_command(char *str, int nb_command)
{
  char		**tab;
  t_var		var;

  var.i = -1;
  tab = my_malloc(sizeof(char * ) * (nb_command + 1));
  var.k = 0;
  var.j = -1;
  tab[nb_command] = NULL;
  while (++var.i < my_strlen(str))
    {
      if (str[var.i] != ' ' && str[var.i] != '\t')
	{
	  var.k = var.i;
	  while (str[var.i] != ' ' && str[var.i] != '\t' && str[var.i] != '\0')
	    var.i++;
	  tab[++var.j] = my_malloc(sizeof(char) * (var.i + 1));
	  if (!tab[var.j])
	    exit(84);
          var.l = -1;
	  while (var.k != var.i)
	    tab[var.j][++var.l] = str[var.k++];
	  tab[var.j][var.l + 1] = '\0';
	}
    }
  return (tab);
}

char		**get_command(char *str)
{
  t_var		var;

  var.i = 0;
  var.j = 0;
  while (str[var.i])
    {
      if (str[var.i] != ' ' && str[var.i] != '\t')
	{
	  var.j++;
	  while (str[var.i] != ' ' && str[var.i] != '\t' && str[var.i] != '\0')
	    var.i++;
	}
      if (var.i < my_strlen(str))
	var.i++;
    }
  return (make_to_tab_command(str, var.j));
}
