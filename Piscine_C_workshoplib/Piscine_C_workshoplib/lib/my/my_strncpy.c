/*
** my_strncpy.c for my_strncpy in /home/maires_b/rendu/Piscine_C_J06/Piscine_C_J06
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Mon Oct  5 09:50:49 2015 Baptiste Mairesse
** Last update Mon Oct  5 09:50:51 2015 Baptiste Mairesse
*/

char	*my_strncpy(char *dest, char *src, int nb)
{
  int	i;

  i = 0;
  while (src[i] != '\0' && i < nb)
    {
      dest[i] = src[i];
      i++;
    }
  while (i < nb)
    {
      dest[i] = '\0';
      i++;
    }
  return (dest);
}