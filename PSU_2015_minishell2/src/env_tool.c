/*
** env_tool.c for C:\Users\bapti\Documents\OneDrive\Documents\rendu in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Mon Mar 14 14:53:06 2016 baptiste mairesse
** Last update Wed Mar 16 12:25:13 2016 baptiste mairesse
*/

#include 	"mysh.h"
#include 	<stdlib.h>

int 		comp_str(char *s1, char *s2)
{
  int i;

  i = 0;
  if (!s1 || !s2)
    return (0);
  if (my_strlen(s1) != my_strlen(s2))
    return (0);
  while (s1[i] != '\0' && s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (0);
      i++;
    }
  return (1);
}

int 		src_str(char *s1, char *s2)
{
  int 		i;

  i = 0;
  if (!s1 || !s2)
    return (0);
  while (s1[i] != '\0' && s1[i] != '=')
    {
      if (s1[i] != s2[i])
	{
	  return (0);
	}
      i++;
    }
  return (1);
}

char 		*src_env(char **env, char *str)
{
  int 		i;
  int 		j;
  int 		equal;
  char 		*var;

  i = -1;
  j = 0;
  while (env[++i])
    {
      if (src_str(str, env[i]) == 1)
	{
	  var = my_malloc(sizeof(char) * my_strlen(env[i]));
	  equal = my_strlen(str) + 1;
	  while (equal < my_strlen(env[i]))
	    {
	      var[j] = env[i][equal];
	      j++;
	      equal++;
	    }
	  var[j] = '\0';
	  return (var);
	}
    }
  return (NULL);
}
