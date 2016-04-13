/*
** dante.h for C:\Users\bapti\Documents\OneDrive\Documents\rendu\dante in C:\Users\bapti\Documents\OneDrive\Documents\rendu\dante
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Sat Mar 12 17:08:17 2016 baptiste mairesse
** Last update	Fri Apr 08 14:42:00 2016 Baptiste Mairesse
*/

#ifndef		DANTE_H_
# define	DANTE_H_

# define 	WALL 		('X')
# define 	PATH 		('.')
# define 	SOLVE 		('o')


typedef struct s_dante
{
  int		x_fin;
  int		y_fin;
}		t_dante;
typedef struct s_pos
{
  int		x;
  int		y;
}		t_pos;

typedef struct s_res
{
  int		xp;
  int		xm;
  int		yp;
  int		ym;
}		t_res;



void		my_putchar(char c);
void		my_putstr(char *str);
void		my_printf(char *format, ...);
int		my_strcmp(const char *s1, char *s2);
int 		my_getnbr(const char *str);
char		*my_strdup(const char *str);
char  		*my_itoa(int n, char *buf);
char		*my_strcopy(char *dest, const char *src);
int 		my_strlen( char *str);
char		*get_next_line(const int fd);
char		*my_strncpy(char *dest, char *src, int nb);

#endif		/* !DANTE_H_ */
