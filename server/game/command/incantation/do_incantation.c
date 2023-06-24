/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** incantation
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"
#include "incantation.h"

static void send_current_elevation(bool state,
    client_t *client, zappy_t *zappy)
{
    char *tmp = NULL;

    if (state) {
        asprintf(&tmp, "Elevation underway Current level: %d\n",
        client->trantorian->level);
        response_t *response = create_response(tmp);
        add_client_to_response(response, client);
        add_response_to_list(response, zappy);
        notifie_gui_plv(client->trantorian, zappy);
    } else {
        response_t *response = create_response("ko\n");
        add_client_to_response(response, client);
        add_response_to_list(response, zappy);
    }
}

void do_incantation(client_t *client, zappy_t *zappy, char *param)
{
    (void) param;
    bool state = true;
    size_t **inventory_lvl = initialize_inventory();
    size_t *level_values = malloc(sizeof(size_t) * 7);
    level_values = copy_inventory_level(inventory_lvl,
    client->trantorian->level, level_values);

    if (!check_inventory_trantorian(client, level_values, zappy))
        state = false;
    send_current_elevation(state, client, zappy);
}

void set_func_incantation(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;

    add_command(event->client, 300, do_incantation, NULL);
}
