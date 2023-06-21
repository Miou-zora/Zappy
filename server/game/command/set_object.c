/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** set_object
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"

static bool drop_object(trantorian_t *trantorian, object_t *tile, int i)
{
    if (trantorian->inventory->nb_of_objects[i] > 0) {
        trantorian->inventory->nb_of_objects[i]--;
        tile->nb_of_objects[i]++;
        return true;
    }
    return false;
}

static bool update_inventory_tile(trantorian_t *trantorian,
    object_t *tile, const char *param)
{
    const char* objects[] = {"FOOD", "LINEMATE", "DERAUMERE", "SIBUR",
    "MENDIANE", "PHIRAS", "THYSTAME"};
    static const size_t num_objects = sizeof(objects) / sizeof(objects[0]);

    for (size_t i = 0; i < num_objects; i++) {
        if (strcmp(param, objects[i]) == 0 &&
            drop_object(trantorian, tile, i)) {
            return true;
        }
    }
    return false;
}

void set_object(client_t *client, zappy_t *zappy, char *param)
{
    if (update_inventory_tile(client->trantorian,
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

void set_func_set_object(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;

    add_command(event->client, 7, set_object, event->request);
}
