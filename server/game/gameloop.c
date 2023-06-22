/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** Game loop
*/

#include "server.h"
#include "trantorian.h"
#include "check_functions.h"
#include "gui_protocol.h"
#include "game.h"

void bad_command(event_t *event, zappy_t *zappy_s)
{
    response_t *response = NULL;

    if (!event->client->is_connected)
        return;
    response = create_response("ko\n");
    add_client_to_response(response, event->client);
    add_response_to_list(response, zappy_s);
}

bool handle_event(event_t *event, zappy_t *zappy_s)
{
    void (*list_cmd[]) (event_t *event, zappy_t *zappy_s) = {
        set_func_forward, set_func_left, set_func_right, set_func_inventory,
        set_func_incantation, set_func_connect_nbr, set_func_set_object,
        set_func_look, set_func_fork};
    char *commands[] = {"Forward\n", "Left\n", "Right\n", "Inventory\n",
        "Incantation\n", "Connect_nbr\n", "Set object\n", "Look\n",
        "Fork\n", NULL};

    if (special_event(event, zappy_s))
        return (true);
    for (int i = 0; commands[i] != NULL; i++) {
        if (strncmp(event->request, commands[i], strlen(commands[i])) == 0) {
            list_cmd[i](event, zappy_s);
            destroy_event(event);
            return (true);
        }
    }
    return (handle_gui_event(event, zappy_s));
}

static bool check_if_player_dead(event_t *event)
{
    if (event->client->is_graphic || !event->client->is_logged
    || !event->client->is_connected || event->client->trantorian == NULL)
        return (false);
    if (!event->client->is_connected || event->client->trantorian == NULL)
        return (true);
    if (event->client->trantorian->is_dead == true) {
        return (true);
    }
    return (false);
}

void gameloop(zappy_t *zappy_s)
{
    event_t *event = NULL;

    LIST_FOREACH(event, &zappy_s->events, next) {
        sleep(1);
        if (!check_if_player_dead(event)) {
            handle_event(event, zappy_s);
        }
    }
    LIST_INIT(&zappy_s->events);
    update_players(zappy_s);
}
