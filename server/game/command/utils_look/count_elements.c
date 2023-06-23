/*
** EPITECH PROJECT, 2023
** Zappy-Mirror [WSL : Ubuntu]
** File description:
** count_stones
*/

#include "server.h"

static char *copy_at_tile_in_buffer(size_t nb_elem, char *element)
{
    char *res = calloc(nb_elem * 2 * strlen(element), sizeof(char));
    int copy_idx = 0;

    for (size_t i = 0; i < nb_elem; i++, copy_idx += strlen(element) + 1) {
        memcpy(res + copy_idx, element, strlen(element));
        memcpy(res + copy_idx + strlen(element), " ", 1);
    }
    return (res);
}

char *all_elements_at_tile(size_t x, size_t y, zappy_t *zappy)
{
    map_t *map = zappy->game_struct->map;
    char *array[7] = {"food", "linemate", "deraumere", "sibur", "mendiane",
        "phiras", "thystame"};
    char *tmp = NULL;
    char *res = calloc(1, sizeof(char) * 1);
    size_t nb_elem = 0;

    for (size_t i = 0; i < NUMBER_OF_DIFFERENT_ELEMENTS; i++) {
        nb_elem = 0;
        if (map->tile[y][x].nb_of_objects[i] != 0) {
            nb_elem = map->tile[y][x].nb_of_objects[i];
            tmp = copy_at_tile_in_buffer(nb_elem, array[i]);
            res = realloc(res, sizeof(char) * (strlen(res) + strlen(tmp) + 2));
            strcat(res, tmp);
        }
    }
    return (res);
}
