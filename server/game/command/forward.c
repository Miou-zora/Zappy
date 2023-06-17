/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** forward
*/

#include "server.h"

void cmd_forward(event_t *event, zappy_t *zappy_s)
{
    response_t *response = NULL;

    response = create_response("ok\n");
    add_client_to_response(response, event->client);
    add_response_to_list(response, zappy_s);
}
