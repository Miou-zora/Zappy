/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_parse_args
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test(parse_args_is_true_multi, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "4242", "-x", "10", "-y", "10",
        "-n", "toto", "tata", "-c", "10", "-f", "2", NULL};
    int ac = 15;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(value, true);
}

Test(parse_args_is_false, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-", "4242", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int ac = 15;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(value, false);
}

Test(parse_args_is_false_flag, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "0", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int ac = 15;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(value, false);
}


Test(parse_args_is_false_flag2, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "2", "-y", "0",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int ac = 15;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(value, false);
}

Test(parse_args_is_false_flag3, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "2", "-y", "2",
        "-n", "toto", "-c", "10", "-f", "0", NULL};
    int ac = 15;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(value, false);
}

Test(parse_args_is_false_flag4, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "2", "-y", "2",
        "-n", "toto", "-c", "0", "-f", "2", NULL};
    int ac = 15;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(value, false);
}

Test(parse_args_is_false_flag5, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "7000000", "-x", "2", "-y", "2",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int ac = 15;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(value, false);
}

Test(parse_args_is_false_flag6, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "2", "-y", "2",
        "-n", "\0", "-c", "10", "-f", "2", NULL};
    int ac = 15;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(value, false);
}