/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** server
*/

#include "server.h"

static void init_args(argv_t *args)
{
    args->port = 0;
    args->width = 0;
    args->height = 0;
    args->names = NULL;
    args->clientsNb = 0;
    args->freq = 0;
}

static bool check_args(argv_t *args)
{
    if (args->port >= 1 && args->port <= 65535 && args->width >= 1
        && args->height >= 1 && args->names[0][0] != '\0'
        && args->clientsNb >= 1 && args->freq >= 1)
        return (true);
    else
        return (false);
}

bool parse_args(int ac, char **av, argv_t *args)
{
    init_args(args);
    args->port = get_port(av);
    args->width = get_width(av);
    args->height = get_height(av);
    args->clientsNb = get_nb_client(av);
    args->freq = get_freq(av);
    args->names = get_names(ac, av);
    if (check_args(args) == false)
        return (false);
    return (true);
}
