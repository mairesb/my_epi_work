/*
** pot_peinture.c for  in /home/pillon_m/rendu/rendu/gfx_tekpaint/pilloooon
**
** Made by maxime pillon
** Login   <pillon_m@epitech.net>
**
** Started on  Tue Jan 26 09:14:06 2016 maxime pillon
** Last update Tue Jan 26 18:57:15 2016 Yan Poinssot
*/

#include		<stddef.h>
#include		<stdlib.h>
#include		<lapin.h>
#include		"base.h"
#include		"my.h"

t_position		*new_list(t_bunny_position pos)
{
  t_position		*new;

  if ((new = bunny_malloc(sizeof(t_position))) != NULL)
    {
      new->position.x = pos.x;
      new->position.y = pos.y;
      new->next = NULL;
    }
  return (new);
}

t_position		*add_on_stack(t_bunny_position pos,
				      t_position *pile)
{
  t_position		*new_elem;

  if ((new_elem = bunny_malloc(sizeof(t_position))) == NULL)
    {
      return (pile);
    }
  new_elem->position.x = pos.x;
  new_elem->position.y = pos.y;
  new_elem->next = pile;
  pile = new_elem;
  return (pile);
}

t_position		*unset_on_stack(t_position *pile)
{
  t_position		*position;

  position = pile;
  pile = pile->next;
  bunny_free(position);
  return (pile);
}

t_position		*stack_pile(unsigned int colcible,
				    t_bunny_position check,
				    t_position *pile,
				    t_bunny_pixelarray *pix)
{
  check.y -= 1;
  if (check.y >= 0)
    if (((unsigned int *)pix->pixels)
	[check.y * pix->clipable.clip_width + check.x] == colcible)
      pile = add_on_stack(check, pile);
  check.y += 2;
  if (check.y < pix->clipable.clip_height)
    if (((unsigned int *)pix->pixels)
	[check.y * pix->clipable.clip_width + check.x] == colcible)
      pile = add_on_stack(check, pile);
  check.y -= 1;
  check.x -= 1;
  if (check.x >= 0)
    if (((unsigned int *)pix->pixels)
	[check.y * pix->clipable.clip_width + check.x] == colcible)
      pile = add_on_stack(check, pile);
  check.x += 2;
  if (check.x < pix->clipable.clip_width)
    if (((unsigned int *)pix->pixels)
	[check.y * pix->clipable.clip_width + check.x] == colcible)
      pile = add_on_stack(check, pile);
  return (pile);
}

void			do_peinture(t_bunny_pixelarray *pix,
				    t_bunny_position  pos,
				    unsigned int colrep)
{
  t_color		color;
  t_position		*pile;
  int			count;
  t_bunny_position	check;
  unsigned int		colcible;

  color.full = colrep;
  pile = new_list(pos);
  colcible = ((unsigned int *)pix->pixels)
    [pos.y * pix->clipable.clip_width + pos.x];
  check.x = pos.x;
  check.y = pos.y;
  count = 0;
  while (pile != NULL)
    {
      count++;
      tekpixel(pix, &check, &color);
      pile = unset_on_stack(pile);
      pile = stack_pile(colcible, check, pile, pix);
      if (pile == NULL)
	return ;
      check.x = pile->position.x;
      check.y = pile->position.y;
    }
  return ;
}
