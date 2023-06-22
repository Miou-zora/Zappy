/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** refill
*/

#pragma once
#include <stdbool.h>
#include "all_objects.h"
#include "game_struct.h"

/**
 * @brief Fill the map with objects (stones)
 * @param int pos[2] : position of the map tile for the stone
 * @param game_struct_t struct containing all the information about the game
 * @param trantorian_t struct all the information about the trantorian
 * @param map
 */
void check_and_add_stones_to_tiles(int pos[2], game_struct_t *game_struct,
    trantorian_t *trantorian);

/**
 * @brief generate a list of stones with their density and number of stones
 * @param x args of the server
 * @param y args of the server
 */
int **generate_stone_list(int x, int y);

/**
 * @brief malloc a tab array with the stones and their density
 * @return int **tab
 */
int **malloc_tab_array(void);

/**
 * @brief get the stone from the list
 * @param list_need_stones list of stones
 * @param i index of the stone
 * @return int stone
 */
int get_stone_from_list(int **list_need_stones, int i);
