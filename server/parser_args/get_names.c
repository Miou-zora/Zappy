/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** server
*/

#include "server.h"

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
