##
## Makefile for Makefile in /home/morel_j/Antoine/annee_1/semestre_1/infographie/Fil de fer 1/gfx_fdf1
## 
## Made by Antoine MOREL
## Login   <morel_j@epitech.net>
## 
## Started on  Sat Nov 21 12:52:33 2015 Antoine MOREL
## Last update Wed Dec  2 11:48:38 2015 Antoine MOREL
##

NAME		=	tekpaint

LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm

CFLAGS		=	-W -Wall -Werror -ansi -pedantic -g -I/home/${USER}/.froot/include/

SRC		=	main.c			\
			core.c			\
			tekpixel.c		\
			tekline.c		\
			tools.c			\
			tekline_uns.c		\
			bunny_free.c		\
			load_bitmap.c		\
			rectangular.c		\
			save_bitmap.c		\
			pot_peinture.c		\
			save_file_ftn.c		\
			my_strcmp.c		\
			unload_file_ftn.c	\
			parsing.c		\
			sepia.c			\
			shape_2.c		\
			for_norme.c		\
			main_next.c		\
			main_one.c		\
			main_two.c		\
			main_three.c		\
			core_next.c		\
			core_more.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJ)
			gcc $(OBJ) $(LIB) -o $(NAME)
clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:		fclean all

