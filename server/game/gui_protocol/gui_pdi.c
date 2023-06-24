/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pdi
*/

#include "server.h"
#include "gui_protocol.h"

void send_death_to_gui(trantorian_t *trantorian, zappy_t *zappy)
{
    char buffer[1024] = {0};
    response_t *response = NULL;

    if (sprintf(buffer, "pdi %d\n", trantorian->id) < 0)
        return;
    response = create_response(buffer);
    if (response == NULL)
        return;
    send_response_to_all_gui_clients(response, zappy);
}
