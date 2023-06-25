/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** get_direction_broadcast
*/

#include "game.h"

static int get_direction_820(int dy)
{
    if (dy < 0)
        return (8);
    else if (dy > 0)
        return (2);
    else
        return (0);
    return (0);
}

static int get_direction_914(int dx, int dy)
{
    if (dx > 0)
        return (get_direction_820(dy));
    if (dy < 0)
        return (9);
    else if (dy > 0)
        return (1);
    else
        return (4);
    return (get_direction_820(dy));
}

static int get_direction_736(int dx, int dy)
{
    if (dx < 0)
        return (get_direction_914(dx, dy));
    if (dy < 0)
        return (7);
    else if (dy > 0)
        return (3);
    else
        return (6);
    return (get_direction_914(dx, dy));
}

int get_direction_broadcast(vector_t pos_trantorian, vector_t pos_origin)
{
    int dx = pos_trantorian.x - pos_origin.x;
    int dy = pos_trantorian.y - pos_origin.y;

    if (dx == 0 && dy == 0)
        return (0);
    return (get_direction_736(dx, dy));
}
