/*
** my_str_isupper.c for my_str_isupper in /home/maires_b/rendu/Piscine_C_J06/Piscine_C_J06/ex_14
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Mon Oct  5 20:11:19 2015 Baptiste Mairesse
** Last update Mon Oct  5 20:11:20 2015 Baptiste Mairesse
*/

int	my_str_isupper(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 65 || str[i] > 90)
	return (0);
      i++;
    }
  return (1);
}