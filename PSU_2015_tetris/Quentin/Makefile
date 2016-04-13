NAME		= tetris

SRC		=	tetris.c\
			flag.c \
			aff.c\
			aff_tetris.c\

FLAG 		= -Wall -Wextra -ansi -pedantic -g3

all:			$(NAME)

$(NAME):
					gcc -o $(NAME) $(SRC) libmy.a $(FLAG) -lncurses

clean:
					rm -f *~

fclean:		clean
					rm -f $(NAME)

re: fclean all
