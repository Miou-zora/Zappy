/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_msz
*/

#include "gui_protocol.h"

void gui_msz(event_t *event, zappy_t *zappy)
{
    char buffer[100] = {0};
    response_t *response = NULL;
    client_t *client = event->client;

    if (!client->is_graphic || !client->is_logged || !client->is_connected)
        return;
    sprintf(buffer, "msz %d %d\n", zappy->args->width, zappy->args->height);
    response = create_response(buffer);
    add_client_to_response(response, client);
    add_response_to_list(response, zappy);
}
