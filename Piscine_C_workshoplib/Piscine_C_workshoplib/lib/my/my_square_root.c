/*
** my_square_root.c for my_square_root in /home/maires_b/rendu/Piscine_C_J05/Piscine_C_J05
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Fri Oct  2 18:48:35 2015 Baptiste Mairesse
** Last update Fri Oct  2 18:48:38 2015 Baptiste Mairesse
*/

int	my_square_root(int nb)
{
  int	divi;

  divi = 1;
  if (nb > (2147483642))
    nb = nb / 8;
  while (nb / divi != divi)
    {
      divi++;
      if (divi > nb)
	return (0);
    }
  if (divi * divi != nb)
    return (0);
  return (divi);
}