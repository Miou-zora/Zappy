/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** server
*/

#include "server.h"

void free_names(char **names)
{
    for (int i = 0; names[i] != NULL; i++) {
        free(names[i]);
    }
    free(names);
}

void parse_names(int argc, char** argv, int optind, argv_t* args)
{
    int i = 0;
    free_names(args->names);
    args->names = calloc(argc - optind + 1, sizeof(char*));
    for (i = optind; i < argc && argv[i][0] != '-'; i++) {
        args->names[i - optind] = strdup(argv[i]);
    }
    args->names[i - optind] = NULL;
}

char **send_names_by_default(char **names)
{
    names = calloc(5, sizeof(char *));
    names[0] = strdup("Team1");
    names[1] = strdup("Team2");
    names[2] = strdup("Team3");
    names[3] = strdup("Team4");
    names[4] = NULL;
    return (names);
}

char **get_names(int ac, char **av)
{
    char **names = NULL;
    bool is_name = false;
    int j = 0;

    for (int i = 0; av[i] != NULL; i++)
        if (strcmp(av[i], "-n") == 0)
            names = malloc(sizeof(char *) * (ac - i));
    for (int i = 1; av[i] != NULL; i++){
        if (strcmp(av[i], "-c") == 0)
            is_name = false;
        if ((strcmp(av[i - 1], "-n") == 0 || is_name == true)) {
            is_name = true;
            names[j] = malloc(sizeof(char) * strlen(av[i]) + 1);
            strcpy(names[j], av[i]);
            j++;
        }
    }
    names[j] = NULL;
    return (names);
}
