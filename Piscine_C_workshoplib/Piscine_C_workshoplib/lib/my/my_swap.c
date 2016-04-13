/*
** my_swap.c for my_swap in /home/maires_b/rendu/Piscine_C_J04/Piscine_C_J04
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Thu Oct  1 09:47:20 2015 Baptiste Mairesse
** Last update Thu Oct  1 09:47:22 2015 Baptiste Mairesse
*/

int	my_swap(int *a, int *b)
{
  int 	x;

  x = *a;
  *a = *b;
  *b = x;
}