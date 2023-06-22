/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** forward command
*/

#include "server.h"
#include "game.h"

void move_forward(client_t *client, zappy_t *zappy, char *param)
{
    (void) param;
    void (*movement[4]) (client_t *client, zappy_t *zappy_s) = {
        forward_move_up,
        forward_move_right,
        forward_move_down,
        forward_move_left,
    };

    movement[client->trantorian->direction - 1](client, zappy);
}

void set_func_forward(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;

    add_command(event->client, 7, move_forward, NULL);
}
