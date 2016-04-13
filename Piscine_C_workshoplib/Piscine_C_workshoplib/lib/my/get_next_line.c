/*
** get_next_line.c for C:\Users\bapti\Documents\home\rendu in C:\Users\bapti\Documents\home\rendu\CPE_2015_getnextline
**
** Made by baptiste mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Mon Jan 04 09:39:40 2016 baptiste mairesse
** Last update Wed Mar 16 10:01:47 2016 baptiste mairesse
*/

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char 	*str_read;

int 		my_strcpy(char *buf)
{
  char 		*tmp;
  int		i;
  int		j;
  int		k;
  int		ret;

  tmp = str_read;
  j = 0;
  i = 0;
  while (buf[i] != '\0')
    i++;
  while (str_read != NULL && str_read[j] != '\0')
    j++;
  ret = (!(str_read = my_malloc(sizeof(char) * (i + j + 1)))) ? -1 : 0;
  if (ret ==-1)
    return (ret);
  k = -1;
  while (++k != j)
    str_read[k] = tmp[k];
  str_read[k] = '\0';
  k = -1;
  while (++k != i + 1)
    str_read[k + j] = buf[k];
  free(tmp);
  return (ret);
}

int 		check_end_line()
{
  int		i;

  i = 0;
  while (str_read != NULL && str_read[i] != '\0')
    {
      if (str_read[i] == '\n')
	return (i);
      i++;
    }
  return (-1);
}

char 		*make_to_str(int first_line)
{
  int		i;
  int		ret;
  char		*line_read;

  i = 0;
  ret = (!(line_read = my_malloc(sizeof(char) * (first_line + 1)))) ? -1 : 0;
  if (ret == -1)
    return (NULL);
  while (i != first_line)
    {
      line_read[i] = str_read[i];
      i++;
    }
  line_read[i] = '\0';
  return (line_read);
}

int 		clean_stat(int first_line)
{
  int		i;
  int		j;
  int		ret;
  char		*tmp;

  i = 0;
  j = 0;
  tmp = str_read;
  while (str_read[i] != '\0')
    i++;
  ret = (!(str_read = my_malloc(sizeof(char) * (i)))) ? -1 : 0;
  if (ret == -1)
    return (ret);
  while (first_line != i)
    {
      str_read[j] = tmp[first_line];
      first_line++;
      j++;
    }
  str_read[j] = '\0';
  free(tmp);
  return (ret);
}

char 		*get_next_line(const int fd)
{
  char		*line_read;
  int		i;
  char		buf[READ_SIZE + 1];
  int		ret;
  int		debug;

  while ((i = check_end_line(ret)) == -1)
    {
      ret = read(fd, &buf, READ_SIZE);
      if (ret == -1 || ret == 0)
	return (NULL);
      buf[ret] = '\0';
      debug = (my_strcpy(buf) == -1) ? -1 : 0;
      if (debug == -1)
	return (NULL);
    }
  line_read = make_to_str(i);
  debug = (clean_stat(i + 1) == -1) ? -1 : 0;
  if (debug == -1)
    return (NULL);
  return (line_read);
}
