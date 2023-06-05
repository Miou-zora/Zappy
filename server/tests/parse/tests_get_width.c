/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_get_width
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test(getwidth_is_true, get_width)
{
    char *av[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "10", NULL};
    int value = get_width(av);
    cr_assert_eq(value, 10);
}

Test(getwidth_is_false_0, get_width)
{
    char *av[] = {"./zappy_server", "-p", "2", "-x", "0", "-y", "4",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int value = get_width(av);
    cr_assert_eq(value, 0);
}

Test(getwidth_is_false_letter, get_width)
{
    char *av[] = {"./zappy_server", "-p", "3", "-x", "x", "-y", "4",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int value = get_width(av);
    cr_assert_neq(value, 1);
}

Test(getwidth_is_false_empty, get_width)
{
    char *av[] = {"./zappy_server", "-p", "99", "-x", "", "-y", "4",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int value = get_width(av);
    cr_assert_neq(value, 1);
}

Test(getwidth_is_no_flag, get_width)
{
    char *av[] = {"./zappy_server", "-p", "99", "-y", "4",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int value = get_width(av);
    cr_assert_neq(value, 1);
}
