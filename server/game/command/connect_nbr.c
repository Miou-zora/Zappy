/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** connect_nbr
*/

#include "server.h"
#include "game.h"
#include "game_struct.h"
#include "clan.h"

static int get_nb_of_clan_members(clan_t *clan)
{
    int nb_of_members = 0;
    clan_member_t *clan_member = NULL;

    LIST_FOREACH(clan_member, &clan->all_members, next_clan_member)
        nb_of_members++;
    return (nb_of_members);
}

void connect_nbr(client_t *client, zappy_t *zappy, char *param)
{
    (void) param;
    response_t *response = NULL;
    char buffer[1024] = {0};
    clan_t *clan = NULL;
    int unused_slot = 0;

    LIST_FOREACH(clan, &zappy->game_struct->all_clans, next_clan) {
        if (strncmp(clan->name, client->trantorian->team_name,
            strlen(clan->name))) {
            unused_slot = get_nb_of_clan_members(clan);
            break;
        }
    }
    if (sprintf(buffer, "%d\n", unused_slot) < 0)
        return;
    response = create_response(buffer);
    if (!response)
        return;
    add_client_to_response(response, client);
    add_response_to_list(response, zappy);
}

void set_func_connect_nbr(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;

    add_command(event->client, 0, connect_nbr, NULL);
}
