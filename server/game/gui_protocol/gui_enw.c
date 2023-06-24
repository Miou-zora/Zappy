/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_enw
*/

#include "gui_protocol.h"
#include "server.h"

int get_egg_by_trantorian(zappy_t *server, trantorian_t *trantorian)
{
    egg_t *egg = NULL;

    LIST_FOREACH(egg, &server->game_struct->all_eggs, next_egg) {
        if (egg->pos.x == trantorian->position.x
            && egg->pos.y == trantorian->position.y)
            return (egg->id);
    }
    return (0);
}

void notifie_gui_enw(trantorian_t *trantorian, zappy_t *server)
{
    char buffer[1024];
    response_t *response = NULL;
    int egg_id = get_egg_by_trantorian(server, trantorian);

    if (sprintf(buffer, "enw %d %d %d %d\n", egg_id, trantorian->id,
        trantorian->position.x, trantorian->position.y) < 0)
        return;
    response = create_response(buffer);
    if (!response)
        return;
    send_response_to_all_gui_clients(response, server);
}
