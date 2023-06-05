##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## Makefile
##

all: 		zappy_gui zappy_server

zappy_server:
		make -C server/
		cp ./server/zappy_server ./zappy_server

zappy_gui:
		make -C GUI/
		cp ./GUI/zappy_gui ./zappy_gui

zappy_ai:

debug:
		make -C server/ debug
		make -C GUI/ debug
		make -C AI/ debug

tests_run:
		make -C server/ tests_run
		make -C GUI/ tests_run
		make -C AI/ tests_run

clean:
		make -C server/ clean
		make -C GUI/ clean
		make -C AI/ clean

fclean:
		make -C server/ fclean
		make -C GUI/ fclean
		make -C AI/ fclean
		rm -f zappy_server
		rm -f zappy_gui

re:
		make -C server/ re
		make -C GUI/ re
		make -C AI/ re
		cp ./server/zappy_server ./zappy_server
		cp ./GUI/zappy_gui ./zappy_gui

.PHONY:		all debug tests_run clean fclean re zappy_server zappy_gui zappy_ai
