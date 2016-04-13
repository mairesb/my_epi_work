// /*
// ** have_action.c for C:\Users\bapti\Documents\OneDrive Entreprise\Epitech\Documents\rendu\PSU_2015_minishell2 in C:\Users\bapti\Documents\OneDrive Entreprise\Epitech\Documents\rendu\PSU_2015_minishell2
// **
// ** Made by baptiste mairesse
// ** Login   <bapti@epitech.net>
// **
// ** Started on  Wed Mar 23 16:03:40 2016 baptiste mairesse
// ** Last update Wed Mar 23 19:10:31 2016 baptiste mairesse
// */
//
// #include 	"mysh.h"
//
// int		have_chevron_left(char *str, int *i, char *tmp, int *j)
// {
//   if (str[*i] != ' ' && str[*i] != '\t')
//     {
//       my_printf(",%c,%d\n", str[*i], *i);
//       if (str[*i + 1] && str[*i + 1] == '<')
// 	{
// 	  if (str[*i + 2] && str[*i + 2] == '<')
// 	    {
// 	      tmp[*j] = (str[*i] == '<') ? ' ' : str[*i];
// 	      tmp[*j + 1] = (str[*i] == '<') ? '<' : ' ';
// 	      tmp[*j + 2] = (str[*i] == '<') ? '<' : '<';
// 	      tmp[*j + 3] = (str[*i] == '<') ? ' ' : '<';
// 	      tmp[*j + 4] = ' ';
// 	      *j += (str[*i] == '<') ? 4 : 5;
// 	      *i += 2;
// 	    }
// 	  else
// 	    {
// 	      tmp[*j] = (str[*i] == '<') ? ' ' : str[*i];
// 	      tmp[*j + 1] = ' ';
//               tmp[*j + 2] = '<';
// 	      tmp[*j + 3] = ' ';
// 	      *i += 1;
// 	      *j += 4;
// 	    }
//             return (1);
// 	}
//     }
//   return (0);
// }
//
// int		have_chevron_right(char *str, int *i, char *tmp, int *j)
// {
//   if (str[*i] != ' ' && str[*i] != '\t')
//     {
//       if (str[*i + 1] && str[*i + 1] == '>')
// 	{
// 	  if (str[*i + 2] && str[*i + 2] == '>')
// 	    {
// 	      tmp[*j] = str[*i];
// 	      tmp[*j + 1] = ' ';
// 	      tmp[*j + 2] = '>';
// 	      tmp[*j + 3] = '>';
// 	      *j += 3;
// 	      *i += 2;
// 	    }
// 	  else
//       	    {
// 	      tmp[*j] = str[*i];
// 	      tmp[*j + 1] = ' ';
// 	      tmp[*j + 2] = '>';
// 	      *i += 1;
// 	      *j += 2;
// 	    }
// 	  return (1);
// 	}
//     }
//   return (0);
// }
//
// int		have_pipe_test(char *str, int *i, char *tmp, int *j)
// {
//   if (str[*i] != ' ' && str[*i] != '\t')
//     {
//       if (str[*i + 1] && str[*i + 1] == '|')
// 	{
// 	  tmp[*j++] = str[*i];
// 	  tmp[*j++] = ' ';
// 	  tmp[*j++] = '|';
// 	  *i += 1;
// 	  return (1);
// 	}
//     }
//   return (0);
// }
//
// int		have_end_test(char *str, int *i, char *tmp, int *j)
// {
//   if (str[*i] != ' ' && str[*i] != '\t')
//     {
//       if (str[*i + 1] && str[*i + 1] == ';')
// 	{
// 	  tmp[*j++] = str[*i];
// 	  tmp[*j++] = ' ';
// 	  tmp[*j++] = '|';
// 	  *i += 1;
// 	  return (1);
// 	}
//     }
//   return (0);
// }
