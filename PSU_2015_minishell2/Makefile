##
## Makefile for C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_minishell2
##
## Made by	Baptiste Mairesse
## Login	maires_b
##
## Started on	Tue Apr 12 16:02:45 2016 Baptiste Mairesse
## Last update	Tue Apr 12 16:02:45 2016 Baptiste Mairesse
##

CC = gcc

RM = rm -f

CFLAGS = -Wall -Wextra -ansi -pedantic -g3 -Werror
LDFLAGS += $(CFLAGS)
NAME = mysh

LIB = lib/libmy.a

SRCS = 	src/mysh.c \
	src/get_env.c \
	src/super_free.c \
	src/multi_comand.c \
	src/get_path.c \
	src/fctn_prompt.c \
	src/get_command.c \
	src/builtins.c \
	src/check.c \
	src/exe.c \
	src/set_env.c \
	src/unset_env.c \
	src/parsing.c \
	src/exe_sub_command.c \
	src/list.c \
	src/pwd.c \
	src/my_fcnt.c \
	src/do_redir.c \
	src/env_tool.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIB) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
