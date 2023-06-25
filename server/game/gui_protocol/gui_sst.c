/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_sst
*/

#include "gui_protocol.h"
#include "server.h"

void notifie_gui_sst(zappy_t *zappy)
{
    char buffer[1024];
    response_t *response = NULL;

    if (sprintf(buffer, "sst %d\n", zappy->args->freq) < 0)
        return;
    response = create_response(buffer);
    if (!response)
        return;
    send_response_to_all_gui_clients(response, zappy);
}

void handle_gui_sst(event_t *event, zappy_t *zappy)
{
    int freq = 0;
    if (strlen(event->request) < 7)
        return;
    if (sscanf(event->request, "sst %d", &freq) != 1) {
        notifie_gui_sbp(event->client, zappy);
        return;
    }
    zappy->args->freq = freq;
    notifie_gui_sst(zappy);
}
