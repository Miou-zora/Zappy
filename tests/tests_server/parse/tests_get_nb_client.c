/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_get_nb_client
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test(getnb_client_is_true, get_nb_client)
{
    char *av[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "10", NULL};
    int value = get_nb_client(av);
    cr_assert_eq(value, 10);
}

Test(getnb_client_is_false_0, get_nb_client)
{
    char *av[] = {"./zappy_server", "-p", "2", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "0", "-f", "0", NULL};
    int value = get_nb_client(av);
    cr_assert_eq(value, 0);
}

Test(getnb_client_is_false_letter, get_nb_client)
{
    char *av[] = {"./zappy_server", "-p", "3", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "x", "-f", "x", NULL};
    int value = get_nb_client(av);
    cr_assert_neq(value, 1);
}

Test(getnb_client_is_false_empty, get_nb_client)
{
    char *av[] = {"./zappy_server", "-p", "99", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "", "-f", "", NULL};
    int value = get_nb_client(av);
    cr_assert_neq(value, 1);
}

Test(getnb_client_is_no_flag, get_nb_client)
{
    char *av[] = {"./zappy_server", "-p", "99", "-x", "4", "-y", "10",
        "-n", "toto", "10", "2", NULL};
    int value = get_nb_client(av);
    cr_assert_neq(value, 1);
}

Test(getnb_client_is_flag_no_next, get_nb_client)
{
    char *av[] = {"./zappy_server", "-p", "99", "-x", "4", "-y", "10",
        "-n", "toto", "-c", "-f", NULL};
    int value = get_nb_client(av);
    cr_assert_neq(value, 1);
}
