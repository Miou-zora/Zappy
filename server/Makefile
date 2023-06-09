##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## Makefile
##

SRC			=	parser/parse_args.c 			\
				parser/get_freq.c 				\
				parser/get_port.c 				\
				parser/get_width.c 				\
				parser/get_height.c 			\
				parser/get_names.c 				\
				parser/get_nb_client.c 			\
				initialize/initialize_trantorian.c\
				display_log.c 					\
				build/build_server.c			\
				run/run.c 						\
				run/handle_clients.c 			\
				client/client.c		 			\
				initialize/clan.c 				\
				initialize/map.c			 	\
				network/read.c					\
				network/write.c					\

OBJ			=	$(SRC:%.c=%.o)

MAIN		=	main.c

OBJ_MAIN	=	$(MAIN:%.c=%.o)

TESTS		=	tests/parse/tests_get_port.c 			\
				tests/parse/tests_get_freq.c 			\
				tests/parse/tests_get_height.c 			\
				tests/parse/tests_get_width.c 			\
				tests/parse/tests_get_nb_client.c 		\
				tests/parse/tests_get_names.c 			\
				tests/parse/tests_parse_args.c 			\
				tests/tests_build_server.c				\
				tests/server/network/tests_read.c		\
				tests/server/network/tests_write.c 		\

TESTS_OBJ	=	$(TESTS:%.c=%.o)

INCLUDE		=	-I./include \
				-I../utils/

CFLAGS		=	-Wall -Wextra -Werror -Wshadow

TEST_FLAGS	=	-lcriterion --coverage

NAME		=	zappy_server

TEST_BINARY	=	unit_tests

CC			=	gcc

MV			=	mv -f

%.o: %.c
		$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJ) $(OBJ_MAIN)
		$(CC) -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS) $(INCLUDE)

debug:			CFLAGS += -g
debug:			re

tests_run:		$(TESTS_OBJ)
		$(CC) -o $(TEST_BINARY) $(SRC) $(TESTS_OBJ) $(CFLAGS) $(TEST_FLAGS) \
		$(INCLUDE)
		./$(TEST_BINARY)
		gcovr -e tests
		gcovr -e tests -bu
		find . -type f -name '*.gcda' -exec $(MV) {} ./tests/ \;
		find . -type f -name '*.gcno' -exec $(MV) {} ./tests/ \;

clean:
		$(RM) $(OBJ)
		$(RM) $(TESTS_OBJ)
		$(RM) $(OBJ_MAIN)

fclean:			clean
		$(RM) $(NAME)
		$(RM) $(TEST_BINARY)
		$(RM) ./tests/*.gc*
		$(RM) *.gc*
tclean:
		@find . -type f -name '*.gcda' -exec $(RM) {} \;
		@find . -type f -name '*.gcno' -exec $(RM) {} \;
		$(RM) $(TEST_BINARY)

re:				fclean all

.PHONY: %.o all debug tests_run clean fclean tclean re
