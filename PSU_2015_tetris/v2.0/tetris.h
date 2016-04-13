/*
** tetris.h for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 14:53:24 2016 baptiste mairesse
** Last update Thu Mar 03 14:03:06 2016 baptiste mairesse
*/

#include 	<ncurses.h>
#include 	<time.h>

#ifndef		TETRIS_H_
# define	TETRIS_H_
# define 	HELP ("Usage: ./tetris [options]\nOptions:\n --help Display this help\n -l --level={num} Start Tetris at level num\n -kl --key-left={K} Move tetrimino on LEFT with key K\n -kr --key-right={K} Move tetrimino on RIGHT with key K\n")
# define 	HELP2 (" -kt --key-turn={K} Turn tetrimino with key K\n -kd --key-drop={K} Set default DROP on key K\n -kq --key-quit={K} Quit program when press key K\n -kp --key-pause={K} Pause and restart game when press key K\n --map-size={row,col} Set game size at row, col\n -w --without-next Hide next tetrimino\n -d --debug Debug mode\n")

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

void		my_putchar(char c);
void		my_putstr(char *str);
void		my_printf(char *format, ...);
int		my_strcmp(const char *s1, char *s2);
int 		my_getnbr(const char *str);
char		*my_strdup(const char *str);
char		*my_strcopy(char *dest, const char *src);
int 		my_strlen( char *str);
char		*get_next_line(const int fd);
char		*my_strncpy(char *dest, char *src, int nb);
int		parse_arg(t_all *all, int ac, const char *av[]);
void 		debug_mod(t_all *all);
void		get_tetri(t_all *all);
t_t_info	get_tetrimino_data(const char *file);
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
int		test_pos_norm(t_all *all, unsigned int y, unsigned int x);
int		test_pos_turn(t_all *all, unsigned int y, unsigned int x);

#endif		/* !TETRIS_H_ */
