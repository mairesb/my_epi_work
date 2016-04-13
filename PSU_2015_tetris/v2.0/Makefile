NAME		= tetris

SRC		= tetris.c\
		  flag.c \
			aff.c \
			get_tetri.c \
			get_tetrimino/aff.c \
			get_tetrimino/main.c \
			game.c \
			windows.c \
			map_update.c \
			fctn.c \
			mvt.c \
			test_pos.c \
			line_or_not.c


FLAG 		= -Wall -Wextra -ansi -pedantic -g3 -lncurses

all:			$(NAME)

$(NAME):
					clang -o $(NAME) $(SRC) libmy.a $(FLAG)

clean:
					rm -f *~

fclean:		clean
					rm -f $(NAME)

re: fclean all
