/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** check_adjacent_position
*/

#include "game.h"

bool is_adjacent_x(vector_t pos_trantorian, vector_t pos_origin, int incr)
{
    int adjacent_x[] = {0, 1, -1};

    for (size_t i = 0; i < 3; i++) {
        if (pos_trantorian.x + incr == pos_origin.x + adjacent_x[i])
            return (true);
    }
    return (false);
}

bool is_adjacent_y(vector_t pos_trantorian, vector_t pos_origin, int incr)
{
    int adjacent_y[] = {0, 1, -1};

    for (size_t i = 0; i < 3; i++) {
        if (pos_trantorian.y + incr == pos_origin.y + adjacent_y[i])
            return (true);
    }
    return (false);
}

bool check_adjacent_position(vector_t pos_trantorian, vector_t pos_origin)
{
    vector_t adjacent_pos = {0, 0};
    vector_t tab_pos[] = {
        {.x = 0, .y = 1},
        {.x = 0, .y = -1},
        {.x = 1, .y = 0},
        {.x = -1, .y = 0},
        {.x = 1, .y = 1},
        {.x = -1, .y = -1},
        {.x = 1, .y = -1},
        {.x = -1, .y = 1}
    };

    for (size_t i = 0; i < 8; i++) {
        adjacent_pos.x = pos_origin.x + tab_pos[i].x;
        adjacent_pos.y = pos_origin.y + tab_pos[i].y;
        if (pos_trantorian.x == adjacent_pos.x
            && pos_trantorian.y == adjacent_pos.y)
            return (true);
    }
    return (false);
}
