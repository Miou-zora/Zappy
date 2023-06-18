/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** move_functions
*/

#include "server.h"
#include "trantorian.h"

void move_up(event_t *event, zappy_t *zappy)
{
    response_t *response = NULL;

    if (event->client->trantorian->position.y > 0)
            event->client->trantorian->position.y -= 1;
    else
        event->client->trantorian->position.y = (size_t) zappy->args->height
            - 1;
    response = create_response("ok\n");
    add_client_to_response(response, event->client);
    add_response_to_list(response, zappy);
}

void move_down(event_t *event, zappy_t *zappy)
{
    response_t *response = NULL;

    if (event->client->trantorian->position.y < (size_t) zappy->args->height
        - 1)
        event->client->trantorian->position.y += 1;
    else
        event->client->trantorian->position.y = 0;
    response = create_response("ok\n");
    add_client_to_response(response, event->client);
    add_response_to_list(response, zappy);
}

void move_left(event_t *event, zappy_t *zappy)
{
    response_t *response = NULL;

    if (event->client->trantorian->position.x > 0)
        event->client->trantorian->position.x -= 1;
    else
        event->client->trantorian->position.x = (size_t) zappy->args->width - 1;
    response = create_response("ok\n");
    add_client_to_response(response, event->client);
    add_response_to_list(response, zappy);
}

void move_right(event_t *event, zappy_t *zappy)
{
    response_t *response = NULL;

    if (event->client->trantorian->position.x < (size_t) zappy->args->width - 1)
        event->client->trantorian->position.x += 1;
    else
        event->client->trantorian->position.x = 0;
    response = create_response("ok\n");
    add_client_to_response(response, event->client);
    add_response_to_list(response, zappy);
}
