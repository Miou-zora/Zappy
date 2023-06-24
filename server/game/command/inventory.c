/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** inventory
*/

#include "server.h"
#include "trantorian.h"

void send_inventory(client_t *client, zappy_t *zappy, char *param)
{
    (void) param;
    char res[1024] = {0};
    object_t *obj = client->trantorian->inventory;

    if (sprintf(res, "[food %ld, linemate %ld, deraumere %ld, sibur %ld, "
        "mendiane %ld, phiras %ld, thystame %ld]\n", obj->nb_of_objects[FOOD],
        obj->nb_of_objects[LINEMATE], obj->nb_of_objects[DERAUMERE],
        obj->nb_of_objects[SIBUR], obj->nb_of_objects[MENDIANE],
        obj->nb_of_objects[PHIRAS],obj->nb_of_objects[THYSTAME]) < 0)
        return;
    display_log("inventory: %s", res);
    response_t *response = create_response(res);
    add_client_to_response(response,client);
    add_response_to_list(response, zappy);
}

void set_func_inventory(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;

    add_command(event->client, 1, send_inventory, NULL);
}
