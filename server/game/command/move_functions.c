/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** move_functions
*/

#include "server.h"
#include "trantorian.h"

void forward_move_up(client_t *client, zappy_t *zappy)
{
    response_t *response = NULL;

    if (client->trantorian->position.y > 0)
        client->trantorian->position.y -= 1;
    else
        client->trantorian->position.y = (size_t) zappy->args->height - 1;
    response = create_response("ok\n");
    add_client_to_response(response, client);
    add_response_to_list(response, zappy);
}

void forward_move_down(client_t *client, zappy_t *zappy)
{
    response_t *response = NULL;

    if (client->trantorian->position.y < zappy->args->height - 1)
        client->trantorian->position.y += 1;
    else
        client->trantorian->position.y = 0;
    response = create_response("ok\n");
    add_client_to_response(response, client);
    add_response_to_list(response, zappy);
}

void forward_move_left(client_t *client, zappy_t *zappy)
{
    response_t *response = NULL;

    if (client->trantorian->position.x > 0)
        client->trantorian->position.x -= 1;
    else
        client->trantorian->position.x = zappy->args->width - 1;
    response = create_response("ok\n");
    add_client_to_response(response, client);
    add_response_to_list(response, zappy);
}

void forward_move_right(client_t *client, zappy_t *zappy)
{
    response_t *response = NULL;

    if (client->trantorian->position.x < zappy->args->width - 1)
        client->trantorian->position.x += 1;
    else
        client->trantorian->position.x = 0;
    response = create_response("ok\n");
    add_client_to_response(response, client);
    add_response_to_list(response, zappy);
}
