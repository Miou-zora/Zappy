/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pdr
*/

#include "game.h"
#include "server.h"

void send_gui_pdr(client_t *client, zappy_t *zappy, char *param)
{
    char buffer[1024];
    response_t *response = NULL;
    int ressource_id = get_id_ressource_by_name(param);

    if (sprintf(buffer, "pdr %d %d\n", client->trantorian->id,
        ressource_id) < 0)
        return;
    response = create_response(buffer);
    if (!response)
        return;
    send_response_to_all_gui_clients(response, zappy);
}
