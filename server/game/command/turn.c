/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** turn
*/

#include "server.h"

void cmd_left(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;

    add_command(event->client, TURN_LEFT, 7, NULL);
}

void cmd_right(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;

    add_command(event->client, TURN_RIGHT, 7, NULL);
}

void left(event_t *event, zappy_t *zappy, char *param)
{
    (void) param;

    if (event->client->trantorian->direction == UP)
        event->client->trantorian->direction = LEFT;
    else
        event->client->trantorian->direction -= 1;
    response_t *response = create_response("ok\n");
    add_client_to_response(response, event->client);
    add_response_to_list(response, zappy);
}

void right(event_t *event, zappy_t *zappy, char *param)
{
    (void) param;

    if (event->client->trantorian->direction == LEFT)
        event->client->trantorian->direction = UP;
    else
        event->client->trantorian->direction += 1;
    response_t *response = create_response("ok\n");
    add_client_to_response(response, event->client);
    add_response_to_list(response, zappy);
}
