/*
** base.h for core in Documents/annee_1/semestre_1/infographie/Others/entrainement
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Mon Dec 14 20:38:32 2015 Antoine MOREL
** Last update Mon Dec 14 20:38:32 2015 Antoine MOREL
*/

#include		<lapin.h>
#include		<lapin_enum.h>
#ifndef			BASE_H_
# define		BASE_H_

typedef	struct		s_load_bmp
{
  t_bunny_pixelarray	*Brushs;
  t_bunny_pixelarray	*Buckets;
  t_bunny_pixelarray	*Erasers;
  t_bunny_pixelarray	*Brushs_select;
  t_bunny_pixelarray	*Buckets_select;
  t_bunny_pixelarray	*Erasers_select;
  t_bunny_pixelarray	*Brushs_small;
  t_bunny_pixelarray	*Brushs_med;
  t_bunny_pixelarray	*Brushs_large;
  t_bunny_pixelarray	*Color_select;
  t_bunny_pixelarray	*Color;
  t_bunny_pixelarray	*Circle_select;
  t_bunny_pixelarray	*Circle;
  t_bunny_pixelarray	*Traces;
  t_bunny_pixelarray	*Traces_select;
  t_bunny_pixelarray	*Box;
  t_bunny_pixelarray	*Save;
  t_bunny_pixelarray	*Save_select;
  t_bunny_pixelarray	*Palette;
  t_bunny_pixelarray	*Palette_select;
  t_bunny_pixelarray	*filter_select;
  t_bunny_pixelarray	*filter;
  t_bunny_pixelarray	*baw;
  t_bunny_pixelarray	*blurs;
  t_bunny_pixelarray	*invert;
}			t_load_bmp;

typedef	struct		s_lapin
{
  t_bunny_window	*window_1;
  t_bunny_pixelarray	*font;
  t_bunny_pixelarray	*pixelarray_1;
  t_bunny_pixelarray	*pixelarray_2;
  t_bunny_pixelarray	*pixelarray_3;
  t_bunny_pixelarray	*pixelarray_4;
  t_bunny_pixelarray	*pixelarray_tmp;
  t_bunny_pixelarray	*pixelarray_tmp_2;
  t_bunny_pixelarray	*img;
  t_bunny_position	pos_mouse_tmp;
  int			interf_or_not;
  char			*str;
  int			tools;
  int			format;
  int			option;
  int			mouse_click;
  unsigned int		color;
  int			size;
  int			save;
  t_load_bmp		bmp;
}			t_lapin;

typedef	struct		s_hbmp
{
  short int		id;
  int			size;
  int			useless;
  int			pos_pix;
  int			head_size;
  int			width;
  int			height;
  short int		p_bit;
  short int		bits_pix;
  int			cprs;
  int			oct_size;
  int			pix_width;
  int			pix_height;
  int			color_pal;
  int			color_imp;
} __attribute__ ((packed))	t_hbmp;

typedef	struct		s_position
{
  t_bunny_position	position;
  struct s_position	*next;
}			t_position;

#endif			/* !BASE_H_ */
