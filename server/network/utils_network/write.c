/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** write
*/

#include "network.h"
#include "event.h"

int send_client(zappy_t *server, client_t *client, char *msg)
{
    (void)server;
    display_log("Sending to client %d at %s:%d %s", client->fd,
        client->ip, client->port, msg);

    return (write(client->fd, msg, strlen(msg)));
}
