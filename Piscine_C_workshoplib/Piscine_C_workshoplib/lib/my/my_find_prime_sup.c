/*
** my_find_prime_sup.c for my_find_prime_sup in /rendu/Piscine_C_J07/Piscine_C_J07/lib/my
**
** Made by Baptiste Mairesse (maires_b)
** Login   <baptiste.mairesse@epitech.eu>
**
** Started on  Tue Oct 06 11:39:30 2015 Baptiste Mairesse (maires_b)
** Last update Tue Oct 06 11:39:30 2015 Baptiste Mairesse (maires_b)
*/

int	my_find_prime_sup(int nb)
{
  int	c;

  while ((c = my_is_prime(nb)) == 0)
    {
      nb++;
    }
  return (nb);
}