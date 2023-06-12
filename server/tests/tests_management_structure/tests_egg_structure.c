/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_create_egg_structure
*/

#include <criterion/criterion.h>
#include "egg.h"

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
