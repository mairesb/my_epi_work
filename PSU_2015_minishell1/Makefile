NAME		= mysh

SRC		= mysh.c \
				get_env.c \
				super_free.c \
				get_path.c \
				fctn_prompt.c \
				get_command.c \
				builtins.c \
				check.c \
				exe.c \
				set_env.c \
				unset_env.c \
				env_tool.c


FLAG 		= -Wall -Wextra -ansi -pedantic -g3

all:			$(NAME)

$(NAME):
					clang -o $(NAME) $(SRC) libmy.a $(FLAG)

clean:
					rm -f *~

fclean:		clean
					rm -f $(NAME)

re: fclean all
