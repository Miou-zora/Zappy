##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## Makefile
##

NAME					=	zappy_gui

BINARY_NAME				=	unitTests

FTCUBE_NAME				=	ftCube

FTSCENE_NAME			=	ftScene

FTOBJLOADER_NAME		=	ftObjLoader

FTSENPAI				=	ftSenpai

all:
		cmake -S . -B build
		make -j 10 -C build

debug:			all

tests_run:		all
		./unitTests --verbose --full-stats

clean:
		rm -rf build/

fclean: 		clean
		rm -f $(NAME)
		rm -f $(BINARY_NAME)
		rm -f $(FTCUBE_NAME)
		rm -f $(FTSCENE_NAME)
		rm -f $(FTOBJLOADER_NAME)
		rm -f $(FTSENPAI)

re: 			fclean all

.PHONY: 		all clean fclean re tests_run
