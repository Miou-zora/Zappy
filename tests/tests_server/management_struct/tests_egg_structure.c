/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_create_egg_structure
*/

#include <criterion/criterion.h>
#include "game_struct.h"

Test(create_egg_structure, test_create_egg_structure)
{
    egg_t *egg = create_egg(1, 2, "team", 1);

    cr_assert_eq(egg->pos.x, 1);
    cr_assert_eq(egg->pos.y, 2);
    cr_assert_str_eq(egg->team_name, "team");
    cr_assert_eq(egg->id, 1);
}

Test(create_egg_structure, test_create_egg_chained_list)
{
    struct egg_head head = create_egg_chained_list();

    cr_assert_eq(LIST_EMPTY(&head), 1);
}

Test(create_egg_structure, test_add_egg_to_chained_list)
{
    struct egg_head head = create_egg_chained_list();
    egg_t *egg = create_egg(1, 2, "team", 1);

    LIST_INSERT_HEAD(&head, egg, next_egg);
    cr_assert_eq(LIST_EMPTY(&head), 0);
    cr_assert_eq(LIST_FIRST(&head), egg);
    cr_assert_eq(strcmp(egg->team_name, "team"), 0);
    cr_assert_eq(egg->pos.x, 1);
}

Test(create_egg_structure, test_remove_egg_from_chained_list)
{
    struct egg_head head = create_egg_chained_list();
    egg_t *egg = create_egg(1, 2, "team", 1);

    LIST_INSERT_HEAD(&head, egg, next_egg);
    LIST_REMOVE(egg, next_egg);
    cr_assert_eq(LIST_EMPTY(&head), 1);
}

Test(generate_spawn_eggs, test_spawn_egg)
{
    argv_t *args = calloc(1, sizeof(argv_t));
    args->height = 10;
    args->width = 10;
    args->freq = 100;
    game_struct_t *game_struct = init_game_struct(args);
    egg_t *egg = NULL;
    clan_t *clan = create_clan(3, "team");
    clan_t *clan2 = create_clan(3, "team2");

    int count = 0;

    LIST_INSERT_HEAD(&game_struct->all_clans, clan, next_clan);
    LIST_INSERT_HEAD(&game_struct->all_clans, clan2, next_clan);
    generate_spawn_eggs(game_struct);

    for (size_t i = 0; i < (size_t)game_struct->map->height * game_struct->map->width; i++) {
        LIST_FOREACH(egg, &(game_struct->all_eggs), next_egg) {
            if (egg->pos.x == i % game_struct->map->width &&
                egg->pos.y == i / game_struct->map->width)
                count++;
        }
    }
    cr_assert_eq(count, 6);
}
