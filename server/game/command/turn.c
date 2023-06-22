/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** turn
*/

#include "server.h"
#include "game.h"

void set_func_left(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;
    add_command(event->client, 7, move_left, NULL);
}

void set_func_right(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;

    add_command(event->client, 7, move_right, NULL);
}

void move_left(client_t *client, zappy_t *zappy, char *param)
{
    (void) param;

    if (client->trantorian->direction == UP)
        client->trantorian->direction = LEFT;
    else
        client->trantorian->direction -= 1;
    response_t *response = create_response("ok\n");
    add_client_to_response(response, client);
    add_response_to_list(response, zappy);
}

void move_right(client_t *client, zappy_t *zappy, char *param)
{
    (void) param;

    if (client->trantorian->direction == LEFT)
        client->trantorian->direction = UP;
    else
        client->trantorian->direction += 1;
    response_t *response = create_response("ok\n");
    add_client_to_response(response, client);
    add_response_to_list(response, zappy);
}
