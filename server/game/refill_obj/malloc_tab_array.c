/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** get_stone
*/

#include "refill.h"

int **malloc_tab_array(void)
{
    int **tmp = calloc(6, sizeof(int *));

    for (int i = 0; i < 6; i++) {
        tmp[i] = calloc(1, sizeof(int));
    }
    *(tmp[0]) = LINEMATE;
    *(tmp[1]) = DERAUMERE;
    *(tmp[2]) = SIBUR;
    *(tmp[3]) = MENDIANE;
    *(tmp[4]) = PHIRAS;
    *(tmp[5]) = THYSTAME;
    return (tmp);
}
