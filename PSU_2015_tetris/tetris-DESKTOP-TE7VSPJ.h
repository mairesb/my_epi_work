/*
** tetris.h for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 14:53:24 2016 baptiste mairesse
** Last update Sun Mar 20 21:52:22 2016 baptiste mairesse
*/

#include 	<ncurses.h>
#include 	<time.h>

#ifndef		TETRIS_H_
# define	TETRIS_H_

typedef struct s_param
{
  char		*left;
  char		*right;
  char		*turn;
  char		*drop;
  char		*quit;
  char		*pause;
  unsigned int  rows;
  unsigned int  cols;
  char		next;
  char		debug;
  unsigned int	level;
  char		help;
  char		**map;
  char		**map_tmp;
}		t_param;

typedef struct s_t_info
{
  char		*name;
  int 		width;
  int		height;
  unsigned int 	color;
  char		**tetri;
  char		error;
}		t_t_info;

typedef struct s_tetri
{
  char		*name;
  unsigned int 	width;
  unsigned int	height;
  unsigned int 	color;
  char		**tetri;
  unsigned int  nb;
  char		error;
  struct s_tetri	*next;
  struct s_tetri	*prev;
}		t_tetri;

typedef struct s_tetrictrl
{
  t_tetri	*first;
  t_tetri	*last;
}		t_tetrictrl;

typedef struct	s_game
{
  WINDOW		*board;
  WINDOW		*tetris;
  WINDOW		*panel;
  WINDOW		*next;
  int 		score;
  int 		h_score;
}		t_game;

typedef struct	s_pos
{
  unsigned int 	x;
  unsigned int 	y;
  unsigned int 	width;
  unsigned int 	height;
  unsigned int  color;
  char 		**tetri;
  unsigned int 	next;
  int 	turn;
}		t_pos;

typedef struct 	s_all
{
  t_param 	param;
  t_game	game;
  unsigned int color;
  char		update;
  time_t	time_tmp;
  t_pos		pos_cur_tet;
  t_tetrictrl	list_tetri;
}		t_all;

void		init_win();
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
int		parse_arg(t_all *all, int ac, const char *av[]);
void 		debug_mod(t_all *all);
void		get_tetri(t_all *all);
void		get_tetrimino_data(const char *file, t_t_info *info);
char 		*my_strcat(char *s1, char *s2);
void 		start_game(t_all *all);
void		init_windowss(t_all *all);
void		init_win();
void		end_window();
void		game_play(t_all *all);
void 		make_xy_tab(t_all *all);
void		super_free(char **tab);
void 		update_tab(t_all *all);
void		mvt_left(t_all *all);
void 		tab_turn(t_all *all);
void		mvt_right(t_all *all);
void		mvt_turn(t_all *all);
void		mvt_drop(t_all *all);
void 		line_or_not(t_all *all);
void 		tab_turn_inv(t_all *all);
void 		tab_clean_inv(t_all *all);
void 		tab_clean(t_all *all);
void		comp_tetris(t_all *all);
void		aff_tetrimino_info(t_tetri *elem);
int		test_pos_turn_inv(t_all *all);
int		test_pos_turn(t_all *all);
int		test_pos_clean_inv(t_all *all);
int		test_pos_clean(t_all *all);
void		my_put_in_file(int nb, char *path);
char		*key_cap(char *str);
char 		*print_key(char *key);


#endif		/* !TETRIS_H_ */
