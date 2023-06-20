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
    const char *objects[] = {"food", "linemate", "deraumere", "sibur",
        "mendiane", "phiras", "thystame"};
    char *resp = NULL;

    asprintf(&resp, "[");
    for (int i = 0; i < 7; i++) {
        char *tmp = NULL;
        asprintf(&tmp, "%s %ld, ", objects[i],
        client->trantorian->inventory->nb_of_objects[i]);
        resp = realloc(resp, strlen(resp) + strlen(tmp) + 1);
        strcat(resp, tmp);
        free(tmp);
    }
    resp[strlen(resp) - 2] = ']';
    resp[strlen(resp) - 1] = '\0';
    response_t *response = create_response(resp);
    add_client_to_response(response,client);
    add_response_to_list(response, zappy);
    free(resp);
}

void set_func_inventory(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;

    add_command(event->client, 1, send_inventory, NULL);
}
