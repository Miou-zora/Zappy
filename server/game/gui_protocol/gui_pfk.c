/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pfk
*/

#include "server.h"
#include "game.h"

void send_gui_pfk(client_t *client, zappy_t *zappy)
{
    char buffer[1024] = {0};
    response_t *response = NULL;

    if (sprintf(buffer, "pfk %d\n", client->trantorian->id) < 0)
        return;
    response = create_response(buffer);
    if (!response)
        return;
    send_response_to_all_gui_clients(response, zappy);
}
