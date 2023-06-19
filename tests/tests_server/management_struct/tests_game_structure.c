/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_game_structure
*/

#include <criterion/criterion.h>
#include "game_struct.h"
#include "server.h"

Test(init_game_struct, test_create_egg)
{
    argv_t *args = calloc(1, sizeof(argv_t));
    args->height = 10;
    args->width = 10;
    args->freq = 100;
    game_struct_t *game_struct = init_game_struct(args);

    cr_assert_eq(game_struct->map->width, 10);
    cr_assert_eq(game_struct->map->height, 10);
    cr_assert_eq(game_struct->time_unit, 100);
    cr_assert_eq(game_struct->all_clans.lh_first, NULL);
    cr_assert_eq(game_struct->all_eggs.lh_first, NULL);
}

Test(add_object_at_tile, test_add_object_at_tile)
{
    argv_t *args = calloc(1, sizeof(argv_t));
    args->height = 10;
    args->width = 10;
    args->freq = 100;
    game_struct_t *game_struct = init_game_struct(args);

    add_object_at_tile(game_struct->map, FOOD, 0, 0);
    cr_assert_eq(game_struct->map->tile[0]->nb_of_objects[FOOD], 1);
    add_object_at_tile(game_struct->map, LINEMATE, 0, 0);
    cr_assert_eq(game_struct->map->tile[0]->nb_of_objects[LINEMATE], 1);
    add_object_at_tile(game_struct->map, DERAUMERE, 0, 0);
    cr_assert_eq(game_struct->map->tile[0]->nb_of_objects[DERAUMERE], 1);
    add_object_at_tile(game_struct->map, SIBUR, 0, 0);
    cr_assert_eq(game_struct->map->tile[0]->nb_of_objects[SIBUR], 1);
    add_object_at_tile(game_struct->map, MENDIANE, 0, 0);
    cr_assert_eq(game_struct->map->tile[0]->nb_of_objects[MENDIANE], 1);
    add_object_at_tile(game_struct->map, PHIRAS, 0, 0);
    cr_assert_eq(game_struct->map->tile[0]->nb_of_objects[PHIRAS], 1);
    add_object_at_tile(game_struct->map, THYSTAME, 0, 0);
    cr_assert_eq(game_struct->map->tile[0]->nb_of_objects[THYSTAME], 1);
}

Test(fill_map, test_fill_map)
{
    argv_t *args = calloc(1, sizeof(argv_t));
    args->height = 10;
    args->width = 10;
    args->freq = 100;
    int count_object = 0;
    game_struct_t *game_struct = init_game_struct(args);
    int nb_of_object = game_struct->map->height * game_struct->map->width * 0.5; // for food

    fill_map(game_struct->map);
    for (int i = 0; i < 100; i++) {
        count_object += game_struct->map->tile[i]->nb_of_objects[FOOD];
    }
    cr_assert_eq(count_object, nb_of_object);
}

Test(fill_map, test_fill_map_thystame)
{
    argv_t *args = calloc(1, sizeof(argv_t));
    args->height = 10;
    args->width = 10;
    args->freq = 100;
    int count_object = 0;
    game_struct_t *game_struct = init_game_struct(args);
    int nb_of_object = game_struct->map->height * game_struct->map->width * 0.05;

    fill_map(game_struct->map);
    for (int i = 0; i < 100; i++) {
        count_object += game_struct->map->tile[i]->nb_of_objects[THYSTAME];
    }
    cr_assert_eq(count_object, nb_of_object);
}


Test(fill_map, test_fill_map_thystame_small_map)
{
    argv_t *args = calloc(1, sizeof(argv_t));
    args->height = 10;
    args->width = 5;
    args->freq = 100;
    int count_object = 0;

    game_struct_t *game_struct = init_game_struct(args);
    float nb_of_object = game_struct->map->height * game_struct->map->width * THYSTAME_DENSITY;
    nb_of_object /= 1000;
    int tmp = (int) nb_of_object;
    tmp += (tmp < nb_of_object) ? 1 : 0;
    fill_map(game_struct->map);
    for (int i = 0; i < 50; i++) {
        count_object += game_struct->map->tile[i]->nb_of_objects[THYSTAME];
    }
    cr_assert_eq(count_object, tmp);
}