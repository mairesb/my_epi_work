/*
** my_strncat.c for my_strncat in rendu/Piscine_C_J07/Piscine_C_J07/lib/my
**
** Made by Baptiste Mairesse (maires_b)
** Login   <baptiste.mairesse@epitech.eu>
**
** Started on  Tue Oct 06 15:39:08 2015 Baptiste Mairesse (maires_b)
** Last update Tue Oct 06 15:39:08 2015 Baptiste Mairesse (maires_b)
*/

char	*my_strncat(char *dest, char *src, int nb)
{
  int	i;
  int 	count;

  i = 0;
  while (dest[i] != '\0')
    {
      i++;
    }
  count = 0;
  while (count != nb)
    {
      dest[i + count] = src[count];
      count++;
    }
  return (dest);
}