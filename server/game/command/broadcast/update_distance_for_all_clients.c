/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** update distance for all clients
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"

static void create_response_broadcast(char *send_message,
    zappy_t *server, client_t *tmp_client, int direction)
{
    char buffer[1024] = {0};
    response_t *response = NULL;

    if (sprintf(buffer, "message %d, %s\n", direction, send_message) < 0)
        return;
    response = create_response(buffer);
    add_client_to_response(response, tmp_client);
    add_response_to_list(response, server);
}

static bool handle_emitteur_case(trantorian_t *receptor,
    vector_t *pos_emitter, zappy_t *server, char *msg)
{
    response_t *response = NULL;
    char buffer[1024] = {0};

    if (receptor->position.x != pos_emitter->x
    && receptor->position.y != pos_emitter->y)
        return false;

    if (sprintf(buffer, "message %d, %s\n", 0, msg) < 0)
        return false;
    response = create_response(buffer);
    add_client_to_response(response, receptor->client);
    add_response_to_list(response, server);
    return true;
}

static void process_client_positions_and_broadcast(char *send_message,
    zappy_t *server, client_t *client, vector_t pos_origin)
{
    vector_t increment_pos = {0, 0}; vector_t pos_receptor = {0, 0};
    client_t *tmp_client = NULL;
    trantorian_t *emitter = client->trantorian;

    LIST_FOREACH(tmp_client, &server->clients, next) {
        if (tmp_client->trantorian == NULL) {
            continue;
        }
        if (handle_emitteur_case(emitter, &pos_origin, server, send_message))
            continue;
        pos_receptor = tmp_client->trantorian->position;
        increment_pos = select_increment_pos(pos_origin, pos_receptor);
        pos_receptor = find_adjacent_pos_loop(pos_receptor,
        increment_pos, server->game_struct->map, emitter);
        create_response_broadcast(send_message, server, tmp_client,
        get_direction_broadcast(pos_receptor, pos_origin));
    }
}

void update_distance_for_all_clients(zappy_t *server,
    client_t *client, char *send_message)
{
    vector_t pos_origin = {client->trantorian->position.x,
        client->trantorian->position.y};

    process_client_positions_and_broadcast(send_message,
        server, client, pos_origin);
    notifie_gui_pbc(send_message, client->trantorian, server);

}
