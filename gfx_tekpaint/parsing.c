/*
** parsing.c for Parsing in /home/poinss_y/Documents/gfx_wolf3d
**
** Made by Yan Poinssot
** Login   <poinss_y@epitech.net>
**
** Started on  Tue Jan 26 15:45:29 2016 Yan Poinssot
** Last update Tue Jan 26 19:19:51 2016 Yan Poinssot
*/

#include	<unistd.h>

int		check_format(char *a)
{
  int		c;

  if (a[0] == '.')
    {
      write(2, "Invalid filename\n", 16);
      return (-1);
    }
  c = 0;
  while (a[++c] != '\0')
    {
      if (a[c] == '.' && a[c + 1] == 'b' && a[c + 2] == 'm' &&
      a[c + 3] == 'p' && a[c + 4] == '\0')
      return (1);
      if (a[c] == '.' && a[c + 1] == 'f' && a[c + 2] == 't' &&
      a[c + 3] == 'n' && a[c + 4] == '\0')
      return (2);
      else if (a[c] == '.')
	{
	  write(2, "Invalid filename; accepted formats: .bmp or .ftn\n", 48);
	  return (-1);
	}
    }
  write(2, "Invalid filename; accepted formats: .bmp or .ftn\n", 48);
  return (-1);
}

int		parse(int argc, char **argv)
{
  if (argc != 2)
    {
      write(2, "Invalid argument; ./tekpaint [Filename]\n", 39);
      return (-1);
    }
  return (check_format(argv[1]));
}
