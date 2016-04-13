/*
** percent.c for percent in /rendu/PSU_2015_my_printf/PSU_2015_my_printf/lib/my
**
** Made by Mairesse Baptiste (maires_b)
** Login   <baptiste.mairesse@epitech.eu>
**
** Started on  Wed Nov 11 15:19:39 2015 Mairesse Baptiste (maires_b)
** Last update Wed Nov 11 15:19:39 2015 Mairesse Baptiste (maires_b)
*/
#include "../../include/my.h"

int 	my_unsign(int nb)
{
  int 	i;
  i = 0;
  if (nb < 0)
    nb *= -1;
  i += my_putnbr(nb, "01");
  return (i);
}

int     my_putnbr2(int nb, char *base)
{
  int   divi;
  int 	i;
  int 	leng;

  leng = my_strlen(base);
  i = 0;
  divi = 1;
  while ((nb / divi) >= leng)
    {
      divi = divi * leng;
    }
  while (divi > 0)
    {
      i += 1;
      divi = divi / leng;
    }
  return (i);
}

int 	my_put_non_print(int c)
{
  int	i;
  int 	j;

  j = 0;
  i = 0;
  i += my_putchar('\\');
  j = my_putnbr2(c, "01234567");
  while (j != 3)
    {
      i += my_putchar('0');
      j++;
    }
  i += my_putnbr(c, "01234567");
  return (i);
}

int     my_putnbr_p(int nb, char *base)
{
  int   divi;
  int i;
  int leng;

  leng = my_strlen(base);
  i = 2;
  my_putstr("0x");
  divi = 1;
  while ((nb / divi) >= leng)
    {
      divi = divi * leng;
    }
  while (divi > 0)
    {
      i += my_putchar(base[(nb / divi) % leng]);
      divi = divi / leng;
    }
  return (i);
}