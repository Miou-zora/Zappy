/*
** EPITECH PROJECT, 2023
** Zappy-Mirror [WSL : Ubuntu]
** File description:
** look
*/

#pragma once
#include "server.h"

/**
 * @brief struct containing every information about the look
 * allowing the code to be more readable
 *
 * @param res the string containing the look
 * @param ppos the player position
 * @param cpos the corrected position
 * @param correction the correction vector
 * @param tile the tile
 * @param direction the direction
 */
typedef struct look_s {
    char *res;
    vector_t ppos;
    vector_t cpos;
    vector_t correction;
    char *tile;
    enum DIRECTION direction;
} look_t;

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
size_t nb_of_trantorians_at_pos(int x, int y, zappy_t *zappy);

/**
 * @brief look down
 *
 * @param event the event
 * @param zappy the struct containing every information about the server
 * @return char* the string containing the look
 */
size_t nb_of_eggs_at_pos(int x, int y, zappy_t *zappy);

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

/**
* @brief look a the tile in x and y
then send back the size to alloc for the string
*/
size_t size_to_alloc_tile(map_t *map, size_t x, size_t y);

/**
 * @brief check if the position is in the map
 * if not, it will reset the position
 *
 * @param x the x
 * @param y the y
 * @param map the map
 * @return vector_t the vector
 */
vector_t check_edges(int x, int y, map_t *map);

/**
 * @brief fetch the size needed to store the data from the look
 *
 * @param client the client
 * @param zappy the struct containing every information about the server
 * @param cpos the math vector to calculate the pos
 * @return size_t* the size to alloc
 */
size_t size_to_alloc_look(client_t *client, zappy_t *zappy, vector_t cpos);

/**
 * @brief create the string containing the look
 * @param client the client
 * @param zappy the struct containing every information about the server
 * @param cpos the math vector to calculate the pos
 */
char *send_look(client_t *client, zappy_t *zappy, vector_t cpos);
