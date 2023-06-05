/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** build_server
*/

#include "server.h"

static int clean_bind(int socket, struct sockaddr_in *interface)
{
    return (bind(socket, (struct sockaddr *)interface, sizeof(*interface)));
}

static int init_server_socket(zappy_t *server)
{
    server->socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server->socket == -1)
        return(-1);
    server->interface.sin_family = AF_INET;
    server->interface.sin_addr.s_addr = INADDR_ANY;
    server->interface.sin_port = htons(server->port);
    if (clean_bind(server->socket, &server->interface) < 0)
        return (-1);
    if (listen(server->socket, QUEUE_SIZE) < 0)
        return (-1);
    return (0);
}

zappy_t *build_server(int ac, char **av)
{
    zappy_t *zappy = calloc(1, sizeof(zappy_t));

    if (!zappy)
        return (NULL);
    zappy->args = calloc(1, sizeof(argv_t));
    if (!zappy->args)
        return (NULL);
    if (!parse_args(ac, av, zappy->args) || init_server_socket(zappy) < 0)
        return (NULL);
    zappy->game = NULL;
    return (zappy);
}
