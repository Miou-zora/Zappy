/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** client
*/

#include "client.h"

client_t *create_client(struct sockaddr_in info, int fd)
{
    client_t *client = calloc(1, sizeof(client_t));

    if (!client)
        return (NULL);
    client->ip = inet_ntoa(info.sin_addr);
    client->port = ntohs(info.sin_port);
    client->fd = fd;
    client->info = info;
    client->is_connected = true;
    client->is_logged = false;
    client->is_graphic = false;
    write(client->fd, "WELCOME\n", 8);
    return (client);
}

void destroy_client(client_t *client)
{
    if (!client)
        return;
    free(client);
}
