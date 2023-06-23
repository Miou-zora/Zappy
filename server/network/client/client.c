/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** client
*/

#include "client.h"
#include "server.h"
#include <string.h>

void remove_lost_clients(zappy_t *server)
{
    client_t *tmp = NULL;
    client_t *tmp2 = NULL;

    tmp = LIST_FIRST(&server->clients);
    while (tmp != NULL) {
        tmp2 = LIST_NEXT(tmp, next);
        if (tmp->is_connected == false) {
            LIST_REMOVE(tmp, next);
        }
        tmp = tmp2;
    }
}

client_t *create_client(struct sockaddr_in info, int fd)
{
    client_t *client = calloc(1, sizeof(client_t));

    memset(client, 0, sizeof(client_t));
    if (!client)
        return (NULL);
    client->ip = inet_ntoa(info.sin_addr);
    client->port = ntohs(info.sin_port);
    client->fd = fd;
    client->info = info;
    client->is_connected = true;
    client->is_logged = false;
    client->is_graphic = false;
    return (client);
}

void remove_client(client_t *client)
{
    LIST_REMOVE(client, next);
    destroy_client(client);
}

void destroy_client(client_t *client)
{
    display_log("Destroying client %d\n", client->fd);
    if (client->fd != -1)
        close(client->fd);
    client->fd = -1;
    free(client);
}
