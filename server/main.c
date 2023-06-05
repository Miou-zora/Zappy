/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** main
*/

#include "server.h"

int main(int ac, char **av)
{
    argv_t *args = malloc(sizeof(argv_t));

    if (ac >= 13 && parse_args(ac, av, args) == true) {
        return (0);
    } else {
        return (84);
    }
    return (0);
}
