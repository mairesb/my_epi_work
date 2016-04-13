/*
** my_strupcase.c for my_strupcase in /home/maires_b/rendu/Piscine_C_J06/Piscine_C_J06/ex_8
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Mon Oct  5 17:58:10 2015 Baptiste Mairesse
** Last update Mon Oct  5 17:58:12 2015 Baptiste Mairesse
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {

      if (str[i] == ' ')
	i++;
      else if (97 <= str[i] && 122 >= str[i])
	str[i] = (str[i] - 32);
      else
	i++;
    }
  return (str);
}