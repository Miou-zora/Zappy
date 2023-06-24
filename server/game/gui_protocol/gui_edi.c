/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_edi
*/

#include "gui_protocol.h"
#include "server.h"

void notifie_gui_edi(egg_t *egg, zappy_t *zappy)
{
    char buffer[1024];
    response_t *response = NULL;
    int id_egg = egg->id;

    if (sprintf(buffer, "edi %d\n", id_egg) < 0)
        return;
    response = create_response(buffer);
    if (!response)
        return;
    send_response_to_all_gui_clients(response, zappy);
}
