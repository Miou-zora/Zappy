/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** run
*/

#include "server.h"

extern bool running;

void update_fd_set(fd_set *readfds, zappy_t *zappy)
{
    client_t *client = NULL;

    FD_ZERO(readfds);
    FD_SET(zappy->socket, readfds);
    LIST_FOREACH(client, &zappy->clients, next) {
        FD_SET(client->fd, readfds);
    }
}

int listen_sockets(zappy_t *zappy)
{
    update_fd_set(&zappy->readfds, zappy);
    return (select(FD_SETSIZE, &zappy->readfds, NULL, NULL, &zappy->timeout));
}

int run(zappy_t *zappy)
{
    int listen_ret = 0;
    display_log("Server running on port 127.0.0.1:%d\n", zappy->args->port);
    display_log("Waiting for connections...\n");

    while (running) {
        listen_ret = listen_sockets(zappy);
        if (listen_ret < 0) {
            display_log("Error while listening sockets\nFatal error\n");
            return (84);
        } else {
            handle_activity(zappy);
        }
    }
    return (0);
}
