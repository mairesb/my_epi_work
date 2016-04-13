/*
** my_str_isnum.c for my_str_isnum in /home/maires_b/rendu/Piscine_C_J06/Piscine_C_J06/ex_12
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Mon Oct  5 19:20:58 2015 Baptiste Mairesse
** Last update Mon Oct  5 19:20:59 2015 Baptiste Mairesse
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 48 || str[i] > 57)
	return (0);
      i++;
    }
  return (1);
}