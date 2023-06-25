/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** utils_position
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"

static int mod_x(int x, int width)
{
    x = x % width;
    if (x < 0)
        x += width;
    return (x);
}

static int mod_y(int y, int height)
{
    y = y % height;
    if (y < 0)
        y += height;
    return (y);
}

vector_t find_adjacent_pos_loop(vector_t pos_trantorian,
    vector_t cpos, map_t *map, trantorian_t *trantorian)
{
    while (!check_adjacent_position(pos_trantorian, trantorian->position)) {
        sleep(1);
        if (!is_adjacent_x(pos_trantorian, trantorian->position, cpos.x)) {
            pos_trantorian.x += cpos.x;
            pos_trantorian.x = mod_x(pos_trantorian.x, map->width);
        }
        if (!is_adjacent_y(pos_trantorian, trantorian->position, cpos.y)) {
            pos_trantorian.y += cpos.y;
            pos_trantorian.y = mod_y(pos_trantorian.y, map->height);
        }
    }
    return pos_trantorian;
}

vector_t select_increment_pos(vector_t pos_origin, vector_t pos_trantorian)
{
    vector_t res = {0, 0};

    res.x = pos_trantorian.x - pos_origin.x;
    res.y = pos_trantorian.y - pos_origin.y;
    return (res);
}

vector_t get_pos_trantorian(vector_t pos, trantorian_t *trantorian)
{
    vector_t pos_trantorian = {pos.x - trantorian->position.x,
        pos.y - trantorian->position.y};

    if (pos_trantorian.x < 0)
        pos_trantorian.x *= -1;
    if (pos_trantorian.y < 0)
        pos_trantorian.y *= -1;
    return (pos_trantorian);
}
