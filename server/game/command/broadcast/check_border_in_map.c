/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** update distance for all clients
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"

static void adjust_position_on_border_y(vector_t *increment_pos,
    vector_t *pos_trantorian, map_t *map)
{
    if (pos_trantorian->x == 0 && pos_trantorian->y > map->height / 2) {
        pos_trantorian->y = map->height - pos_trantorian->y;
        increment_pos->y *= -1;
    }
}

static void adjust_position_on_border_x(vector_t *increment_pos,
    vector_t *pos_trantorian, map_t *map)
{
    if (pos_trantorian->y == 0 && pos_trantorian->x > map->width / 2) {
        pos_trantorian->x = map->width - pos_trantorian->x;
        increment_pos->x *= -1;
    }
}

static void adjust_position_on_right_border(vector_t *increment_pos,
    vector_t *pos_trantorian, map_t *map)
{
    if (pos_trantorian->x > map->width / 2) {
        increment_pos->x *= -1;
        pos_trantorian->x = map->width - pos_trantorian->x;
    }
}

static void adjust_position_on_left_border(vector_t *increment_pos,
    vector_t *pos_trantorian, map_t *map)
{
    if (pos_trantorian->y > map->height / 2) {
        increment_pos->y *= -1;
        pos_trantorian->y = map->height - pos_trantorian->y;
    }
}

void check_border_in_map(vector_t *increment_pos, vector_t *pos_trantorian,
    map_t *map)
{
    adjust_position_on_border_y(increment_pos, pos_trantorian, map);
    adjust_position_on_border_x(increment_pos, pos_trantorian, map);
    adjust_position_on_right_border(increment_pos, pos_trantorian, map);
    adjust_position_on_left_border(increment_pos, pos_trantorian, map);
}
