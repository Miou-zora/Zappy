##
## EPITECH PROJECT, 2023
## Zappy-Mirror
## File description:
## Makefile
##

SRC_PARSER	=	parser_args/parse_args.c 									\
				parser_args/get_freq.c 										\
				parser_args/get_port.c 										\
				parser_args/get_width.c 									\
				parser_args/get_height.c 									\
				parser_args/get_names.c 									\
				parser_args/get_nb_client.c 								\

SRC_DISPLAY = display/display_log.c 										\

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
				game/gui_protocol/gui_msz.c				\
				game/gui_protocol/handle_event.c		\
				game/gui_protocol/gui_sgt.c				\
				game/gui_protocol/gui_mct.c				\
				game/gui_protocol/gui_bct.c				\
				game/gui_protocol/gui_tna.c				\
				game/gui_protocol/gui_plv.c				\
				game/command/utils_look/count_elements.c\
				game/command/utils_look/utils_look.c	\
				game/command/utils_look/look.c			\
				game/command/utils_look/look_functions.c\
				game/command/utils_look/look_right_and_left.c \
		       	game/command/connect_nbr.c              \
				game/gui_protocol/gui_ppo.c				\
				game/command/incantation/do_incantation.c  					\
				game/command/incantation/init_truth_table.c 				\
				game/command/incantation/check_incantation.c 				\
				game/command/take_object/take_object.c 						\
				game/command/take_object/take_object_check_object.c			\
				game/command/set_object.c 									\
				game/command/eject/eject.c 									\
				game/command/eject/move_trantorians.c						\
				game/gui_protocol/gui_pin.c									\
				game/manage_timer/update_players.c 							\
				game/initialize/clans_lists.c								\
				game/initialize/create_list_clans.c							\
				game/command/fork.c											\
				game/gui_protocol/gui_pdi.c 			\
				game/gui_protocol/gui_pex.c 			\
				game/gui_protocol/gui_pgt.c 			\
				game/gui_protocol/gui_pfk.c 			\
				game/gui_protocol/gui_pdr.c 			\
				game/gui_protocol/gui_pbc.c 			\
				game/gui_protocol/gui_sbp.c				\
				game/gui_protocol/gui_suc.c 			\
				game/command/broadcast/do_broadcast.c				\
				game/command/broadcast/update_distance_for_all_clients.c 	\
				game/command/broadcast/utils_position.c		\
				game/command/broadcast/check_adjacent_position.c		\
				game/command/broadcast/get_direction_broadcast.c		\
				game/command/broadcast/check_border_in_map.c		\
				game/gui_protocol/gui_ebo.c 			\
				game/gui_protocol/gui_pic.c 			\
				game/gui_protocol/gui_edi.c 			\
				game/gui_protocol/gui_enw.c 			\
				game/gui_protocol/gui_seg.c 			\
				game/gui_protocol/gui_sst.c 			\
				game/check_function/check_win.c			\

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
				network/response/insert_response.c		\
				network/client/clients_list.c			\

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
				$(TESTS_FOLDER)AI_commands/tests_incantation.c				 \
				$(TESTS_FOLDER)AI_commands/tests_take_object.c				 \
				$(TESTS_FOLDER)AI_commands/tests_set_object.c				 \
				$(TESTS_FOLDER)AI_commands/tests_fork.c						 \
				$(TESTS_GAME)tests_stone.c 									 \
				$(TESTS_FOLDER)/event/tests_check_alive.c					 \
				$(TESTS_FOLDER)gui_protocol/gui_msz.c						 \
				$(TESTS_FOLDER)gui_protocol/gui_sgt.c					 	 \
				$(TESTS_FOLDER)gui_protocol/gui_mct.c				 	 	 \
				$(TESTS_FOLDER)gui_protocol/gui_bct.c			 	 	 	 \
				$(TESTS_FOLDER)gui_protocol/gui_tna.c			 	 	 	 \
				$(TESTS_FOLDER)AI_commands/tests_look.c			 	 	 	 \
				$(TESTS_FOLDER)gui_protocol/gui_pin.c			 	 	 	 \
				$(TESTS_FOLDER)gui_protocol/gui_pdi.c 						 \
				$(TESTS_FOLDER)gui_protocol/gui_pgt.c 						 \
				$(TESTS_FOLDER)gui_protocol/gui_pbc.c 						 \

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
