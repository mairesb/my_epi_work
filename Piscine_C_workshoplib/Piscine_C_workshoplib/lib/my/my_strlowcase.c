/*
** my_strlowcase.c for my_strcase in /home/maires_b/rendu/Piscine_C_J06/Piscine_C_J06/ex_09
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Mon Oct  5 18:15:51 2015 Baptiste Mairesse
** Last update Mon Oct  5 18:15:53 2015 Baptiste Mairesse
*/

char	*my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {

      if (str[i] == ' ')
	i++;
      else if (str[i] <= 90 && str[i] >= 65)
	str[i] = (str[i] + 32);
      else
	i++;
    }
  return (str);
}