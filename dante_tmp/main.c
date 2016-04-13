/*
** main.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu\dante in C:\Users\bapti\Documents\OneDrive\Documents\rendu\dante
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Sat Mar 12 17:07:53 2016 baptiste mairesse
** Last update	Fri Apr 08 11:39:33 2016 Baptiste Mairesse
*/

#include 	"dante.h"
#include 	<unistd.h>
#include 	<sys/types.h>
#include 	<sys/stat.h>
#include 	<fcntl.h>
#include 	<stdlib.h>

void		free_all(char **tab)
{
  int		i;

  i = 0;
  while (tab[i])
    i++;
  while (i != 0)
    free(tab[i--]);
  free(tab);
}

char 		**get_tab(const char *path, int *width, int *height)
{
  int 		fd;
  char 		**tab;
  int 		i;
  char		*s;

  fd = open(path, O_RDONLY);
  *height = 0;
  while ((s = get_next_line(fd)))
    {
      free(s);
      (*height)++;
    }
  free(s);
  tab = malloc(sizeof(char *) * (*height + 1));
  if (!tab)
    exit (84);
  close(fd);
  fd = open(path, O_RDONLY);
  i = -1;
while (++i != *height)
      tab[i] = get_next_line(fd);
  tab[i] = NULL;
  *width = my_strlen(tab[0]);
  close(fd);
  return (tab);
}

t_pos		add_one(char **tab, t_pos pos, int param)
{
  if (param == 1 && tab[pos.y][pos.x + 1] && tab[pos.y][pos.x + 1] != 'a')
    pos.x++;
 else if (param == 2 && tab[pos.y + 1] && tab[pos.y + 1][pos.x] != 'a')
    pos.y++;
  else if (param == 3 && pos.y - 1 >= 0 && tab[pos.y - 1][pos.x] != 'a')
    pos.y--;
  else if (param == 4 && pos.x - 1 >= 0 && tab[pos.y][pos.x - 1] != 'a')
    pos.x--;
  else
    pos.x = -1;
  return (pos);
}

int		dante(char **tab, t_dante *dante_s, t_pos pos)
{
  char		tmp;

  if (pos.x == -1 || tab[pos.y][pos.x] == 'X')
    return (0);
    tmp = tab[pos.y][pos.x];
  tab[pos.y][pos.x] = 'a';
  if ((pos.y == dante_s->y_fin - 1 && pos.x == dante_s->x_fin - 1) ||
      dante(tab, dante_s, add_one(tab, pos, 1)) == 1 ||
      dante(tab, dante_s, add_one(tab, pos, 3)) == 1 ||
      dante(tab, dante_s, add_one(tab, pos, 2)) == 1 ||
      dante(tab, dante_s, add_one(tab, pos, 4)) == 1)
    tab[pos.y][pos.x] = 'o';
  if (tab[pos.y][pos.x] == 'o')
    return (1);
  tab[pos.y][pos.x] = tmp;
  return (0);
}

int		main(int argc, char const *argv[])
{
  char 		**tab;
  int		i;
  t_dante	*dante_s;
  t_pos		pos;

  dante_s = malloc(sizeof(t_dante));
  i = 0;
  pos.x = 0;
  pos.y = 0;
  tab = get_tab(argv[1], &dante_s->x_fin, &dante_s->y_fin);
  while (tab[i])
    my_printf("%s\n", tab[i++]);
  dante(tab, dante_s, pos);
  my_putstr("######################\n");
  i = 0;
  while (tab[i])
    my_printf("%s\n", tab[i++]);
  argc++;
  free_all(tab);
   return (0);
 }
