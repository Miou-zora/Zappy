/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** get_width
*/

#include "server.h"

int get_width(char **av)
{
    for (int i = 0; av[i] != NULL; i++){
        if (strcmp(av[i], "-x") == 0)
            return (atoi(av[i + 1]));
    }
    return (0);
}
