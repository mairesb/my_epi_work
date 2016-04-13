/*
** my_getnbr.c for my_getnbr in /home/maires_b/rendu/Piscine_C_J04/Piscine_C_J04
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Thu Oct  1 13:56:50 2015 Baptiste Mairesse
** Last update Thu Oct  1 13:56:52 2015 Baptiste Mairesse
*/

int             my_getnbr(char *str)
{
  int           i;
  int           nbr;

  nbr = 0;
  i = 0;
  if (!str)
    return (-1);
  while (is_num(str[i]) == 0)
    i++;
  while (is_num(str[i]) == 1)
    {
      nbr = ((nbr * 10) + (str[i] - 48));
      i++;
    }
  if (is_neg(str) == 1)
    nbr = -nbr;
  return (nbr);
}
