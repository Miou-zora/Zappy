##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## Makefile
##

SRC_PARSER	=	parser_args/parse_args.c 				\
				parser_args/get_freq.c 					\
				parser_args/get_port.c 					\
				parser_args/get_width.c 				\
				parser_args/get_height.c 				\
				parser_args/get_names.c 				\
				parser_args/get_nb_client.c 			\

SRC_DISPLAY = display/display_log.c 					\

SRC_GAME 	=	game/initialize/trantorian.c    		\
				game/initialize/egg.c 					\
				game/initialize/map.c			 		\
				game/initialize/clan.c 					\
				game/initialize/game_struct.c 			\
				game/gameloop.c 						\
				game/gameloop_check_special_event.c 	\
				game/command/forward.c 					\
				game/gui_protocol/gui_pnw.c				\
				game/command/move_functions.c 			\
				game/player_command.c 					\
				game/command/connection.c 				\
				game/command/turn.c 					\
				game/command/inventory.c 				\
				game/refill_obj/management_stone.c		\
				game/refill_obj/generation_list_stone.c \
				game/refill_obj/malloc_tab_array.c		\
				game/check_functions/check_functions.c  \
				game/gui_protocol/gui_msz.c				\
				game/gui_protocol/handle_event.c		\
				game/gui_protocol/gui_sgt.c				\
				game/gui_protocol/gui_mct.c				\
				game/gui_protocol/gui_bct.c				\
				game/gui_protocol/gui_tna.c				\
				game/manage_timer/update_players.c 		\

SRC_NETWORK =	network/build/build_server.c			\
				network/run/run.c 						\
				network/run/handle_clients.c 			\
				network/run/run_manage.c				\
				network/client/client.c		 			\
				network/event/event.c 					\
				network/utils_network/read.c			\
				network/utils_network/write.c			\
				network/utils_network/destroy_zappy.c 	\
				network/response/response.c				\

OBJ			=	$(SRC:%.c=%.o)
OBJ			+=	$(SRC_PARSER:%.c=%.o)
OBJ			+=	$(SRC_DISPLAY:%.c=%.o)
OBJ			+=	$(SRC_GAME:%.c=%.o)
OBJ			+=	$(SRC_NETWORK:%.c=%.o)

MAIN		=	main.c

OBJ_MAIN	=	$(MAIN:%.c=%.o)

TESTS_FOLDER=	../tests/tests_server/

TESTS_GAME 	=	../tests/game/

TESTS		=	$(TESTS_FOLDER)parse/tests_get_port.c 				 		 \
				$(TESTS_FOLDER)parse/tests_get_freq.c 				 		 \
				$(TESTS_FOLDER)parse/tests_get_height.c 				 	 \
				$(TESTS_FOLDER)parse/tests_get_width.c 				   		 \
				$(TESTS_FOLDER)parse/tests_get_nb_client.c 			 		 \
				$(TESTS_FOLDER)parse/tests_get_names.c 			   	 		 \
				$(TESTS_FOLDER)parse/tests_parse_args.c 				 	 \
				$(TESTS_FOLDER)tests_build_server.c					 		 \
				$(TESTS_FOLDER)event/tests_event.c					 		 \
				$(TESTS_FOLDER)management_struct/tests_egg_structure.c 		 \
				$(TESTS_FOLDER)management_struct/tests_trantorian_structure.c\
				$(TESTS_FOLDER)management_struct/tests_clan_structure.c 	 \
				$(TESTS_FOLDER)management_struct/tests_game_structure.c 	 \
				$(TESTS_FOLDER)server/network/tests_read.c			 		 \
				$(TESTS_FOLDER)server/network/tests_write.c 			 	 \
				$(TESTS_FOLDER)server/network/tests_response.c				 \
				$(TESTS_FOLDER)gui_protocol/gui_pnw.c				 		 \
				$(TESTS_FOLDER)AI_commands/tests_forward.c					 \
				$(TESTS_GAME)tests_stone.c 									 \
				$(TESTS_FOLDER)/event/tests_check_alive.c					 \
				$(TESTS_FOLDER)gui_protocol/gui_msz.c						 \
				$(TESTS_FOLDER)gui_protocol/gui_sgt.c					 	 \
				$(TESTS_FOLDER)gui_protocol/gui_mct.c				 	 	 \
				$(TESTS_FOLDER)gui_protocol/gui_bct.c			 	 	 	 \
				$(TESTS_FOLDER)gui_protocol/gui_tna.c			 	 	 	 \

TESTS_OBJ	=	$(TESTS:%.c=%.o)

INCLUDE		=	-I./include/game \
				-I./include/network \
				-I../utils/

CFLAGS		=	-Wall -Wextra -Werror -Wshadow -D_GNU_SOURCE

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
		$(CC) -o $(TEST_BINARY) $(SRC_PARSER) $(SRC_DISPLAY) $(SRC_GAME) \
		$(SRC_NETWORK) $(TESTS_OBJ) $(CFLAGS) $(TEST_FLAGS) $(INCLUDE)
		./$(TEST_BINARY)
		find . -type f -name '*.gcda' -exec $(MV) {} ./tests/ \;
		find . -type f -name '*.gcno' -exec $(MV) {} ./tests/ \;
		gcovr -e tests
		gcovr -e tests -bu

clean:
		$(RM) $(OBJ)
		$(RM) $(TESTS_OBJ)
		$(RM) $(OBJ_MAIN)

fclean:			tclean clean
		$(RM) $(NAME)
		$(RM) $(TEST_BINARY)
tclean:
		find . -type f -name '*.gcda' -exec $(RM) {} \;
		find . -type f -name '*.gcno' -exec $(RM) {} \;
		find . -type f -name '*.gcov' -exec $(RM) {} \;
		$(RM) $(TEST_BINARY)

re:				fclean all

.PHONY: %.o all debug tests_run clean fclean tclean re
