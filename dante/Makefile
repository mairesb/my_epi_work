##
## Makefile for C:\Users\bapti\Documents\OneDrive\Documents\rendu\dante in C:\Users\bapti\Documents\OneDrive\Documents\rendu\dante
##
## Made by baptiste mairesse
## Login   <bapti@epitech.net>
##
## Started on  Sat Mar 12 17:10:44 2016 baptiste mairesse
## Last update Sat Mar 12 17:10:44 2016 baptiste mairesse
##

NAME		= dante

SRC		= main.c


FLAG 		= -Wall -Wextra -ansi -pedantic -g3

all:			$(NAME)

$(NAME):
					clang -o $(NAME) $(SRC) libmy.a $(FLAG)

clean:
					rm -f *~

fclean:		clean
					rm -f $(NAME)

re: fclean all
