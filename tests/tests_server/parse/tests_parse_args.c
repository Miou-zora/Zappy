/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_parse_args
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "server.h"

Test(parse_args_is_port_default, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-x", "10", "-y", "10",
        "-n", "toto", "tata", "-c", "10", "-f", "2", NULL};
    int ac = 12;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(args->port, 4242);
    cr_assert_eq(value, true);
}

Test(parse_args_is_port_false, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "-4242", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int ac = 13;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(args->port, -1);
    cr_assert_eq(value, false);
}

Test(parse_args_is_port_true, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "90", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int ac = 13;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(args->port, 90);
    cr_assert_eq(value, true);
}

Test(parse_args_is_port_random, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "0", "-x", "10", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int ac = 13;
    int port = 0;

    bool value = parse_args(ac, av, args);
    port = args->port;
    cr_assert_eq(args->port, port);
    cr_assert_eq(value, true);
}

Test(parse_args_is_width_no_flag, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int ac = 11;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(args->width, 10);
    cr_assert_eq(value, true);
}

Test(parse_args_is_width_false, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "4", "-x", "0", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int ac = 13;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(args->width, 0);
    cr_assert_eq(value, false);
}

Test(parse_args_is_width_true, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "4", "-x", "5", "-y", "10",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int ac = 13;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(args->width, 5);
    cr_assert_eq(value, true);
}

Test(parse_args_is_height_false, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "2", "-y", "0",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int ac = 13;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(args->height, 0);
    cr_assert_eq(value, false);
}

Test(parse_args_is_height_no_flag, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "2",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int ac = 11;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(args->height, 10);
    cr_assert_eq(value, true);
}

Test(parse_args_is_freq_false, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "2", "-y", "2",
        "-n", "toto", "-c", "10", "-f", "0", NULL};
    int ac = 13;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(args->freq, 0);
    cr_assert_eq(value, false);
}

Test(parse_args_is_freq_true, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "2", "-y", "2",
        "-n", "toto", "-c", "10", "-f", "50", NULL};
    int ac = 13;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(args->freq, 50);
    cr_assert_eq(value, true);
}

Test(parse_args_is_freq_no_flag, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "2", "-y", "2",
        "-n", "toto", "-c", "10", NULL};
    int ac = 11;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(args->freq, 100);
    cr_assert_eq(value, true);
}

Test(parse_args_is_client_false, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "2", "-y", "2",
        "-n", "toto", "-c", "0", "-f", "2", NULL};
    int ac = 13;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(args->clientsNb, 0);
    cr_assert_eq(value, false);
}

Test(parse_args_is_client_true, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "2", "-y", "2",
        "-n", "toto", "-c", "10", "-f", "2", NULL};
    int ac = 13;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(args->clientsNb, 10);
    cr_assert_eq(value, true);
}

Test(parse_args_is_client_no_flag, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "2", "-y", "2",
        "-n", "toto", "-f", "2", NULL};
    int ac = 11;

    bool value = parse_args(ac, av, args);
    cr_assert_eq(args->clientsNb, 3);
    cr_assert_eq(value, true);
}

Test(parse_args_is_names_no_flag, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "2", "-y", "2",
        "-f", "2", NULL};
    char *test[] = {"Team1", "Team2", "Team3", "Team4", NULL};
    int ac = 9;

    bool value = parse_args(ac, av, args);
    cr_assert_str_eq(args->names[0], test[0]);
    cr_assert_str_eq(args->names[1], test[1]);
    cr_assert_str_eq(args->names[2], test[2]);
    cr_assert_str_eq(args->names[3], test[3]);
    cr_assert_eq(value, true);
}

Test(parse_args_is_names_true, parse_args)
{
    argv_t *args = malloc(sizeof(argv_t));
    char *av[] = {"./zappy_server", "-p", "5", "-x", "2", "-n", "toto", "-y", "2",
        "-f", "2", NULL};
    char *test[] = {"toto", NULL};
    int ac = 9;

    bool value = parse_args(ac, av, args);
    cr_assert_str_eq(args->names[0], test[0]);
    cr_assert_eq(value, true);
}
