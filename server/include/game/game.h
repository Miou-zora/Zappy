/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** game.h
*/

#pragma once
#include "server.h"
#include "look.h"

/**
 * @brief Set the func forward object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void set_func_forward(event_t *event, zappy_t *zappy);

/**
 * @brief forward move up
 *
 * @param client the client who is moving
 * @param zappy_s the struct containing every information about the server
 */
void forward_move_up(client_t *client, zappy_t *zappy);

/**
 * @brief forward move right
 *
 * @param client the client who is moving
 * @param zappy_s the struct containing every information about the server
 */
void forward_move_right(client_t *client, zappy_t *zappy);

/**
 * @brief forward move down
 *
 * @param client the client who is moving
 * @param zappy_s the struct containing every information about the server
 */
void forward_move_down(client_t *client, zappy_t *zappy);

/**
 * @brief forward move left
 *
 * @param client the client who is moving
 * @param zappy_s the struct containing every information about the server
 */
void forward_move_left(client_t *client, zappy_t *zappy);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void set_func_left(event_t *event, zappy_t *zappy_s);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void set_func_right(event_t *event, zappy_t *zappy_s);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void move_right(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void move_left(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void set_func_inventory(event_t *event, zappy_t *zappy_s);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void send_inventory(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief add incantation function on command array's player
 *
 * @param event
 * @param zappy_s
 */
void set_func_incantation(event_t *event, zappy_t *zappy_s);

/**
 * @brief make incantation of the player
 *
 * @param event
 * @param zappy
 * @param param
 */
void do_incantation(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief connect nbr command function pointer
 *
 * @param client the client who is moving
 * @param zappy_s the struct containing every information about the server
 */
void connect_nbr(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief Set the func connect nbr object (connect_nbr command)
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void set_func_connect_nbr(event_t *event, zappy_t *zappy_s);

/**
 * @brief Set the func take_object
 *
 * @param event
 * @param zappy_s
 */
void set_func_take_object(event_t *event, zappy_t *zappy_s);

/**
 * @brief player take object on the tile
 *
 * @param event
 * @param zappy
 * @param param
 */
void take_object(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief check if the player have one of the object
 *
 * @param param
 */
int get_object_index(const char* param);

/**
 * @brief Set the func set_object
 *
 * @param event
 * @param zappy_s
 */
void set_object(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief Set the func set_object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void set_func_fork(event_t *event, zappy_t *zappy_s);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void do_fork(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void set_func_set_object(event_t *event, zappy_t *zappy_s);

/**
 * @brief Create a clans object
 *
 * @param game the game struct
 * @param args the args struct
 * @return ** int 0 if success 84 if error
 */
int create_clans(game_struct_t *game, argv_t *args);

/*
 * @brief eject players on the tile
 *
 * @param event
 * @param zappy
 * @param param
 */
void do_eject(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief Set the func eject
 *
 * @param event the event
 * @param zappy_s the struct containing every information about the server
 */
void set_func_eject(event_t *event, zappy_t *zappy_s);

/**
 * @brief move trantorians on the opposite tile of player
 *
 * @param trantorian
 * @param tile
 * @param game
 */
bool push_player(client_t *client, zappy_t *zappy);

/**
 * @brief check if the tile is on the edge of the map
 *
 * @param x
 * @param y
 * @param map
 */
vector_t check_edges(int x, int y, map_t *map);

/**
 * @brief will add a comma at the end of the buffer
 *
 * @param buffer the buffer to add the comma
 * @return ** void
 */
void add_comma_to_buffer(char *buffer);

/*
 * @brief update the life of trantorian
 *
 * @param trantorian
 * @param zappy
 */
void update_trantorian_life(trantorian_t *trantorian, zappy_t *zappy);
