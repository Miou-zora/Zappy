/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** server
*/

#include "server.h"
#include <getopt.h>

static struct option long_options[] =
{
    {"port", required_argument, NULL, 'p'},
    {"width", required_argument, NULL, 'x'},
    {"height", required_argument, NULL, 'y'},
    {"names", required_argument, NULL, 'n'},
    {"clientsNb", required_argument, NULL, 'c'},
    {"freq", required_argument, NULL, 'f'},
    {NULL, 0, NULL, 0}
};

static void init_args(argv_t *args)
{
    args->port = 4242;
    args->width = 10;
    args->height = 10;
    args->names = send_names_by_default(args->names);
    args->clientsNb = 3;
    args->freq = 100;
}

static bool check_args(argv_t *args)
{
    if (args->port == -1)
        return (false);
    if (args->port == 0)
        args->port = (rand() % 65534 + 1);
    if (args->port <= 65535 && args->width >= 1 && args->names != NULL
        && args->height >= 1 && args->clientsNb >= 1 && args->freq >= 1)
        return (true);
    return (false);
}

static void switch_case_next(int argc, char **argv, int option, argv_t *args)
{
    switch (option) {
        case 'n':
            parse_names(argc, argv, optind - 1, args);
            break;
        case 'c':
            args->clientsNb = atoi(optarg);
            break;
        case 'f':
            args->freq = atoi(optarg);
            break;
        default:
            break;
    }
}

static void switch_case(int argc, char **argv, int option, argv_t *args)
{
    switch (option) {
        case 'p':
            if (atoi(optarg) >= 0 && atoi(optarg) <= 65535)
                args->port = atoi(optarg);
            else
                args->port = -1;
            break;
        case 'x':
            args->width = atoi(optarg);
            break;
        case 'y':
            args->height = atoi(optarg);
            break;
        default:
            switch_case_next(argc, argv, option, args);
            break;
    }
}

bool parse_args(int argc, char** argv, argv_t* args)
{
    int option = 0;
    int index = 0;

    init_args(args);
    while ((option = getopt_long(argc, argv, "p:x:y:n:c:f:",
    long_options, &index)) != -1) {
        switch_case(argc, argv, option, args);
    }
    if (!check_args(args)) {
        return (false);
    }
    printf("port: %d\n", args->port);
    return (true);
}
