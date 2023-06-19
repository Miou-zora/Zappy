/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_sgt
*/

#include "gui_protocol.h"
#include "server.h"

void notifie_gui_sgt(client_t *client, zappy_t *zappy)
{
    char buffer[100] = {0};
    response_t *response = NULL;

    if (!client->is_graphic || !client->is_logged || !client->is_connected)
        return;
    sprintf(buffer, "sgt %d\n", zappy->args->freq);
    response = create_response(buffer);
    if (response == NULL)
        return;
    add_client_to_response(response, client);
    add_response_to_list(response, zappy);
}

void handle_gui_sgt(event_t *event, zappy_t *zappy)
{
    notifie_gui_sgt(event->client, zappy);
}
