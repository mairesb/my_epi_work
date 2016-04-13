/*
** my_strcat.c for my_strcat in rendu/Piscine_C_J07/Piscine_C_J07/lib/my
**
** Made by Baptiste Mairesse (maires_b)
** Login   <baptiste.mairesse@epitech.eu>
**
** Started on  Tue Oct 06 15:39:08 2015 Baptiste Mairesse (maires_b)
** Last update Wed Mar 16 09:49:27 2016 baptiste mairesse
*/

#include 	<stdlib.h>

char    	*my_strcat(char *dest, char *src)
{
  int   	i;
  int   	j;

  char		*tmp;

  j = -1;
  i = -1;
  tmp = my_malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));
  if (!tmp)
    return (NULL);
  while (dest[++j])
    tmp[++i] = dest[j];
  j = -1;
  while (src[++j])
    tmp[++i] = src[j];
  tmp[++i] = '\0';
  free(dest);
  return (tmp);
}
