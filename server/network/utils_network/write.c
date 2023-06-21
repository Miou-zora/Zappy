/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** write
*/

#include "network.h"
#include "event.h"

int flush_socket(zappy_t *server, client_t *client)
{
    char *request = read_client(client->fd);
    event_t *event = NULL;

    if (request == NULL)
        return (84);
    event = create_event(request, client);
    if (event == NULL)
        return (84);
    add_event_to_list(event, server);
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
    (void)server;
    display_log("Sending to client %d at %s:%d %s", client->fd,
        client->ip, client->port, msg);
    return (write(client->fd, msg, strlen(msg)));
}
