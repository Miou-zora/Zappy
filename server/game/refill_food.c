/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** check_spawn_food
*/

#include "trantorian.h"
#include "game_struct.h"
#include "server.h"

static void add_food_at_tile(map_t *map, float nb_food)
{
    while (nb_food / (float)(map->width * map->height) != 0.5) {
        int random_x = rand() % map->width;
        int random_y = rand() % map->height;
        map->tile[random_x][random_y].nb_of_objects[FOOD] += 1;
    }
}

void update_spawn_food(zappy_t *zappy)
{
    float nb_food = 0;

    for (int i = 0; i < zappy->game_struct->map->width; i++) {
        for (int j = 0; j < zappy->game_struct->map->height; j++) {
            nb_food += zappy->game_struct->map->tile[i][j].nb_of_objects[FOOD];
        }
    }
    if (nb_food / (float)(zappy->game_struct->map->width *
        zappy->game_struct->map->height) < 0.5) {
        add_food_at_tile(zappy->game_struct->map, nb_food);
    }
}
