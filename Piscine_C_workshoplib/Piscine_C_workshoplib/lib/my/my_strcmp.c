/*
** my_strcmp.c for my_strcmp in /home/maires_b/rendu/Piscine_C_J06/Piscine_C_J06/ex_06
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Mon Oct  5 15:52:30 2015 Baptiste Mairesse
** Last update Mon Oct  5 15:52:32 2015 Baptiste Mairesse
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;

  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] != s2[i] && s2[i] > s1[i])
	return (-1);
      if (s1[i] != s2[i] && s2[i] < s1[i])
	return (1);
      i++;
    }
  if (s1[i] && s2[i])
    return (0);
}