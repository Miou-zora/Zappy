/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_get_freq
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test(getfreq_is_true, get_freq)
{
    char *av[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "10", NULL};
    int value = get_freq(av);
    cr_assert_eq(value, 10);
}

Test(getfreq_is_false_0, get_freq)
{
    char *av[] = {"./zappy_server", "-p", "2", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "0", NULL};
    int value = get_freq(av);
    cr_assert_eq(value, 0);
}

Test(getfreq_is_false_letter, get_freq)
{
    char *av[] = {"./zappy_server", "-p", "3", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "x", NULL};
    int value = get_freq(av);
    cr_assert_neq(value, 1);
}

Test(getfreq_is_false_empty, get_freq)
{
    char *av[] = {"./zappy_server", "-p", "99", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "", NULL};
    int value = get_freq(av);
    cr_assert_neq(value, 1);
}

Test(getfreq_is_no_flag, get_freq)
{
    char *av[] = {"./zappy_server", "-p", "99", "-x", "4", "-y", "10",
        "-n", "toto", "-c", "10", "2", NULL};
    int value = get_freq(av);
    cr_assert_neq(value, 1);
}

Test(getfreq_is_flag_no_next, get_freq)
{
    char *av[] = {"./zappy_server", "-p", "99", "-x", "4", "-y", "10",
        "-n", "toto", "-c", "10", "-f", NULL};
    int value = get_freq(av);
    cr_assert_neq(value, 1);
}
