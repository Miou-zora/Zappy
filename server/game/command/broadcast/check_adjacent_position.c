/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** check_adjacent_position
*/

#include "game.h"

bool check_adjacent_position(vector_t pos_trantorian, vector_t pos_origin)
{
    vector_t adjacent_pos = {0, 0};
    vector_t tab_pos[] = {
        {0, 1},
        {0, -1},
        {1, 0},
        {-1, 0},
        {1, 1},
        {-1, -1},
        {1, -1},
        {-1, 1}
    };

    for (size_t i = 0; i < sizeof(tab_pos) / sizeof(tab_pos[0]); i++) {
        adjacent_pos.x = pos_origin.x + tab_pos[i].x;
        adjacent_pos.y = pos_origin.y + tab_pos[i].y;
        if (pos_trantorian.x == adjacent_pos.x
            && pos_trantorian.y == adjacent_pos.y)
            return (true);
    }
    return (false);
}
