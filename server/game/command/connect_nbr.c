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

static char *int_into_char(int tmp)
{
    char *str = calloc(1, sizeof(char) * 10);
    int i = 0;

    for (; tmp > 0; i++) {
        str[i] = tmp % 10 + '0';
        tmp /= 10;
    }
    str[i] = '\0';
    return (str);
}

static char *get_nb_of_clan_members(clan_t *clan)
{
    int nb_of_members = 0;
    clan_member_t *clan_member = NULL;
    char *nb_of_members_str = NULL;

    LIST_FOREACH(clan_member, &clan->all_members, next_clan_member) {
        nb_of_members++;
    }

    if (nb_of_members == 0) {
        free(nb_of_members_str);
        free(clan_member);
        return (strdup("0\n"));
    } else {
        nb_of_members_str = int_into_char(nb_of_members - 1);
    }
    if (nb_of_members_str == NULL)
        return (strdup("0\n"));
    return (nb_of_members_str);
}

void connect_nbr(client_t *client, zappy_t *zappy, char *param)
{
    (void) param;
    response_t *response = NULL;
    char *target_name = strdup(client->trantorian->team_name);
    clan_t *clan = NULL;
    char *unused_slot = NULL;

    LIST_FOREACH(clan, &zappy->game_struct->all_clans, next_clan) {
        if (strcmp(clan->name, target_name) == 0) {
            unused_slot = get_nb_of_clan_members(clan);
            break;
        }
    }
    if (unused_slot == NULL)
        unused_slot = strdup("0\n");
    response = create_response(strcat(unused_slot, "\n"));
    add_client_to_response(response, client);
    add_response_to_list(response, zappy);
    free(target_name);
    free(unused_slot);
}

void set_func_connect_nbr(event_t *event, zappy_t *zappy_s)
{
    (void) zappy_s;

    add_command(event->client, 0, connect_nbr, NULL);
}
