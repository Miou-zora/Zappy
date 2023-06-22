/*
** EPITECH PROJECT, 2023
** Zappy-Mirror [WSL : Ubuntu]
** File description:
** look
*/

#include "server.h"
#include "look.h"

void look_tile(client_t *client, zappy_t *zappy, char *param)
{
    (void) param;
    response_t *response = NULL;
    char *res = NULL;

    char *(*look[4]) (client_t *client, zappy_t *zappy) = {
        look_up, look_right, look_down, look_left,
    };
    res = strcat(strdup(
        look[client->trantorian->direction - 1](client, zappy)), "\n");
    response = create_response(res);
    add_client_to_response(response, client);
    add_response_to_list(response, zappy);
}

void set_func_look(event_t *event, zappy_t *zappy)
{
    (void) zappy;

    add_command(event->client, 7, look_tile, NULL);
}
