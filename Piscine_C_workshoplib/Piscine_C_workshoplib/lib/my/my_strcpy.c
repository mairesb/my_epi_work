/*
** emacs.c for my_strcpy in /home/maires_b/rendu/Piscine_C_J06/Piscine_C_J06
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Mon Oct  5 09:21:43 2015 Baptiste Mairesse
** Last update Thu Feb 25 12:22:17 2016 baptiste mairesse
*/

char	*my_strcopy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
