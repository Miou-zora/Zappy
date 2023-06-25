/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_kil
*/

#include "gui_protocol.h"
#include "server.h"

void handle_gui_kil(event_t *event, zappy_t *zappy)
{
    int id = 0;
    client_t *client = NULL;

    if (strlen(event->request) < 7)
        return;
    if (sscanf(event->request, "kil %d", &id) != 1) {
        notifie_gui_sbp(event->client, zappy);
        return;
    }
    client->trantorian = get_trantorian_by_id(zappy, id);
    if (!client->trantorian) {
        notifie_gui_sbp(event->client, zappy);
        return;
    }
    client->trantorian->is_dead = true;
    send_death_to_gui(event->client->trantorian, zappy);
}
