char  *my_itoa(int n, char *buf)
{
  int i;
  int j;
  char *tmp;

  i = 0;
  j = 0;
  while(0 <  n)
    {
      buf[i] = n % 10 + '0';
      n = n / 10;
      i++;
    }
  buf[i] = '\0';
  tmp = my_malloc(sizeof(char) * my_strlen(buf));
  while (buf[j])
    {
      tmp[j] = buf[--i];
      j++;
    }
  tmp[j] = '\0';
  free(buf);
  return tmp;
}
