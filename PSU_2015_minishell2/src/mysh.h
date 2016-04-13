/*
** tetris.h for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 14:53:24 2016 baptiste mairesse
** Last update	Tue Apr 12 19:01:53 2016 Baptiste Mairesse
*/

#ifndef		MYSH_H_
# define	MYSH_H_

typedef struct	s_com
{
  char 		*com;
  int		type;
  struct s_com 	*next;
  struct s_com 	*prev;
}		t_com;

typedef struct 	s_comctrl
{
  t_com		*first;
  t_com		*last;
}		t_comctrl;

typedef struct	s_mysh
{
  char		**env;
  char		**path;
  char		*command;
  char		*command_sel;
  t_comctrl	tab_sel_ctrl;
  char 		**tab_com;
  int		ret_val;
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
int 		my_strlen(char *str);
int 		my_strlen_tab(char **tab);
void		my_free(void *ptr);
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
void 		start_list(t_comctrl *l);
void 		 make_top(t_comctrl *l, char *str);
char 		*format_command(int i, char *str);
void		updatepwd(t_mysh *mysh, char *pwd);
void 		update_pwd(t_mysh *mysh, char *pwd);
char		*my_strdub_n_to_n(char *str, int n, int n_f);
void		parse_command(t_mysh *mysh);
void		exec_sub_command(t_mysh *mysh);
void 		show_list(t_comctrl list);
void		free_list(t_comctrl *list);
void		free_tab(char **tab);
void 		exec_command(t_mysh *mysh);
void		redir_multi_com(t_mysh *mysh);
void		my_close(int fd);
void		my_write(int fd, const void *buf, int len);
t_com		*do_redir(t_com *elem, int fd[2], t_mysh *mysh);
void 		forker(int fd_sauvg, int fd, t_mysh *mysh, t_com *elem);
void		check_ret_sig(int sig, int *ret_val);
void		exec_multi_command(t_mysh *mysh, char *com);
void 		clean_mem(t_mysh *mysh);

#endif		/* !MYSH_H_ */
