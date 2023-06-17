/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Game loop
*/

#include "server.h"
#include "trantorian.h"

static void bad_command(zappy_t *zappy_s)
{
    response_t *response = NULL;

    response = create_response("suc\n");
    add_client_to_response(response, zappy_s->clients.lh_first);
    add_response_to_list(response, zappy_s);
}

bool handle_event(event_t *event, zappy_t *zappy_s)
{
    void (*list_cmd[1]) (event_t *event, zappy_t *zappy_s) = {
        cmd_forward,
    };
    char *commands[1] = {
        "Forward\n",
    };

    for (int i = 0; i < 1; i++) {
        if (strncmp(event->request, commands[i], strlen(commands[i])) == 0) {
            list_cmd[i](event, zappy_s);
            return (true);
        }
    }
    bad_command(zappy_s);
    return (false);
}

static bool check_if_player_dead(event_t *event)
{
    if (event->client->trantorian->is_dead == true) {
        LIST_REMOVE(event, next);
        free(event);
        return (true);
    }
    return (false);
}

static void update_players(zappy_t *zappy)
{
    client_t *client = NULL;
    void (*list_cmd[1]) (trantorian_t *trantorian, zappy_t *zappy_s) = {};

    for (client = LIST_FIRST(&zappy->clients); client != NULL;
    client = LIST_NEXT(client, next)) {
        if (client->trantorian->timer == 0 &&
        client->trantorian->current_command != NONE) {
            list_cmd[client->trantorian->current_command]
            (client->trantorian, zappy);
        }
        if (client->trantorian->timer > 0)
            client->trantorian->timer -= 1;
    }
}

void gameloop(zappy_t *zappy_s)
{
    event_t *event = NULL;

    for (event = LIST_FIRST(&zappy_s->events); event != NULL;
    event = LIST_NEXT(event, next)) {
        if (check_if_player_dead(event) == true) {
            continue;
        }
        if (handle_event(event, zappy_s) == true) {
            LIST_REMOVE(event, next);
        }
        LIST_REMOVE(event, next);
        free(event);
    }
    update_players(zappy_s);
}
