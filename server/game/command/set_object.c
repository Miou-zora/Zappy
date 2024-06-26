/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** set_object
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"

static void set_response(char *param, client_t *client, zappy_t *zappy)
{
    if (param == NULL) {
        notifie_gui_sbp(client, zappy);
        return;
    }
    add_command(client, 7, set_object, param);
}

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
    const char* objects[] = {"food", "linemate", "deraumere", "sibur",
        "mendiane", "phiras", "thystame"};
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
    map_t *map = zappy->game_struct->map;
    vector_t pos = client->trantorian->position;

    if (update_inventory_tile(client->trantorian,
        &map->tile[pos.y][pos.x], param)) {
        response_t *response = create_response("ok\n");
        add_client_to_response(response, client);
        add_response_to_list(response, zappy);
        send_gui_pdr(client, zappy, param);
        send_gui_bct(pos.x, pos.y, zappy);
        send_gui_pin(client->trantorian, zappy);
    } else {
        response_t *response = create_response("ko\n");
        add_client_to_response(response, client);
        add_response_to_list(response, zappy);
    }
}

void set_func_set_object(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;
    char *param = NULL;
    char *objects[] = {"food", "linemate", "deraumere", "sibur",
    "mendiane", "phiras", "thystame", NULL};

    for (int i = 0; event->request[i] != '\0'; i++) {
        if (event->request[i] == ' ' && event->request[i + 1] != '\0')
            param = &event->request[i + 1];
    }
    if (param[strlen(param) - 2] == '\n')
        param[strlen(param) - 2] = '\0';
    for (int i = 0; i < NUMBER_OF_DIFFERENT_ELEMENTS; i++) {
        if (strncmp(param, objects[i], strlen(objects[i])) == 0) {
            param = objects[i];
            break;
        }
    }
    set_response(param, event->client, zappy_s);
}
