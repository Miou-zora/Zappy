/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** get_freq
*/

#include "server.h"

int get_freq(char **av)
{
    for (int i = 0; av[i] != NULL; i++){
        if (strcmp(av[i], "-f") == 0 && av[i + 1] != NULL)
            return (atoi(av[i + 1]));
    }
    return (100);
}
