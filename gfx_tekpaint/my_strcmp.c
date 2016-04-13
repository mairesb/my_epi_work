/*
** my_strcmp.c for my_strcmp in /home/morel_j/Documents/B1-Piscine/Jour_6/Piscine_C_J06
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Sun Oct 18 10:44:45 2015 Antoine MOREL
** Last update Sun Oct 18 11:23:41 2015 Antoine MOREL
*/

int	my_strcmp(char *s1, char *s2)
{
  int	c1;

  c1 = 0;
  while (s1[c1] == s2[c1] && s1[c1] != '\0')
    {
      c1++;
    }
  return (s1[c1] - s2[c1]);
}
