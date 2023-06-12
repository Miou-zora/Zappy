/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** run
*/

#include "server.h"
#include "network.h"

extern bool running;

static int send_responses(zappy_t *zappy, response_t *response)
{
    client_t *tmp = NULL;

    LIST_FOREACH(tmp, &response->clients, next) {
        if (send_client(zappy, tmp, response->content) == 84) {
            display_log("Error While sending response to client %d\n",
            tmp->fd);
        }
    }
    return (0);
}

static int send_responses_clients(zappy_t *zappy)
{
    response_t *tmp = NULL;

    LIST_FOREACH(tmp, &zappy->responses, next) {
        if (tmp->clients.lh_first != NULL) {
            send_responses(zappy, tmp);
        }
    }
    return (0);
}

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
    if (zappy->timeout.tv_sec == 0 && zappy->timeout.tv_usec == 0) {
        zappy->timeout.tv_sec = 0;
        zappy->timeout.tv_usec = 1000000 / zappy->args->freq;
    }
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
            display_log("Error while listening sockets\n");
            return (84);
        } else {
            handle_activity(zappy);
        }
        ///Game loop will update here
        send_responses_clients(zappy);
    }
    return (0);
}
