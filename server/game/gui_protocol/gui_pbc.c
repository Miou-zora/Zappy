/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pbc
*/

#include "gui_protocol.h"
#include "server.h"

void notifie_gui_pbc(char *message, trantorian_t *trantorian, zappy_t *zappy)
{
    char buffer[1024];
    response_t *response = NULL;

    if (sprintf(buffer, "pbc %d %s\n", trantorian->id, message) < 0)
        return;
    response = create_response(buffer);
    if (!response)
        return;
    send_response_to_all_gui_clients(response, zappy);
}
