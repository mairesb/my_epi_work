/*
** my_str_isalpha.c for my_str_isalpha in /home/maires_b/rendu/Piscine_C_J06/Piscine_C_J06/ex_11
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Mon Oct  5 18:52:39 2015 Baptiste Mairesse
** Last update Mon Oct  5 18:52:40 2015 Baptiste Mairesse
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 65 || str[i] > 90 && str[i] < 97 || str[i] > 122)
	return (0);
      i++;
    }
  return (1);
}