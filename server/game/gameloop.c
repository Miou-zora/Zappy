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

    response = create_response("ko\n");
    add_client_to_response(response, zappy_s->clients.lh_first);
    add_response_to_list(response, zappy_s);
}

bool handle_event(event_t *event, zappy_t *zappy_s)
{
    if (special_event(event, zappy_s)) {
        return (true);
    }
    void (*list_cmd[3]) (event_t *event, zappy_t *zappy_s) = {
        cmd_forward, cmd_left, cmd_right,
    };
    char *commands[3] = {
        "Forward\n", "LEFT\n", "RIGHT\n",
    };

    for (int i = 0; i < 3; i++) {
        if (strncmp(event->request, commands[i],
        strlen(commands[i])) == 0) {
            list_cmd[i](event, zappy_s);
            destroy_event(event);
            return (true);
        }
    }
    bad_command(zappy_s);
    return (false);
}

static bool check_if_player_dead(event_t *event)
{
    if (!event->client->is_connected || event->client->trantorian == NULL)
        return (true);
    if (event->client->trantorian->is_dead == true) {
        return (true);
    }
    return (false);
}

static void update_players(event_t *event, zappy_t *zappy)
{
    client_t *client = NULL;

    void (*list_cmd[3]) (event_t *event, zappy_t *zappy_s, char *arg) = {
        move_into_the_good_way, left, right,
    };

    char *param = NULL;

    for (client = LIST_FIRST(&zappy->clients); client != NULL;
    client = LIST_NEXT(client, next)) {
        if (client->trantorian->command[0].timer == 0 &&
        client->trantorian->command[0].command != NONE) {
            list_cmd[client->trantorian->command[0].command]
            (event, zappy, param);
        }
        if (client->trantorian->command[0].timer > 0)
            client->trantorian->command[0].timer -= 1;
    }
    re_organize_list_command(client);
}

void gameloop(zappy_t *zappy_s)
{
    event_t *event = NULL;
    event_t *tmp = NULL;

    for (event = LIST_FIRST(&zappy_s->events); event != NULL;
    event = LIST_NEXT(event, next)) {
        if (!check_if_player_dead(event)) {
            handle_event(event, zappy_s);
        }
        if (tmp)
            destroy_event(tmp);
        tmp = event;
        LIST_REMOVE(event, next);
    }
    update_players(event, zappy_s);
}
