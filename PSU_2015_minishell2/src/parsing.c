/*
** parsing.c for C:\Users\bapti\Documents\OneDrive Entreprise\Epitech\Documents\rendu\PSU_2015_minishell2 in C:\Users\bapti\Documents\OneDrive Entreprise\Epitech\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Wed Mar 23 19:38:12 2016 baptiste mairesse
** Last update	Tue Apr 12 15:51:45 2016 Baptiste Mairesse
*/

#include 	"mysh.h"
#include 	<stdlib.h>

int		com_len(char *str, int i)
{
  int		len;
  int		j;

  j = i;
  len = 0;
  while (str[i] && str[i] != '<' && str[i] != '>' && str[i] != '|')
    {
      if (i != 0 && str[i - 1] != '\\' && str[i] == '"')
	{
	  while (str[++i] && i != 0 && str[i - 1] != '\\' && str[i] != '"')
	    i++;
	}
      i = (str[i]) ? i + 1 : i;
    }
  len = (i - j - 1 >= 0) ? i - j - 1 : 0;
  if (i == j)
    {
     if (str[i] == '<')
	len = (str[i + 1] && str[i + 1] == '<') ? 1 : 0;
      else if (str[i] == '>')
	len = (str[i + 1] && str[i + 1] == '>') ? 1 : 0;
      else if (str[i] == '|')
	len = 0;
    }
  return (len);
}

void		cut_command(t_mysh *mysh)
{
  t_var		var;
  char		*token;

  var.i = 0;
  start_list(&mysh->tab_sel_ctrl);
  while (var.i <= my_strlen(mysh->command_sel))
    {
      var.j = com_len(mysh->command_sel, var.i);
      token = my_strdub_n_to_n(mysh->command_sel, var.i, var.j + var.i);
      var.i += var.j  + 1;
      make_top(&mysh->tab_sel_ctrl, token);
    }
  if (token)
    free(token);
}

void		quote_pars(char *str, int *i)
{
  char		*tmp;
  int		j;
  int		have_quote;

  (*i)++;
  while (str[*i] && str[*i] != '"' && str[*i - 1] != '\\')
    (*i)++;
  if (!str[*i])
    {
      while ((tmp = get_next_line(0)))
	{
	  j = -1;
	  have_quote = 0;
	  str = my_strcat(str, tmp);
	  *i = my_strlen(str);
	  while (tmp[++j] && have_quote == 0)
	    have_quote = (tmp[j] == '"') ? 1 : 0;
	  free(tmp);
	  if (have_quote == 1)
	    break;
	}
    }
}

void		parse_command(t_mysh *mysh)
{
  t_var		var;

  var.i = -1;
  var.j = 0;
  while (mysh->command[++var.i])
    {
      if (var.i != 0 && mysh->command[var.i] == '"'
	  && mysh->command[var.i - 1] != '\\')
	quote_pars(mysh->command, &var.i);
      if (mysh->command[var.i] == ';' || !mysh->command[var.i + 1])
	{
	  mysh->command_sel = my_strdub_n_to_n(mysh->command, var.j,
					      (!mysh->command[var.i + 1]
					       && mysh->command[var.i] != ';')
					       ? var.i : var.i - 1);
	  cut_command(mysh);
          exec_sub_command(mysh);
	  var.j = var.i + 1;
	}
    }
}
