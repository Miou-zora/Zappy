/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** eject
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"

static bool destroy_eggs(trantorian_t *trantorian, zappy_t *zappy)
{
    egg_t *egg = NULL;
    int nb_eggs_destroyed = 0;

    LIST_FOREACH(egg, &zappy->game_struct->all_eggs, next_egg) {
        if (egg->pos.x == trantorian->position.x
            && egg->pos.y == trantorian->position.y) {
            LIST_REMOVE(egg, next_egg);
            nb_eggs_destroyed++;
            notifie_gui_edi(egg, zappy);
        }
    }
    if (nb_eggs_destroyed > 0)
        return true;
    return false;
}

void do_eject(client_t *client, zappy_t *zappy, char *param)
{
    (void) param;

    if (push_player(client,
        zappy) || destroy_eggs(client->trantorian,
            zappy)) {
        response_t *response = create_response("ok\n");
        add_client_to_response(response, client);
        add_response_to_list(response, zappy);
        notifie_gui_pex(client->trantorian, zappy);
    } else {
        response_t *response = create_response("ko\n");
        add_client_to_response(response, client);
        add_response_to_list(response, zappy);
    }
}

void set_func_eject(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;

    add_command(event->client, 7, do_eject, NULL);
}
