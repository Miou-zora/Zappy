/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** utils_position
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"

vector_t select_increment_pos(vector_t pos_origin, vector_t pos_trantorian)
{
    vector_t increment_pos = {0, 0};

    if (pos_origin.x < pos_trantorian.x)
        increment_pos.x = 1;
    else if (pos_origin.x > pos_trantorian.x)
        increment_pos.x = -1;
    if (pos_origin.y < pos_trantorian.y)
        increment_pos.y = 1;
    else if (pos_origin.y > pos_trantorian.y)
        increment_pos.y = -1;
    return (increment_pos);
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
