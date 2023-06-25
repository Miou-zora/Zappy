/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** update distance for all clients
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"

static int mod_x(int x, int width)
{
    return ((x % width) < 0 ? (x % width) + width : (x % width));
}

static int mod_y(int y, int height)
{
    return ((y % height) < 0 ? (y % height) + height : (y % height));
}

static vector_t find_adjacent_pos_loop(vector_t pos_trantorian,
    vector_t increment_pos, map_t *map, trantorian_t *trantorian)
{
    int error = pos_trantorian.x - pos_trantorian.y;

    while (!check_adjacent_position(pos_trantorian, trantorian->position)) {
        if (error * 2 > -pos_trantorian.y) {
            error -= pos_trantorian.y;
            pos_trantorian.x += increment_pos.x;
            pos_trantorian.x = mod_x(pos_trantorian.x, map->width);
        }
        if (error * 2 < pos_trantorian.x) {
            error += pos_trantorian.x;
            pos_trantorian.y += increment_pos.y;
            pos_trantorian.y = mod_y(pos_trantorian.y, map->height);
        }
    }
    return pos_trantorian;
}

static void process_client_positions_and_broadcast(char *send_message,
    zappy_t *server, client_t *client, vector_t pos_origin)
{
    vector_t increment_pos = {0, 0}; vector_t pos_trantorian = {0, 0};
    client_t *tmp_client = NULL; response_t *response = NULL;
    char buffer[1024] = {0};

    LIST_FOREACH(tmp_client, &server->clients, next) {
        pos_trantorian =
            get_pos_trantorian(pos_origin, tmp_client->trantorian);
        increment_pos = select_increment_pos(pos_origin, pos_trantorian);
        check_border_in_map(&increment_pos,
            &pos_trantorian, server->game_struct->map);
        pos_trantorian =
            find_adjacent_pos_loop(pos_trantorian, increment_pos,
            server->game_struct->map, tmp_client->trantorian);
        if (sprintf(buffer, "message %d, %s\n",
        get_direction_broadcast(pos_trantorian, pos_origin), send_message) < 0)
            return;
        response = create_response(buffer);
        add_client_to_response(response, client);
        add_response_to_list(response, server);
    }
}

void update_distance_for_all_clients(zappy_t *server,
    client_t *client, char *send_message)
{
    vector_t pos_origin = {client->trantorian->position.x,
        client->trantorian->position.y};

    process_client_positions_and_broadcast(send_message, server,
        client, pos_origin);
}
