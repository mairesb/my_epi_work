##
## Makefile for C:\Users\Baptiste\Documents\Dropbox\rendu in C:\Users\Baptiste\Documents\Dropbox\rendu\mystic_2020
##
## Made by baptiste mairesse
## Login   <Baptiste@epitech.net>
##
## Started on  Thu Feb 11 09:12:50 2016 baptiste mairesse
## Last update Thu Feb 11 09:12:50 2016 baptiste mairesse
##

CC		=	gcc
NAME		=	template
LIB		=	-L/home/${USER}/.froot/lib/ -llapin \
			-L/usr/local/lib \
			-lsfml-audio \
			-lsfml-graphics \
			-lsfml-window \
			-lsfml-system \
			-lstdc++ -ldl \
			-lm
FLAG		=	-W -Wall -ansi -pedantic -I/home/${USER}/.froot/include/
SRC		=	tekcircle.c \
			mystic_clock.c \
			tekpixel.c \
			main.c

OBJ		=	$(SRC:.c=.o)

all:		$(NAME)
$(NAME):	$(OBJ)
		$(CC) $(SRC) $(LIB) -o $(NAME)
clean:
		rm -f $(OBJ)
fclean:		clean
		rm -f $(NAME)
re:		fclean all
.c.o:
		$(CC) -c $< -o $@ $(FLAG)
