/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** forward
*/

#include "server.h"
#include "trantorian.h"

void move_into_the_good_way(event_t *event, zappy_t *zappy, char *param)
{
    (void) param;

    void (*movement[4]) (event_t *event, zappy_t *zappy_s) = {
        move_up,
        move_right,
        move_down,
        move_left,
    };

    movement[event->client->trantorian->direction - 1](event, zappy);
}

void cmd_forward(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;

    add_command(event->client, FORWARD, 7, NULL);
}
