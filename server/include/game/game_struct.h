/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** game_struct
*/

#pragma once
#include "egg.h"
#include "clan.h"
#include "map.h"

typedef struct argv_s argv_t;

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

/**
 * @brief generate eggs on map
 *
 * @param zappy_t
 */
void generate_spawn_eggs(zappy_t *zappy);

/**
 * @brief add clan to list
 * it will be added at the end of the list
 * @param game_struct the game_struct
 * @param clan the clan to add
 * @return ** void
 */
void add_clan_to_list(game_struct_t *game_struct, clan_t *clan);

/**
 * @brief add clan member to list
 * it will be added at the end of the list
 * @param clan the clan
 * @param clan_member the clan_member to add
 * @return ** void
 */
void add_clan_member_to_list(clan_t *clan, clan_member_t *clan_member);
