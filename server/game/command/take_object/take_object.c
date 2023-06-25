/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** take_object
*/

#include "trantorian.h"
#include "game.h"
#include "incantation.h"

static void set_response(char *param, client_t *client, zappy_t *zappy)
{
    if (param == NULL) {
        notifie_gui_sbp(client, zappy);
        return;
    }
    add_command(client, 7, take_object, param);
}

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
    vector_t pos = client->trantorian->position;
    if (find_object_on_tile(client->trantorian,
        &zappy->game_struct->map->tile[pos.y][pos.x],param)) {
        response_t *response = create_response("ok\n");
        add_client_to_response(response, client);
        add_response_to_list(response, zappy);
        send_gui_pgt(client, zappy, param);
        send_gui_bct(pos.x, pos.y, zappy);
        send_gui_pin(client->trantorian, zappy);
    } else {
        response_t *response = create_response("ko\n");
        add_client_to_response(response, client);
        add_response_to_list(response, zappy);
    }
}

void set_func_take_object(event_t *event, zappy_t *zappy_s)
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
