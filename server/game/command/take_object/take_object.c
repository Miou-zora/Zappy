/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** take_object
*/

#include "trantorian.h"
#include "game.h"
#include "incantation.h"

static bool find_object_on_tile_stones(trantorian_t *trantorian, object_t *tile,
    const char *param)
{
    int objectIndex = get_object_index(param);

    if (objectIndex == -1)
        return false;
    if (tile->nb_of_objects[objectIndex] > 0) {
        tile->nb_of_objects[objectIndex]--;
        trantorian->inventory->nb_of_objects[objectIndex]++;
        return true;
    }
    return false;
}

static bool find_object_on_tile(trantorian_t *trantorian, object_t *tile,
    const char *param)
{
    if (strcmp(param, "food") == 0) {
        if (tile->nb_of_objects[FOOD] > 0) {
            tile->nb_of_objects[FOOD]--;
            trantorian->inventory->nb_of_objects[FOOD] += 126;
            return true;
        }
    }
    if (find_object_on_tile_stones(trantorian, tile, param))
        return true;
    return false;
}

void take_object(client_t *client, zappy_t *zappy, char *param)
{
    if (find_object_on_tile(client->trantorian,
        zappy->game_struct->map->tile[client->trantorian->position.x +
        client->trantorian->position.y * zappy->game_struct->map->width],
            param)) {
        response_t *response = create_response("ok\n");
        add_client_to_response(response, client);
        add_response_to_list(response, zappy);
    } else {
        response_t *response = create_response("ko\n");
        add_client_to_response(response, client);
        add_response_to_list(response, zappy);
    }
}

void set_func_take_object(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;

    add_command(event->client, 7, take_object, event->request);
}
