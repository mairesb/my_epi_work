/*
** my_strdub_n_to_n.c for C:\Users\bapti\Documents\OneDrive Entreprise\Epitech\Documents\rendu\Piscine_C_workshoplib\Piscine_C_workshoplib\lib\my in C:\Users\bapti\Documents\OneDrive Entreprise\Epitech\Documents\rendu\Piscine_C_workshoplib\Piscine_C_workshoplib\lib\my
**
** Made by baptiste mairesse
** Login   <bapti@epitech.net>
**
** Started on  Wed Mar 23 19:25:40 2016 baptiste mairesse
** Last update	Wed Mar 30 13:03:38 2016 Baptiste Mairesse
*/

char          my_strdub_n_to_n(char *str, int n, int n_f)
{
  char        *tmp;
  int         i;

  i = 0;
  tmp = my_malloc(sizeof(char) * (n_f - n + 2));
  while (str[n] && n <= n_f)
    tmp[i++] = str[n++];
  tmp[i] = 0;
  return (tmp);
}
