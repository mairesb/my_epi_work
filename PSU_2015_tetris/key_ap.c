/*
** key_ap.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_tetris in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_tetris
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Sun Mar 20 21:20:27 2016 baptiste mairesse
** Last update Sun Mar 20 23:24:14 2016 baptiste mairesse
*/

#include 	"tetris.h"
#include 	<stdlib.h>

char 		*print_key(char *key)
{
  char 		*str;

  str = malloc(sizeof(char) * 5);
  str[4] = 0;
  str[0] = '^';
  str[1] = 'E';
  str[2] = 'O';
  if (my_strcmp(key, tigetstr("kcub1")) == 0)
    str[3] = 'D';
  else if (my_strcmp(key, tigetstr("kcuf1")) == 0)
    str[3] = 'C';
 else if (my_strcmp(key, tigetstr("kcuu1")) == 0)
    str[3] = 'A';
  else if (my_strcmp(key, tigetstr("kcud1")) == 0)
    str[3] = 'B';
  else
    return (key);
  return (str);
}

char		*key_cap(char *str)
{
  if (str[1] == '[')
    str[1] = 'E';
  return (str);
}
