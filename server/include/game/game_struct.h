/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** game_struct
*/

#pragma once
#include "server.h"
#include "egg.h"
#include "clan.h"
#include "map.h"

#define NUMBER_OF_DIFFERENT_ELEMENTS 7

/**
 * @brief Declarate game_struct
 * @param struct egg_head
 * @param struct clan_head
 * @param struct map_t
 * @param int time_unit
 */
typedef struct game_struct_s {
    struct egg_head all_eggs;
    struct clan_head all_clans;
    int nb_trantorians;
    int nb_eggs;
    map_t *map;
    int time_unit;
} game_struct_t;

/**
 * @brief initialize game_struct
 *
 * @return game_struct_t*
 */
game_struct_t *init_game_struct(argv_t *args);

/**
 * @brief free game_struct
 *
 * @param game_struct
 */
void free_game_struct(game_struct_t *game_struct);

extern const int ELEMENTS_DENSITIES[];

/**
 * @brief fill map with objects
 *
 * @param map_struct
 */
void fill_map(map_t *map);

/**
 * @brief add object at tile
 *
 * @param map
 * @param object
 * @param x
 * @param y
 */
bool add_object_at_tile(map_t *map, enum ELEMENTS type, size_t x, size_t y);
