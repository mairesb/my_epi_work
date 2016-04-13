/*
** my_strlen.c for my_strlen in /home/maires_b/rendu/Piscine_C_J04/Piscine_C_J04
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Thu Oct  1 13:44:44 2015 Baptiste Mairesse
** Last update Thu Oct  1 13:44:47 2015 Baptiste Mairesse
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i++;
  return (i);
}