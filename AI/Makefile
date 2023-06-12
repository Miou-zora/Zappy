##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## Makefile
##

all:

debug:

tests_run:
	python3 -m unittest discover -s tests

clean:
		find . | grep -E "(__pycache__|\.pyc|\.pyo)" | xargs rm -rf


fclean: 	clean

re: 		fclean all

.PHONY: 	all clean fclean re tests_run
