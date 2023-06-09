/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** handle_clients
*/

#include "server.h"

static int handle_client_activity(zappy_t *zappy, client_t *client)
{
    char buffer[1024] = {0};
    int ret = 0;
    (void)zappy;

    ret = read(client->fd, buffer, 1024);
    if (ret < 0)
        return (84);
    if (ret == 0) {
        close(client->fd);
        LIST_REMOVE(client, next);
        free(client);
        return (0);
    }
    display_log("Received from client %d: %s\n", client->fd, buffer);
    write(client->fd, "OK\n", 3);
    return (0);
}

static int handle_new_connection(zappy_t *zappy)
{
    client_t *client = NULL;
    int client_fd = 0;
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);

    client_fd = accept(zappy->socket, (struct sockaddr *)&client_addr,
        &client_addr_len);
    if (client_fd < 0) {
        display_log("Error while accepting new connection\n");
        return (84);
    }
    client = create_client(client_addr, client_fd);
    if (!client) {
        display_log("Error while creating client\n");
        return (84);
    }
    LIST_INSERT_HEAD(&zappy->clients, client, next);
    return (0);
}

int handle_activity(zappy_t *zappy)
{
    client_t *client = NULL;

    if (FD_ISSET(zappy->socket, &zappy->readfds) && zappy->socket != 0) {
        return (handle_new_connection(zappy));
    }
    LIST_FOREACH(client, &zappy->clients, next) {
        if (FD_ISSET(client->fd, &zappy->readfds) && client->fd > 0) {
            handle_client_activity(zappy, client);
        }
    }
    return (0);
}
