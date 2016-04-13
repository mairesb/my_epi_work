/*
** my.h for my in /home/maires_b/rendu/Piscine_C_J09/Piscine_C_J09/ex_02
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Thu Oct  8 11:37:38 2015 Baptiste Mairesse
** Last update Thu Feb 25 12:15:36 2016 baptiste mairesse
*/
#ifndef MY_H_
# define MY_H_
#include <stdarg.h>

typedef struct s_print
  {
    int nb_aff;
    char ret;
    int i;
    const char *format;
    va_list pa;
  }t_print;

int	my_putchar(char c);
int 	my_isneg(char *str);
int 	my_put_nbr(int nb, char *base);
int 	my_swap(int *a, int *b);
int 	my_putstr(char *str);
int 	my_strlen(char *str);
int 	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int 	my_power_rec(int nb, int power);
int 	my_square_root(int nb);
int 	my_is_prime(int nombre);
int 	my_find_prime_sup(int nb);
char	*my_strcopy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int 	my_strcmp(char *s1, char *s2);
int 	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int 	my_str_isalpha(char *str);
int 	my_str_isnum(char *str);
int 	my_str_islower(char *str);
int 	my_str_isupper(char *str);
int 	my_str_isprintable(char *str);
int 	my_showstr(char *str);
int 	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int 	my_unsign(int nb);
int     my_putnbr2(int nb , char *base);
int   	my_put_non_print(int c);
int 	percent_s(char *str);
void	check_param(t_print* print);
void	have_percent(t_print* print);
int	my_printf(const char *format, ...);
int   	check_flag(char c);
int 	unkown_flag(char c);
char *my_strdup(char *str);
int is_num(char c);
#endif	/* !MY_H_ */
