/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** server
*/

#include "server.h"

int get_port(char **av)
{
    for (int i = 0; av[i] != NULL; i++){
        if (strcmp(av[i], "-p") == 0)
            return (atoi(av[i + 1]));
    }
    return (4242);
}
