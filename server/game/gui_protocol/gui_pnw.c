/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pnw
*/

#include "server.h"
#include "gui_protocol.h"
#include "trantorian.h"

void gui_pnw(client_t *nc, zappy_t *zappy)
{
    char buffer[1024];
    response_t *response = NULL;

    if (nc->is_graphic == false || nc->trantorian == NULL || !nc->is_connected)
        return;
    sprintf(buffer, "pnw %d %ld %ld %d %d %s\n", nc->trantorian->id,
        nc->trantorian->position.x, nc->trantorian->position.y,
        nc->trantorian->direction,
        nc->trantorian->level, nc->trantorian->team_name);
    response = create_response(buffer);
    if (response == NULL)
        return;
    for (client_t *client = LIST_FIRST(&zappy->clients); client != NULL;
        client = LIST_NEXT(client, next)) {
        if (client->is_graphic == true) {
            add_client_to_response(response, client);
        }
    }
    add_response_to_list(response, zappy);
}
