/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** get_nb_client
*/

#include "server.h"

int get_nb_client(char **av)
{
    for (int i = 0; av[i] != NULL; i++){
        if (strcmp(av[i], "-c") == 0)
            return(atoi(av[i + 1]));
    }
    return (0);
}
