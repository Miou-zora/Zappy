/*
** EPITECH PROJECT, 2023
** Zappy-Mirror [WSL : Ubuntu]
** File description:
** count_stones
*/

#include "server.h"
#include "look.h"

static const char *elem_names[7] = {
    "food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"
    };

static char *fill_with_element(char *res, object_t *tile, int i)
{
    for (size_t j = 0; j < tile->nb_of_objects[i]; j++) {
        res = strcat(res, elem_names[i]);
        if (j != tile->nb_of_objects[i] - 1
            || tile->nb_of_objects[i + 1] != 0) {
            res = strcat(res, " ");
        }
    }
    return (res);
}

size_t size_to_alloc_look(client_t *client, zappy_t *zappy, vector_t cpos)
{
    vector_t ppos = {client->trantorian->position.x,
    client->trantorian->position.y};
    size_t size_to_alloc = 0;

    for (size_t i = 0; i <= (size_t)client->trantorian->level; i++) {
        for (size_t j = 0; j < 1 + (2 * i); j++) {
            vector_t tmp_vector = check_edges((int)(ppos.x - (int)i),
            (int)(ppos.y - (int)j), zappy->game_struct->map);
            size_to_alloc += size_to_alloc_tile(zappy->game_struct->map,
            tmp_vector.x, tmp_vector.y) + 2;
        }
        ppos.y += cpos.y;
        ppos.x += cpos.x;
    }
    return (size_to_alloc);
}

size_t size_to_alloc_tile(map_t *map, size_t x, size_t y)
{
    size_t size_to_alloc = 0;

    for (size_t i = 0; i < NUMBER_OF_DIFFERENT_ELEMENTS; i++) {
        if (map->tile[y][x].nb_of_objects[i] != 0) {
            size_to_alloc += strlen(elem_names[i]) *
                map->tile[y][x].nb_of_objects[i] + 1;
        }
    }
    return (size_to_alloc);
}

char *all_elements_at_tile(size_t x, size_t y, zappy_t *zappy)
{
    map_t *map = zappy->game_struct->map;
    char *res = calloc(size_to_alloc_tile(map, x, y) + 2, sizeof(char));

    if (res == NULL)
        return (NULL);
    for (size_t i = 0; i < NUMBER_OF_DIFFERENT_ELEMENTS; i++) {
        res = fill_with_element(res, &map->tile[y][x], i);
    }
    return (res);
}
