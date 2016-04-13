##
## Makefile for C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_my_exec2 in C:\Users\bapti\Documents\OneDrive\Documents\rendu\PSU_2015_my_exec2
##
## Made by baptiste mairesse
## Login   <bapti@epitech.net>
##
## Started on  Thu Mar 17 09:11:21 2016 baptiste mairesse
## Last update Thu Mar 17 09:11:21 2016 baptiste mairesse
##

NAME		= my_exec

SRC		= my_exec2.c \
				get_command.c


FLAG 		= -Wall -Wextra -ansi -pedantic -g3

all:			$(NAME)

$(NAME):
					clang -o $(NAME) $(SRC) libmy.a $(FLAG)

clean:
					rm -f *~

fclean:		clean
					rm -f $(NAME)

re: fclean all
