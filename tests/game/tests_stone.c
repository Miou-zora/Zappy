/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_stone
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "refill.h"

Test(malloc_tab_array_is_good, malloc_tab_array)
{
    int **tmp = malloc_tab_array();

    cr_assert_eq(*(tmp[0]), LINEMATE);
    cr_assert_eq(*(tmp[1]), DERAUMERE);
    cr_assert_eq(*(tmp[2]), SIBUR);
    cr_assert_eq(*(tmp[3]), MENDIANE);
    cr_assert_eq(*(tmp[4]), PHIRAS);
    cr_assert_eq(*(tmp[5]), THYSTAME);
}
