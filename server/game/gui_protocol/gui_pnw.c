/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pnw
*/

#include "server.h"
#include "gui_protocol.h"
#include "trantorian.h"

static int fill_buffer(client_t *nc, char *buffer)
{
    return sprintf(buffer, "pnw %d %d %d %d %d %s\n", nc->trantorian->id,
        nc->trantorian->position.x, nc->trantorian->position.y,
        nc->trantorian->direction,
        nc->trantorian->level, nc->trantorian->team_name);
}

void notifie_gui_pnw(client_t *nc, zappy_t *zappy)
{
    char buffer[1024];
    response_t *response = NULL;
    client_t *client = NULL;

    if (nc->is_graphic == true || nc->trantorian == NULL || !nc->is_connected) {
        return;
    }
    if (fill_buffer(nc, buffer) < 0)
        return;
    response = create_response(buffer);
    if (response == NULL)
        return;
    LIST_FOREACH(client, &zappy->clients, next) {
        if (client->is_graphic == true)
            add_client_to_response(response, client);
    }
    if (response->clients.lh_first != NULL)
        add_response_to_list(response, zappy);
}
