/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pic
*/

#include "gui_protocol.h"
#include "server.h"

void notifie_gui_pic(trantorian_t *trantorian, zappy_t *server,
    bool state_incantation)
{
    char buffer[1024];
    response_t *response = NULL;

    if (sprintf(buffer, "pic %d %d %d\n", trantorian->position.x,
        trantorian->position.y, state_incantation) < 0)
        return;
    response = create_response(buffer);
    if (!response)
        return;
    send_response_to_all_gui_clients(response, server);
}
