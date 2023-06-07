/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** map
*/

#include "map.h"
#include <stdlib.h>

map_t *create_map(int width, int height)
{
    map_t *map = calloc(1, sizeof(map_t));

    map->width = width;
    map->height = height;
    map->tile = calloc(1, sizeof(object_t*) * (width * height));
    for (int i = 0; i < width * height; i++) {
        map->tile[i] = calloc(1, sizeof(object_t));
    }
    return (map);
}
