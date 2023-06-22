/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** fork command
*/

#include "server.h"
#include "game.h"

static void send_do_fork(client_t *client, zappy_t *zappy)
{
    response_t *response = NULL;

    response = create_response("ok\n");
    add_client_to_response(response, client);
    add_response_to_list(response, zappy);
}

void do_fork(client_t *client, zappy_t *zappy, char *param)
{
    (void) param;
    egg_t *egg = NULL;
    clan_t *clan = NULL;

    LIST_FOREACH(clan, &zappy->game_struct->all_clans, next_clan) {
        if (strcmp(clan->name, client->trantorian->team_name) == 0)
            clan->max_nb_of_members++;
    }
    egg = create_egg(client->trantorian->position.x,
    client->trantorian->position.y,
    client->trantorian->team_name, client->trantorian->id + 1);
    LIST_INSERT_HEAD(&zappy->game_struct->all_eggs, egg, next_egg);
    send_do_fork(client, zappy);
}

void set_func_fork(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;
    add_command(event->client, 42, do_fork, NULL);
}
