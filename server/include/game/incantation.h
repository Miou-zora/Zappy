/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** incantation.h
*/

#pragma once
#include "server.h"

/**
 * @brief set the level_values for compare with the inventory
 *
 * @param level the level of the player
 * @param level_values the level_values
 * @param zappy the struct containing all the informations about the server
 */
size_t *copy_inventory_level(size_t **inventory_lvl, int level,
    size_t *level_values);

/**
 * @brief check the inventory of the player and compare with the level_values
 *
 * @param size_t **inventory_lvl the level_values
 * @param level the level of the player
 * @param player the player who send the command
 */
bool check_inventory_trantorian(client_t *client, size_t *level_values);

/**
 * @brief initialize the inventory_lvl
 *
 * @param client the client who send the command
 * @param zappy the struct containing all the informations about the server
 * @param param the parameters of the command
 */
size_t **initialize_inventory(void);

/**
 * @brief check if the players are on the same tile
 *
 * @param client the client who send the command
 * @param zappy the struct containing all the informations about the server
 * @param param the parameters of the command
 */
bool check_players_on_tile(client_t *client, zappy_t *zappy,
    size_t *level_values);
