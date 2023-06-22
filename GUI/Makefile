##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## Makefile
##

PROJECT_BINARY_NAME			=	zappy_gui

TESTS_BINARY_NAME			=	unitTests

all:
		cmake -S . -B build
		make -j 10 -C build

debug:			all

tests_run:		all
		./unitTests --verbose --full-stats

clean:
		rm -rf build/

fclean: 		clean
		rm -f $(PROJECT_BINARY_NAME)
		rm -f $(TESTS_BINARY_NAME)

re: 			fclean all

.PHONY: 		all clean fclean re tests_run
