/*
** my_power_rec.c for my_power_rec.c in /home/maires_b/rendu/Piscine_C_J05/Piscine_C_J05
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Fri Oct  2 14:44:51 2015 Baptiste Mairesse
** Last update Fri Oct  2 14:44:53 2015 Baptiste Mairesse
*/

int	my_power_rec(int nb, int power)
{
  int	a;

  if (a > 2147483647 / nb || a < 2147483648 / nb)
    return (0);
  if ((power + 1) > 1)
    nb = nb * my_power_rec(nb, power - 1);
  else if (power == 0)
    nb = 1;
  else
    nb = 0;
  return (nb);
}