/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** generation_list_stone
*/

#include "refill.h"

static int **set_stone_density(int x, int y, int **list_stone)
{
    list_stone[0][0] = LINEMATE;
    list_stone[0][1] = (x * y) * 0.3;
    list_stone[1][0] = DERAUMERE;
    list_stone[1][1] = (x * y) * 0.15;
    list_stone[2][0] = SIBUR;
    list_stone[2][1] = (x * y) * 0.1;
    list_stone[3][0] = MENDIANE;
    list_stone[3][1] = (x * y) * 0.1;
    list_stone[4][0] = PHIRAS;
    list_stone[4][1] = (x * y) * 0.08;
    list_stone[5][0] = THYSTAME;
    list_stone[5][1] = (x * y) * 0.05;
    return (list_stone);
}

int **generate_stone_list(int x, int y)
{
    int elem_stone = 6;
    int **list_stone = calloc(elem_stone, sizeof(int *));

    for (int i = 0; i < elem_stone; i++) {
        list_stone[i] = calloc(2, sizeof(int));
    }
    list_stone = set_stone_density(x, y, list_stone);
    return (list_stone);
}

int get_stone_from_list(int **list_need_stones, int i)
{
    int stone = list_need_stones[i][0];

    return (stone);
}
