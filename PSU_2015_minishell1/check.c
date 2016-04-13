/*
** check.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Tue Mar 15 15:52:50 2016 baptiste mairesse
** Last update Wed Mar 16 13:35:33 2016 baptiste mairesse
*/

#include 	"mysh.h"
#include        <stdlib.h>

char 		*my_strcat_free(char *s1, char *s2)
{
  s1 = my_strcat(s1, s2);
  free(s2);
  return (s1);
}

int 		check_str(char *str)
{
  int 		i;
  int 		j;
  int 		nb;

  j = 0;
  i = 0;
  while (str[i])
    i++;
  while (j < i)
    {
      if (str[j] < '0' || str[j] > '9')
	return (0);
      j++;
    }
  nb = my_getnbr(str);
  if (nb > 255 || nb < 0)
    nb = 0;
  return (nb);
}
