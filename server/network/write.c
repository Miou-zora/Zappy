/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** write
*/

#include "network.h"

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

int send_client(zappy_t *server, int fd, char *msg)
{
    int is_ready = is_socket_ready(fd);
    if (is_ready == 1) {
        if (write(fd, msg, strlen(msg)) <= 0)
            return (84);
        return (0);
    } else if (is_ready == 0) {
        read_client(fd);
        return (send_client(server, fd, msg));
    } else {
        return (84);
    }
}