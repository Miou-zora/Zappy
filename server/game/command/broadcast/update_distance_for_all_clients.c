/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** update distance for all clients
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"

void send_response_emetter(zappy_t *zappy, char *message, trantorian_t *src)
{
    response_t *response = NULL;
    char buffer[1024];

    if (sprintf(buffer, "message %d, %s\n", 0, message) < 0)
        return;
    response = create_response(message);
    add_client_to_response(response, src->client);
    add_response_to_list(response, zappy);
}

vector_t comptute_compensation(vector_t *pos_origin, vector_t *pos_target)
{
    vector_t compensation = {0, 0};

    if (pos_origin->x < pos_target->x)
        compensation.x = 1;
    else
        compensation.x = -1;
    if (pos_origin->y < pos_target->y)
        compensation.y = 1;
    else
        compensation.y = -1;
    return (compensation);
}

vector_t compute_difference(vector_t *pos_origin, vector_t *pos_target)
{
    vector_t diff = {0, 0};

    diff.x = abs(pos_target->x - pos_origin->x);
    diff.y = abs(pos_target->y - pos_origin->y);
    return (diff);
}

void update_distance_for_all_clients(zappy_t *server,
    client_t *client, char *send_message)
{
    compute_message_movement(server, client->trantorian, send_message);
    notifie_gui_pbc(send_message, client->trantorian, server);

}
