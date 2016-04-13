/*
** main.h for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_bstetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 10:32:50 2016 baptiste mairesse
** Last update Fri Feb 26 23:43:23 2016 baptiste mairesse
*/

#ifndef		MAIN_H_
# define	MAIN_H_

typedef struct s_t_info
{
  char		*name;
  int 		width;
  int		height;
  unsigned int 	color;
  char		**tetri;
  char 		error;
}		t_t_info;

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_printf(char *format, ...);
int		my_strcmp(char *s1, char *s2);
int 		my_getnbr(char *str);
char		*my_strdup(char *str);
char		*my_strcopy(char *dest, char *src);
int 		my_strlen( char *str);
char		*get_next_line(const int fd);
void 		show_struct(t_t_info *info);
char		*my_strncpy(char *dest, char *src, int nb);
char 		*get_name(const char *file, t_t_info *info);
void		check_tetrimino(const char *file);
void 		make_to_tab(char *str, t_t_info *info, int i);
void		free_all(t_t_info *info);
char 		*my_strcat(char *s1, const char *s2);


#endif		/* !MAIN_H_ */
