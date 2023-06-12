/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_trantorian_structure
*/

#include <criterion/criterion.h>
#include "trantorian.h"


Test(trantorian, create_trantorian)
{
    egg_t *egg = create_egg(1, 1, "test", 1);
    trantorian_t *trantorian = create_trantorian(egg);

    cr_assert_eq(trantorian->level, 1);
    cr_assert_eq(trantorian->life, 10);
    cr_assert_eq(trantorian->position.x, 1);
    cr_assert_eq(trantorian->position.y, 1);
    cr_assert_eq(trantorian->is_incanting, false);
    cr_assert_eq(trantorian->is_dead, false);
    cr_assert_eq(trantorian->is_egging, false);
    cr_assert_eq(trantorian->inventory->nb_of_objects[FOOD], 0);
    cr_assert_eq(trantorian->inventory->nb_of_objects[LINEMATE], 0);
    cr_assert_eq(trantorian->inventory->nb_of_objects[DERAUMERE], 0);
    cr_assert_eq(trantorian->inventory->nb_of_objects[SIBUR], 0);
    cr_assert_eq(trantorian->inventory->nb_of_objects[MENDIANE], 0);
    cr_assert_eq(trantorian->inventory->nb_of_objects[PHIRAS], 0);
    cr_assert_eq(trantorian->inventory->nb_of_objects[THYSTAME], 0);
}

Test(trantorian, create_trantorian_chained_list)
{
    struct trantorian_head head = create_trantorian_chained_list();

    cr_assert_eq(LIST_EMPTY(&head), true);
}

Test(trantorian, create_egg_chained_list)
{
    struct egg_head head = create_egg_chained_list();

    cr_assert_eq(LIST_EMPTY(&head), true);
}
