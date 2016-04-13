int	my_strlen_tab(char **tab)
{
  int	i;

  i = 0;
 if (!tab || !tab[0])
    return (0);
  while (tab[i])
    i++;
  return (i);
}
