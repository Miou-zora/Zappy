/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_ebo
*/

#include "gui_protocol.h"
#include "server.h"

void notifie_gui_ebo(client_t *client, zappy_t *zappy)
{
    char buffer[1024];
    response_t *response = NULL;
    int id_egg = get_egg_by_trantorian(zappy, client->trantorian);

    if (sprintf(buffer, "ebo %d\n", id_egg) < 0)
        return;
    response = create_response(buffer);
    if (!response)
        return;
    send_response_to_all_gui_clients(response, zappy);
}
