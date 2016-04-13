/*
** my_strdup.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu\Piscine_C_workshoplib\Piscine_C_workshoplib\lib\my in C:\Users\bapti\Documents\OneDrive\Documents\rendu\Piscine_C_workshoplib\Piscine_C_workshoplib\lib\my
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Wed Mar 16 09:49:50 2016 baptiste mairesse
** Last update Wed Mar 16 09:50:43 2016 baptiste mairesse
*/

#include <stdlib.h>

char    *my_strdup(char *str)
{
  char	*s;
  int	i;

  if ((s = my_malloc(sizeof(char) * (my_strlen(str) + 1))) == 0)
    {
      return (0);
    }
  i = -1;
  while (str[++i])
    s[i] = str[i];
  s[i] = '\0';
  return (s);
}
