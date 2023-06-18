/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** client
*/

#include "client.h"
#include "server.h"
#include <string.h>

void disconnect_clients(zappy_t *server)
{
    client_t *tmp = NULL;
    client_t *tmp2 = NULL;

    LIST_FOREACH(tmp, &server->clients, next) {
        if (tmp2)
            destroy_client(tmp2);
        if (!tmp->is_connected) {
            LIST_REMOVE(tmp, next);
            tmp2 = tmp;
        }
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
    if (client->fd != -1)
        close(client->fd);
    client->fd = -1;
    free(client);
}
