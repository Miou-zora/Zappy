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