/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** manage run
*/

#include "server.h"
#include "network.h"

bool manage_run(zappy_t *zappy, int listen_ret)
{
    if (listen_ret < 0) {
        display_log("Error while listening sockets\n");
        return (false);
    } else if (listen_ret > 0) {
        handle_activity(zappy);
    } else {
        gameloop(zappy);
        send_responses_clients(zappy);
        disconnect_clients(zappy);
    }
    return (true);
}
