/*
** my_strcapitalize.c for my_strcapitalize in /home/maires_b/rendu/Piscine_C_J06/Piscine_C_J06/ex_10
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Mon Oct  5 18:27:31 2015 Baptiste Mairesse
** Last update Mon Oct  5 18:27:32 2015 Baptiste Mairesse
*/

char	*my_strupcases(char *str, int i)
{

  if (97 <= str[i] && 122 >= str[i])
    str[i] = (str[i] - 32);
  else
    i++;
  return (str);
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (i == 0)
	my_strupcases(str, i);
      if (str[i] == ' ')
	my_strupcases(str, i + 1);
      i++;
    }
  return (str);
}