/*
** tetris.h for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 14:53:24 2016 baptiste mairesse
** Last update Thu Mar 17 11:02:20 2016 baptiste mairesse
*/


#ifndef		MY_EXEC2_H_
# define	MY_EXEC2_H_

typedef struct	s_var
{
  int		i;
  int		j;
  int		k;
  int		l;
}		t_var;

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_printf(char *format, ...);
int		my_strcmp(const char *s1, char *s2);
int 		my_getnbr(const char *str);
char		*my_strdup(const char *str);
char  		*my_itoa(int n, char *buf);
char		*my_strcopy(char *dest, const char *src);
int 		my_strlen( char *str);
char		*my_strcat(char *s1, char *s2);
char		*get_next_line(const int fd);
char		*my_strncpy(char *dest, char *src, int nb);
void		*my_malloc(int size);
char		**get_command(char *str);



#endif		/* !MY_EXEC2_H_ */
