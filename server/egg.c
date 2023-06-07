/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** egg
*/

#include "server.h"
#include "egg.h"
#include "vector.h"

void add_egg(egg_t *egg, int pos_x, int pos_y, char *team_name)
{
    egg->pos.x = pos_x;
    egg->pos.y = pos_y;
    egg->team_name = strdup(team_name);
}