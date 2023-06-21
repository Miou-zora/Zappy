/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** check_inventory_lvl
*/

#include "server.h"
#include "trantorian.h"

size_t **initialize_inventory(void)
{
    size_t **inventory_lvl = calloc(7, sizeof(size_t *));
    size_t second_lvl[] = {1, 1, 0, 0, 0, 0, 0};
    size_t third_lvl[] = {2, 1, 1, 1, 0, 0, 0};
    size_t fourth_lvl[] = {2, 2, 0, 1, 0, 2, 0};
    size_t fifth_lvl[] = {4, 1, 1, 2, 0, 1, 0};
    size_t sixth_lvl[] = {4, 1, 2, 1, 3, 0, 0};
    size_t seventh_lvl[] = {6, 1, 2, 3, 0, 1, 0};
    size_t eighth_lvl[] = {6, 2, 2, 2, 2, 2, 1};
    size_t *levels[] = { second_lvl, third_lvl, fourth_lvl, fifth_lvl,
        sixth_lvl, seventh_lvl,eighth_lvl
    };

    for (size_t i = 0; i < 7; i++) {
        inventory_lvl[i] = malloc(sizeof(size_t) * 7);
        memcpy(inventory_lvl[i], levels[i], sizeof(size_t) * 7);
    }
    return inventory_lvl;
}

size_t *copy_inventory_level(size_t **inventory_lvl, int level,
    size_t *level_values)
{
    memcpy(level_values, inventory_lvl[level], sizeof(size_t) * 7);
    return level_values;
}
