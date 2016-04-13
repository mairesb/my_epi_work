/*
** my_strncmp.c for my_strncmp in /home/maires_b/rendu/Piscine_C_J06/Piscine_C_J06/ex_07
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Mon Oct  5 17:01:12 2015 Baptiste Mairesse
** Last update Mon Oct  5 17:01:13 2015 Baptiste Mairesse
*/

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;

  i = 0;
  while (i < nb)
    {
      if (s1[i] != s2[i] && s2[i] > s1[i])
	return (-1);
      if (s1[i] != s2[i] && s2[i] < s1[i])
	return (1);
      i++;
    }
  if (s1[i] && s2[i] && nb)
    return (0);
}