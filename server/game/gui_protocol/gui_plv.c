/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_plv
*/

#include "gui_protocol.h"
#include "server.h"

void notifie_gui_plv(trantorian_t *player, zappy_t *server, client_t *client)
{
    char buffer[1024];
    response_t *response = NULL;

    if (sprintf(buffer, "plv %d %d\n", player->id, player->level) < 0)
        return;
    response = create_response(buffer);
    if (!response)
        return;
    add_client_to_response(response, client);
    LIST_INSERT_HEAD(&server->responses, response, next);
}

void handle_gui_plv(event_t *event, zappy_t *server)
{
    char *data = event->request;
    int id = 0;
    trantorian_t *trantorian = NULL;

    if (!data)
        return;
    if (strlen(data) < 7)
        return;
    if (sscanf(data, "plv %d", &id) < 1)
        return;
    trantorian = get_trantorian_by_id(server, id);
    if (!trantorian)
        return;
    notifie_gui_plv(trantorian, server, event->client);
}
