/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_sgt
*/

#include "gui_protocol.h"
#include "server.h"

void gui_sgt(event_t *event, zappy_t *zappy)
{
    char buffer[1024] = {0};
    response_t *response = NULL;

    if (!event->client->is_graphic || !event->client->is_connected)
        return;
    sprintf(buffer, "sgt %d\n", zappy->args->freq);
    response = create_response(buffer);
    if (response == NULL)
        return;
    add_client_to_response(response, event->client);
    add_response_to_list(response, zappy);
}
