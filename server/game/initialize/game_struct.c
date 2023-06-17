/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** game_struct
*/

#include "server.h"
#include "game_struct.h"

const int ELEMENTS_DENSITIES[] = {FOOD_DENSITY, LINEMATE_DENSITY,
    DERAUMERE_DENSITY, SIBUR_DENSITY, MENDIANE_DENSITY,
    PHIRAS_DENSITY, THYSTAME_DENSITY};


game_struct_t *init_game_struct(argv_t *args)
{
    game_struct_t *game_struct = calloc(1, sizeof(game_struct_t));

    if (game_struct == NULL)
        return (NULL);
    game_struct->map = create_map(args->width, args->height);
    game_struct->all_clans = create_clan_chained_list();
    game_struct->all_eggs = create_egg_chained_list();
    game_struct->time_unit = args->freq;
    return (game_struct);
}

void fill_map(map_t *map)
{
    float nb_objects = 0;
    size_t tmp = 0;

    for (size_t i = FOOD; i < NUMBER_OF_DIFFERENT_ELEMENTS; i++) {
        nb_objects = ((float)(ELEMENTS_DENSITIES[i] * map->height *
            map->width)) / 1000;
        tmp = (int) nb_objects;
        if (tmp < nb_objects)
            tmp += 1;
        for ( size_t j = 0; j < tmp; j++) {
            add_object_at_tile(map, i, rand() % map->width,
                rand() % map->height);
        }
    }
}

bool add_object_at_tile(map_t *map, enum ELEMENTS type, size_t x, size_t y)
{
    int pos = x + y * map->width;

    if (pos > map->height * map->width - 1)
        return (false);
    map->tile[pos]->nb_of_objects[type] += 1;
    return (true);
}
