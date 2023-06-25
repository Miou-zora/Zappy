/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** game_struct
*/

#include "server.h"
#include "game_struct.h"
#include "game.h"

const int ELEMENTS_DENSITIES[] = {FOOD_DENSITY, LINEMATE_DENSITY,
    DERAUMERE_DENSITY, SIBUR_DENSITY, MENDIANE_DENSITY,
    PHIRAS_DENSITY, THYSTAME_DENSITY};


game_struct_t *init_game_struct(argv_t *args)
{
    game_struct_t *game_struct = calloc(1, sizeof(game_struct_t));

    if (game_struct == NULL)
        return (NULL);
    game_struct->map = create_map(args->width, args->height);
    if (game_struct->map == NULL || create_clans(game_struct, args) == 84)
        return (NULL);
    game_struct->all_eggs = create_egg_chained_list();
    game_struct->time_unit = args->freq;
    fill_map(game_struct->map);
    return (game_struct);
}

void fill_map(map_t *map)
{
    float nb_objects = 0;
    size_t tmp = 0;

    for (size_t i = FOOD; i < NUMBER_OF_DIFFERENT_ELEMENTS; i++) {
        nb_objects = ((float)(ELEMENTS_DENSITIES[i]
        * map->height *map->width)) / 1000;
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
    map->tile[y][x].nb_of_objects[type] += 1;
    return (true);
}

static vector_t rand_spawn_egg(vector_t pos, map_t *map)
{
    pos.x = rand() % map->width;
    pos.y = rand() % map->height;
    if (pos.x == 0)
        pos.x += 1;
    if (pos.y == 0)
        pos.y += 1;
    return (pos);
}

void generate_spawn_eggs(zappy_t *zappy)
{
    clan_t *clan = NULL; response_t *response = NULL;
    vector_t pos = {0, 0}; egg_t *egg = NULL;
    char buf[1024] = {0};

    LIST_FOREACH(clan, &(zappy->game_struct->all_clans), next_clan) {
        pos = rand_spawn_egg(pos, zappy->game_struct->map);
        for (size_t i = 0; i < clan->max_nb_of_members; i++) {
            egg = create_egg(pos.x, pos.y, clan->name,
                zappy->game_struct->nb_eggs + 1);
            LIST_INSERT_HEAD(&(zappy->game_struct->all_eggs), egg, next_egg);
            if (sprintf(buf, "enw %d -1 %d %d\n",
                egg->id, egg->pos.x, egg->pos.y) < 0)
                return;
            response = create_response(buf);
            send_response_to_all_gui_clients(response, zappy);
            zappy->game_struct->nb_eggs += 1;
            pos = rand_spawn_egg(pos, zappy->game_struct->map);
        }
    }
}
