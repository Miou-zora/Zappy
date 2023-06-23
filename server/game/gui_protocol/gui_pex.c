/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pex
*/

#include "gui_protocol.h"
#include "server.h"

void notifie_gui_pex(trantorian_t *trantorian, zappy_t *server,
    client_t *client)
{
    char buffer[1024];
    response_t *response = NULL;

    if (sprintf(buffer, "pex %d\n", trantorian->id) < 0)
        return;
    response = create_response(buffer);
    if (!response)
        return;
    add_client_to_response(response, client);
    add_response_to_list(response, server);
}
