##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## Makefile
##

NAME	=	zappy_gui

all:
		cmake -S . -B build
		make -C build

debug:		all

tests_run:	all

clean:
		rm -rf build/

fclean: clean
		rm -f $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re tests_run
