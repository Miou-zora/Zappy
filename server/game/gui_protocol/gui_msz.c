/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_msz
*/

#include "gui_protocol.h"

void notifie_gui_msz(client_t *client, zappy_t *zappy)
{
    char buffer[100] = {0};
    response_t *response = NULL;

    if (!client->is_graphic || !client->is_logged || !client->is_connected)
        return;
    sprintf(buffer, "msz %d %d\n", zappy->args->width, zappy->args->height);
    response = create_response(buffer);
    if (response == NULL)
        return;
    send_response_to_all_gui_clients(response, zappy);
}

void handle_gui_msz(event_t *event, zappy_t *zappy)
{
    notifie_gui_msz(event->client, zappy);
}
