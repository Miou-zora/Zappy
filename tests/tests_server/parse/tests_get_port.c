/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_get_port
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test(getport_is_true, get_port)
{
    char *av[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "10", NULL};
    int value = get_port(av);
    cr_assert_eq(value, 4242);
}

Test(getport_is_false_0, get_port)
{
    char *av[] = {"./zappy_server", "-p", "0", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "10", NULL};
    int value = get_port(av);
    cr_assert_eq(value, 0);
}

Test(getport_is_false_letter, get_port)
{
    char *av[] = {"./zappy_server", "-p", "l", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "10", NULL};
    int value = get_port(av);
    cr_assert_neq(value, 1);
}

Test(getport_is_false_empty, get_port)
{
    char *av[] = {"./zappy_server", "-p", "", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "10", NULL};
    int value = get_port(av);
    cr_assert_neq(value, 1);
}

Test(getport_is_no_flag, get_port)
{
    char *av[] = {"./zappy_server", "99", "-x", "4", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int value = get_port(av);
    cr_assert_neq(value, 1);
}
