/*
** my_strstr.c for my_strstr in /home/maires_b/rendu/Piscine_C_J06/Piscine_C_J06/ex_05
**
** Made by Baptiste Mairesse
** Login   <maires_b@epitech.net>
**
** Started on  Mon Oct  5 14:09:03 2015 Baptiste Mairesse
** Last update Mon Oct  5 14:09:05 2015 Baptiste Mairesse
*/

char	*my_strstr(char *str, char *to_find)
{
  int	compteur;

  if (str[0] != '\0')
    {
      compteur = 0;
      while (to_find[compteur] != '\0')
	{
	  if (to_find[compteur] != str[compteur])
	    return (my_strstr(str + 1, to_find));
	  compteur++;
	}
      return (str);
    }
  else
    return (0);
}
