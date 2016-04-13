/*
** list.c for C:\Users\bapti\Documents\OneDrive Entreprise\Epitech\Documents\rendu\PSU_2015_minishell2 in C:\Users\bapti\Documents\OneDrive Entreprise\Epitech\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Thu Mar 24 10:22:21 2016 baptiste mairesse
** Last update	Sat Apr 02 14:02:17 2016 Baptiste Mairesse
*/

#include 	"mysh.h"
#include 	<stdlib.h>

void 		start_list(t_comctrl *l)
{
  l->first = NULL;
  l->last = NULL;
}

void 		show_list(t_comctrl list)
{
  t_com		*elem;

  elem = list.last;
  while (elem)
    {
      my_printf("debug : %s\n", elem->com);
      elem = elem->prev;
    }
}

int		check_type(char *str)
{
  if (my_strlen(str) > 1 && str[0] == '<' && str[1] == '<')
    return (1);
  else if (my_strlen(str) > 1 && str[0] == '>' && str[1] == '>')
    return (3);
  else if (str[0] == '<')
    return (2);
  else if (str[0] == '>')
    return (4);
  else if (str[0] == '|')
    return (5);
  else
    return (0);
}

void 		 make_top(t_comctrl *l, char *str)
{
  t_com 	*elem;
  int 		i;
  int 		test_empy;

  i = -1;
  test_empy = 0;
  while (++i < my_strlen(str))
    {
      if (str[i] != ' ' && str[i] != '\t')
	test_empy = 1;
    }
  if (test_empy == 0)
    return;
  elem = my_malloc(sizeof(t_com));
  elem->com = my_strdup(str);
  elem->type = check_type(str);
  elem->prev = NULL;
  if (l->first != NULL)
    l->first->prev = elem;
  else
    l->last = elem;
  l->first = elem;
  free(str);
}
