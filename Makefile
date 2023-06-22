##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## Makefile
##

is_fedora := $(shell lsb_release -si 2>/dev/null)

all: 		zappy_gui zappy_server

install:
	    @which dnf > /dev/null 2>&1 || \
		(echo "DNF package manager not found"; exit 1)
		dnf install -y alsa-lib-devel mesa-libGL-devel libX11-devel \
		libXrandr-devel libXi-devel libXcursor-devel libXinerama-devel \
		libatomic
		git clone https://github.com/raysan5/raylib.git raylib
		mkdir raylib/build
		cmake -S raylib -B raylib/build -DBUILD_SHARED_LIBS=ON
		make -C raylib/build
		make -C raylib/build install
		rm -rf raylib

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

funct_test:
		./tests/tests_server/server/supervisor.sh 5555 100

.PHONY:	all debug tests_run clean fclean re zappy_server zappy_gui zappy_ai \
		funct_test
