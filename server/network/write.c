/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** write
*/

#include "network.h"
#include "event.h"

static int flush_socket(zappy_t *server, client_t *client)
{
    char *request = read_client(client->fd);
    event_t *event = NULL;

    if (request == NULL)
        return (84);
    event = create_event(request, client);
    if (event == NULL)
        return (84);
    LIST_INSERT_HEAD(&server->events, event, next);
    return (0);
}

int is_socket_ready(int fd)
{
    fd_set writefds;
    struct timeval tv = {0, 0};

    FD_ZERO(&writefds);
    FD_SET(fd, &writefds);
    if (select(FD_SETSIZE, NULL, &writefds, NULL, &tv) <= 0)
        return (-1);
    if (FD_ISSET(fd, &writefds) == 0)
        return (0);
    return (1);
}

int send_client(zappy_t *server, client_t *client, char *msg)
{
    int is_ready = is_socket_ready(client->fd);

    if (is_ready == 1) {
        if (write(client->fd, msg, strlen(msg)) <= 0)
            return (84);
        return (0);
    } else if (is_ready == 0) {
        flush_socket(server, client);
        return (send_client(server, client, msg));
    } else {
        return (84);
    }
}