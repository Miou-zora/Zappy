/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_suc
*/

#include "gui_protocol.h"
#include "server.h"

void notifie_gui_suc(client_t *client, zappy_t *zappy)
{
    char buffer[1024];
    response_t *response = NULL;

    if (sprintf(buffer, "suc\n") < 0)
        return;
    response = create_response(buffer);
    if (!response)
        return;
    add_client_to_response(response, client);
    add_response_to_list(response, zappy);
}
