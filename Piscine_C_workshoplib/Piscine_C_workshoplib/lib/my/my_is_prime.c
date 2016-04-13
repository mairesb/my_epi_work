/*
** my_prime_is.c for my_prime_is in /home/maires_b/rendu/Piscine_C_J05/Piscine_C_J05
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Fri Oct  2 20:46:31 2015 Baptiste Mairesse
** Last update Fri Oct  2 20:46:33 2015 Baptiste Mairesse
*/

int	my_is_prime(int nombre)
{
  int	compteur;

  compteur = 2;
  if (nombre == 0 || nombre == 1)
    return (0);
  while (nombre > compteur)
    {
      if (nombre % compteur == 0)
	return (0);
      compteur++;
    }
  return (1);
}
