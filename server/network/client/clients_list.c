/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** clients_list
*/

#include "server.h"
#include "network.h"
#include "client.h"

client_t *get_last_client(zappy_t *zappy)
{
    client_t *tmp = NULL;
    client_t *tmp2 = NULL;

    LIST_FOREACH(tmp, &zappy->clients, next) {
        tmp2 = tmp;
    }
    return (tmp2);
}

void add_client_to_list(client_t *client, zappy_t *zappy_s)
{
    if (client == NULL || zappy_s == NULL)
        return;
    if (zappy_s->clients.lh_first == NULL) {
        LIST_INSERT_HEAD(&zappy_s->clients, client, next);
        return;
    }
    LIST_INSERT_AFTER(get_last_client(zappy_s), client, next);
}

void send_response_to_all_gui_clients(response_t *response, zappy_t *zappy)
{
    client_t *client = NULL;

    if (!response)
        return;
    LIST_FOREACH(client, &zappy->clients, next) {
        if (client->is_graphic == true) {
            add_client_to_response(response, client);
        }
    }
    add_response_to_list(response, zappy);
}
