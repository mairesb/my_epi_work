/*
** my_revstr.c for my_revstr in /home/maires_b/rendu/Piscine_C_J06/Piscine_C_J06
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Mon Oct  5 11:10:47 2015 Baptiste Mairesse
** Last update Mon Oct  5 11:10:49 2015 Baptiste Mairesse
*/

char	*my_revstr(char *str)
{
  char	x;
  int	start;
  int	end;

  start = 0;
  end = my_strlen(str) - 1;
  while (start < end)
    {
      x = str[start];
      str[start] = str[end];
      str[end] = x;
      start = start + 1;
      end = end - 1;
    }
  return (str);
}