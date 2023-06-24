/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_seg
*/

#include "gui_protocol.h"
#include "server.h"

void notifie_gui_seg(zappy_t *zappy, char *team_name)
{
    char buffer[1024];
    response_t *response = NULL;

    if (sprintf(buffer, "seg %s\n", team_name) < 0)
        return;
    response = create_response(buffer);
    if (!response)
        return;
    send_response_to_all_gui_clients(response, zappy);
}
