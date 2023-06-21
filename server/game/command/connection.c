/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** connection
*/

#include "server.h"

void event_connection(event_t *event, zappy_t *zappy_s)
{
    response_t *response = NULL;

    if (event->client->is_connected && event->client->is_logged == false) {
        response = create_response("WELCOME\n");
        if (response == NULL)
            return;
        add_client_to_response(response, event->client);
        add_response_to_list(response, zappy_s);
    }
}
