/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** broadcast
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"

void do_broadcast(client_t *client, zappy_t *zappy, char *param)
{
    char buffer[1024] = {0};

    if (param == NULL)
        return;
    if (sscanf(param, "Broadcast %*[^ ] %[^\n]", buffer) < 0)
        return;
    update_distance_for_all_clients(zappy, client, buffer);
    notifie_gui_pbc(buffer, client->trantorian, zappy);
}

void set_func_broadcast(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;

    add_command(event->client, 7, do_broadcast, NULL);
}
