/*
** my_str_islower.c for my_str_islower in /home/maires_b/rendu/Piscine_C_J06/Piscine_C_J06/ex_13
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Mon Oct  5 20:09:36 2015 Baptiste Mairesse
** Last update Mon Oct  5 20:09:38 2015 Baptiste Mairesse
*/

int	my_str_islower(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] < 97 || str[i] > 122)
	return (0);
      i++;
    }
  return (1);
}