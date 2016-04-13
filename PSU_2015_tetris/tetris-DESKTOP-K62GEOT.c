/*
** tetris.c for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <Baptiste@epitech.net>
**
** Started on  Thu Feb 25 14:40:01 2016 baptiste mairesse
** Last update Sun Mar 20 21:42:42 2016 baptiste mairesse
*/

#include 	"tetris.h"
#include 	<stdlib.h>
#include 	<sys/types.h>
#include 	<sys/stat.h>
#include 	<fcntl.h>
#include 	<term.h>
#include 	<unistd.h>

void		my_put_in_file(int nb, char *path)
{
  int 		divi;
  int 		fd;
  char		buf;

  fd = open(path, O_CREAT);
  if (fd == -1)
    return;
  divi = 1;
  while ((nb / divi) >= 10)
    {
      divi = divi * 10;
    }
  while (divi > 0)
    {
      buf = (nb / divi) % 10 + 48;
      write(fd, &buf, 1);
      divi = divi / 10;
    }
  close (fd);
}

void 		init_struct(t_all *all)
{
  setupterm(NULL, 1, (int*)0);
  all->param.left = key_cap(tigetstr("kcub1"));
  all->param.right = key_cap(tigetstr("kcuf1"));
  all->param.turn = key_cap(tigetstr("kcuu1"));
  all->param.drop = key_cap(tigetstr("kcud1"));
  all->param.quit = my_strdup("q");
  all->param.pause = my_strdup(" ");
  all->param.rows = 20;
  all->param.cols = 10;
  all->param.next = 0;
  all->param.debug = '0';
  all->param.level = 1;
  all->param.help = '0';
  all->update = '0';
}

void		init_tab(t_all *all, char ***map)
{
  unsigned int 	i;
  unsigned int 	j;

  i = 0;
  (*map) = malloc(sizeof(char *) * all->param.rows + 1);
  while (i < all->param.rows)
    {
      j = 0;
      (*map)[i] = malloc(sizeof(char) * all->param.cols + 1);
      while (j < all->param.cols)
	{
	  (*map)[i][j] = '0';
	  j++;
	}
      (*map)[i][all->param.cols] = '\0';
      i++;
    }
  (*map)[all->param.rows] = NULL;
}

void		my_help(const char *name_exe)
{
  my_printf("Usage: %s [options]\n", name_exe);
  my_putstr("Options:\n");
  my_putstr("  --help\t\tDisplay this help\n");
my_putstr("  -l --level={num}\tStart Tetris at level num\n");
my_putstr("  -kl --key-left={K}\tMove tetrimino on LEFT with key K\n");
my_putstr("  -kr --key-right={K}\tMove tetrimino on RIGHT with key K\n");
my_putstr("  -kt --key-turn={K}\tTurn tetrimino with key K\n");
my_putstr("  -kd --key-drop={K}\tSet default DROP on key K\n");
my_putstr("  -kq --key-quit={K}\tQuit program when press key K\n");
my_putstr("  -kp --key-pause={K}\tPause and restart game when press key K\n");
my_putstr("  --map-size={row,col}\tSet game size at row, col\n");
  my_putstr("  -w --without-next\tHide next tetrimino\n");
  my_putstr("  -d --debug\t\tDebug mode\n");
}

int 		main(int argc, char const *argv[])
{
  t_all 	all;
  int 		fd;

  fd = open("hs.txt", O_CREAT);
  all.game.h_score = my_getnbr(get_next_line(fd));
  if (all.game.h_score == -1)
    all.game.h_score = 0;
  init_struct(&all);
  if (parse_arg(&all, argc, argv) == -1)
    {
      my_printf("Bad option, test \"%s --help\"\n", argv[0]);
      return (84);
    }
  get_tetri(&all);
  init_tab(&all, &all.param.map);
  init_tab(&all, &all.param.map_tmp);
  if (all.param.help == '1')
    {
      my_help(argv[0]);
      return (0);
    }
  if (all.param.debug == 1)
    debug_mod(&all);
  start_game(&all);
  return (0);
}
