/*
** my_isneg.c for my_isneg in /home/maires_b/Documents/Piscine_C_J03/my_isneg
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Wed Sep 30 10:19:11 2015 Baptiste Mairesse
** Last update Wed Sep 30 10:32:20 2015 Baptiste Mairesse
*/

int             is_neg(char *str)
{
  int           i;
  int           counter;

  i = 0;
  counter = 0;
  while (str[i] > '9' || str[i] < '0')
    {
      if (str[i] == '-')
	counter++;
      i++;
    }
  if (counter % 2 != 0)
    return (1);
  else
    return (0);
}

int is_num(char c)
{
  if (c >= '0' && c <= '9')
    return 1;
  return 0;
}
