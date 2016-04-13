/*
** main.c for main_printf in /rendu/PSU_2015_my_printf/PSU_2015_my_printf/lib/my
**
** Made by Mairesse Baptiste (maires_b)
** Login   <baptiste.mairesse@epitech.eu>
**
** Started on  Thu Nov 05 17:31:43 2015 Mairesse Baptiste (maires_b)
** Last update Thu Nov 05 17:31:43 2015 Mairesse Baptiste (maires_b)
*/
#include <stdarg.h>
#include "../../include/my.h"

int 	percent_s(char *str)
{
  int 	i;
  int 	j;

  j = 0;
  i = 0;
  while (i < my_strlen(str))
    {
      if (str[i] < 32 || str[i] >= 127)
	{
	  j += my_put_non_print(str[i]);
	  i++;
	}
      while (str[i] > 32 && str[i] < 127)
	{
	  j += my_putchar(str[i]);
	  i++;
	}
    }
  return (j);
}

void		check_param(t_print* print)
{
  print->i++;
  if (check_flag(print->format[print->i]) == 0)
    {
      if (print->format[print->i] == ' ')
	print->nb_aff += my_putchar(' ');
      while (check_flag(print->format[print->i]) == 0)
	print->i++;
    }
  print->ret = print->format[print->i];
}

int 	unkown_flag(char c)
{
  int 	i;
  i = 0;
  i += my_putchar('%');
  i += my_putchar(c);
  return i;
}

void	 	have_percent(t_print* print)
{
  check_param(print);
  if (print->ret == 's')
    print->nb_aff += my_putstr(va_arg(print->pa, char *));
  else if (print->ret == 'd' || print->ret == 'i')
    print->nb_aff += my_putnbr(va_arg(print->pa, int), "0123456789");
  else if (print->ret == 'x')
    print->nb_aff += my_putnbr(va_arg(print->pa, int), "0123456789abcdef");
  else if (print->ret == 'X')
    print->nb_aff += my_putnbr(va_arg(print->pa, int), "0123456789ABCDEF");
  else  if (print->ret == 'o')
    print->nb_aff += my_putnbr(va_arg(print->pa, int), "01234567");
  else if (print->ret == 'c')
    print->nb_aff += my_putchar(va_arg(print->pa, int));
  else if (print->ret == '%')
    print->nb_aff += my_putchar('%');
  else if (print->ret == 'S')
    print->nb_aff += percent_s(va_arg(print->pa, char*));
  else if (print->ret == 'b')
    print->nb_aff += my_unsign(va_arg(print->pa, int));
  else if (print->ret == 'p')
    print->nb_aff += my_putnbr_p(va_arg(print->pa, int), "0123456789abcdef");
  else
    print->nb_aff 	+= unkown_flag(print->ret);
}

int		my_printf(const char *format, ...)
  {
    t_print	my_print;

    va_start(my_print.pa, format);
    my_print.i = 0;
    my_print.nb_aff = 0;
    my_print.format = format;
    while (format[my_print.i] != '\0')
      {
	if (format[my_print.i] == '%')
	  have_percent(&my_print);
	else
	  my_print.nb_aff += my_putchar(format[my_print.i]);
	my_print.i++;
      }
    return (my_print.nb_aff);
  }