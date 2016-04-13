/*
** tetris.h for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 14:53:24 2016 baptiste mairesse
** Last update Wed Mar 16 13:35:31 2016 baptiste mairesse
*/


#ifndef		MYSH_H_
# define	MYSH_H_

typedef struct	s_mysh
{
  char		**env;
  char		**path;
  char		*command;
  char 		**tab_com;
}		t_mysh;

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
char 		**get_env_arg(char **env);
void 		free_struct(t_mysh *mysh);
char 		*src_env(char **env, char *str);
char 		**get_path(char **env);
int 		aff_prompt();
void 		ctrl_c_p();
void 		ctrl_c_f();
int 		comp_str(char *s1, char *s2);
void 		my_builtins(t_mysh *mysh);
void 		my_error(char *str);
char		**get_command(char *str);
void		free_command(t_mysh *mysh);
int 		check_str(char *str);
void 		my_exit(t_mysh *mysh);
void 		my_cd(t_mysh *mysh);
int 		src_str(char *s1, char *s2);
int 		comp_str(char *s1, char *s2);
int 		my_exe(t_mysh *my_struct);
void		*my_malloc(int size);
void 		my_set_env(t_mysh *mysh);
void		my_unset_env(t_mysh *mysh);
char 		*my_strcat_free(char *s1, char *s2);


#endif		/* !MYSH_H_ */
