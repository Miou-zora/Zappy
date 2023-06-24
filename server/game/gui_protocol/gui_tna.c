/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_tna
*/

#include "server.h"
#include "gui_protocol.h"
#include "response.h"

void notifie_gui_tna(zappy_t *zappy)
{
    char buffer[1024] = {0};
    response_t *response = NULL;

    for (size_t i = 0; zappy->args->names[i] != NULL; i++) {
        if (sprintf(buffer, "tna %s\n", zappy->args->names[i]) < 0)
            return;
        response = create_response(buffer);
        if (response == NULL)
            return;
        memset(buffer, 0, 1024);
        send_response_to_all_gui_clients(response, zappy);
    }
}

void handle_gui_tna(event_t *event, zappy_t *zappy)
{
    if (!event->client->is_connected || !event->client->is_logged ||
        !event->client->is_graphic)
        return;
    notifie_gui_tna(zappy);
}
