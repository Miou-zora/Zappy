/*
** EPITECH PROJECT, 2023
** Zappy-Mirror [WSL : Ubuntu]
** File description:
** look
*/

#include "server.h"
#include "look.h"

static vector_t get_vector_based_orientation(client_t *client)
{
    enum DIRECTION direction[] = {UP, DOWN, RIGHT, LEFT};
    vector_t vectors[] = {
        {.x = -1, .y = 0},
        {.x = -1, .y = 0},
        {.x = 0, .y = -1},
        {.x = 0, .y = 1},
    };
    for (size_t i = 0; i < 4; i++) {
        if (client->trantorian->direction == direction[i])
            return (vectors[i]);
    }
    return (vectors[0]);
}

void look_tile(client_t *client, zappy_t *zappy, char *param)
{
    (void) param;
    response_t *response = NULL;
    char *res = NULL;

    res = send_look(client, zappy, get_vector_based_orientation(client));
    if (!res)
        return;
    response = create_response(res);
    if (!response)
        return;
    add_client_to_response(response, client);
    add_response_to_list(response, zappy);
}

void set_func_look(event_t *event, zappy_t *zappy)
{
    (void) zappy;

    add_command(event->client, 7, look_tile, NULL);
}
