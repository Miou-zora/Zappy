/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_get_height
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test(getheight_is_true, get_height)
{
    char *av[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "10", NULL};
    int value = get_height(av);
    cr_assert_eq(value, 10);
}

Test(getheight_is_false_0, get_height)
{
    char *av[] = {"./zappy_server", "-p", "2", "-x", "3", "-y", "0",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int value = get_height(av);
    cr_assert_eq(value, 0);
}

Test(getheight_is_false_letter, get_height)
{
    char *av[] = {"./zappy_server", "-p", "3", "-x", "3", "-y", "a",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int value = get_height(av);
    cr_assert_neq(value, 1);
}

Test(getheight_is_false_empty, get_height)
{
    char *av[] = {"./zappy_server", "-p", "99", "-x", "5", "-y", "",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int value = get_height(av);
    cr_assert_neq(value, 1);
}

Test(getheight_is_no_flag, get_height)
{
    char *av[] = {"./zappy_server", "-p", "99", "-x", "4",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int value = get_height(av);
    cr_assert_neq(value, 1);
}
