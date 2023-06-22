/*
** EPITECH PROJECT, 2023
** Zappy-Mirror [WSL : Ubuntu]
** File description:
** look
*/

#pragma once
#include "server.h"

/**
 * @brief look at the tile in front of the player
 *
 * @param event the event
 * @param zappy the struct containing every information about the server
 * @param param the param
 */
void look_tile(client_t *client, zappy_t *zappy, char *param);

/**
 * @brief Set the func look object
 *
 * @param event the event
 * @param zappy the struct containing every information about the server
 */
void set_func_look(event_t *event, zappy_t *zappy);

/**
 * @brief look up
 *
 * @param event the event
 * @param zappy the struct containing every information about the server
 * @return char* the string containing the look
 */
char *look_up(client_t *client, zappy_t *zappy);

/**
 * @brief look down
 *
 * @param event the event
 * @param zappy the struct containing every information about the server
 * @return char* the string containing the look
 */
char *look_down(client_t *client, zappy_t *zappy);

/**
 * @brief look right
 *
 * @param event the event
 * @param zappy the struct containing every information about the server
 * @return char* the string containing the look
 */
size_t nb_of_trantorians_at_pos(size_t x, size_t y, zappy_t *zappy);

/**
 * @brief look down
 *
 * @param event the event
 * @param zappy the struct containing every information about the server
 * @return char* the string containing the look
 */
size_t nb_of_eggs_at_pos(size_t x, size_t y, zappy_t *zappy);

/**
 * @brief look left
 *
 * @param event the event
 * @param zappy the struct containing every information about the server
 * @return char* the string containing the look
 */
char *look_at_tile(size_t x, size_t y, zappy_t *zappy);

/**
 * @brief look at the tile in front of the player
 *
 * @param event the event
 * @param zappy the struct containing every information about the server
 * @param param the param
 */
char *all_elements_at_tile(size_t x, size_t y, zappy_t *zappy);

/**
 * @brief look at the tile in front of the player
 *
 * @param event the event
 * @param zappy the struct containing every information about the server
 * @param param the param
 */
char *rm_spaces_before_coma(char *str);

/**
 * @brief add the coma to the string
 *
 * @param first_size the size of the first string
 * @param i the i
 * @param j the j
 * @param res the string to add the coma
 */
char *add_the_coma(size_t first_size, size_t i, size_t j, char *res);

/**
 * @brief add the hook to the string
 *
 * @param str the string to add the hook
 */
char *add_hook(char *str);

/**
 * @brief check if the position is out of the map
 *
 * @param x the x
 * @param y the y
 * @param game the struct containing every information about the server
 */
vector_t check_edges(int x, int y, game_struct_t *game);

/**
 * @brief look at the tile in front of the player
 *
 * @param event the event
 * @param zappy the struct containing every information about the server
 * @param param the param
 */
char *look_left(client_t *client, zappy_t *zappy);

/**
 * @brief look at the tile in front of the player
 *
 * @param event the event
 * @param zappy the struct containing every information about the server
 * @param param the param
 */
char *look_right(client_t *client, zappy_t *zappy);
