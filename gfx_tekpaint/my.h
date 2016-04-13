/*
** my.h for core in Documents/annee_1/semestre_1/infographie/Others/entrainement
**
** Made by Antoine MOREL
** Login   <morel_j@epitech.net>
**
** Started on  Mon Dec 14 19:37:52 2015 Antoine MOREL
** Last update Mon Dec 14 19:37:52 2015 Antoine MOREL
*/

#include		"base.h"
#ifndef			MY_H_
# define		MY_H_

t_lapin			*set_lapin(t_lapin *lapin);
t_color			*set_color(int red, int green, int blue, int alpha);
void			background(t_bunny_pixelarray *pixelarray,
				   unsigned int color);
t_bunny_response	key(t_bunny_event_state state,
			    t_bunny_keysym keysysm, void *data);
void			blit_to_window(t_bunny_window *window,
				       t_bunny_pixelarray *pixelarray);
void			tekpixel(t_bunny_pixelarray *pix, t_bunny_position *pos,
				 t_color *color);
void			tekline(t_bunny_pixelarray *pix, t_bunny_position *pos,
				t_color *color, int size);
void			tekpixel_uns(t_bunny_pixelarray *pix, t_bunny_position *pos,
				     unsigned int color);
void			tekline_uns(t_bunny_pixelarray *pix, t_bunny_position *pos,
				    unsigned int color);
void			fill_interf(t_bunny_pixelarray *pix, int tools);
t_bunny_pixelarray	*load_bitmap(const char *file);
void			init_pixel_1(t_lapin *lapin);
void			rectangular_withpos(t_bunny_position *pos,
					    t_bunny_pixelarray *pix_palet,
					    unsigned int color);
t_bunny_pixelarray	*palet();
void			paint_square(t_bunny_position *pos, int radius,
				     t_bunny_pixelarray *pix, unsigned int color);
void			paint_circle(t_bunny_position *pos, int radius,
				     t_bunny_pixelarray *pix, t_color *color);
void			cpy_pixel(t_bunny_pixelarray *bmp,
				  t_bunny_pixelarray *pixelarray_1, int x, int y);
int			save_bitmap(const char *name_file,
				    t_bunny_pixelarray *pix);
int			save_file_ftn(t_bunny_pixelarray *pix,
				      char *name);
void			do_peinture(t_bunny_pixelarray *pix,
				    t_bunny_position  pos,
				    unsigned int colrep);
int			parse(int argc, char **argv);
t_bunny_pixelarray	*load_ftn(const char *file);
int			my_strcmp(char *s1, char *s2);
void			sepia(t_bunny_pixelarray *pix, char c);
unsigned int		what_major_bis(t_color color);
unsigned int		what_major(unsigned int colors);
void			black_and_white(t_bunny_pixelarray *pix);
void			free_all(t_lapin *lapin);
t_bunny_response	refresh_my_game(void *data);
void			size_bar(t_bunny_window *win,
                                 t_bunny_pixelarray *pix, int x, int y);
void			set_max_heap_size(size_t);
void			mouse_position(t_lapin *lapin);
t_bunny_position        pos_img(t_bunny_position pos);
void			change_color(t_lapin *lapin,
                                     t_bunny_pixelarray *pix, t_bunny_position *pos);
t_bunny_position	pos_img_color(t_bunny_position pos);
void			effect(t_lapin *lapin, t_bunny_position *pos);
void			new_size(t_lapin *lapin, t_bunny_position *pos);
void			palette(t_lapin *lapin,
                                t_bunny_pixelarray *pix, t_bunny_position *pos);
void			rubber(t_lapin *lapin, t_bunny_position *pos_fin);
void			pencil_draw(t_lapin *lapin,
                                    t_bunny_position *pos_fin, unsigned int colore);
void			trace_square(t_lapin *lapin,
                                     t_bunny_position *pos_fin, unsigned int colore);
void			cpy_tmp_2(t_bunny_pixelarray *pix_1,
                                  t_bunny_pixelarray *pix_2);
void			cpy_tmp_to_file(t_lapin *lapin, int sel);
void			trace_line(t_lapin *lapin,
                                   t_bunny_position *pos_fin, unsigned int colore);
void			action_button_bis(t_lapin *lp,
                                          t_bunny_position p_fin, t_bunny_position p);
void			action_button(t_lapin *lp,
                                      t_bunny_position p_fin, t_bunny_position p);
void			init_pixel_array(t_lapin *lapin);
void			init_bmp(t_lapin *lapin);

#endif			/* !MY_H_ */
