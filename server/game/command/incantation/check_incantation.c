/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** check_inventory_lvl
*/

#include "server.h"
#include "trantorian.h"

static bool check_pos_trantorian(client_t *client, clan_member_t *clan_member)
{
    if (clan_member->trantorian->position.x == client->trantorian->position.x
        && clan_member->trantorian->position.y
        == client->trantorian->position.y) {
        return true;
    }
    return false;
}

static bool check_players_level(client_t *client, zappy_t *zappy,
    size_t *level_values, size_t need_level)
{
    int nb_players = 1;
    clan_t *clan = NULL;
    clan_member_t *clan_member = NULL;

    LIST_FOREACH(clan, &zappy->game_struct->all_clans, next_clan) {
        LIST_FOREACH(clan_member, &clan->all_members, next_clan_member) {
            if (check_pos_trantorian(client, clan_member)
            && clan_member->trantorian->level == client->trantorian->level) {
                nb_players++;
            }
        }
    }
    if ((size_t)nb_players != level_values[need_level])
        return false;
    return true;
}

bool check_players_on_tile(client_t *client, zappy_t *zappy,
    size_t *level_values)
{
    size_t need_level = client->trantorian->level;

    if (check_players_level(client, zappy, level_values, need_level))
        return true;
    return false;
}

bool check_inventory_trantorian(client_t *client, size_t *level_values)
{
    size_t level_trantorian = client->trantorian->level;

    for (size_t i = 1; i < 7; i++) {
        if (level_trantorian == i
        && client->trantorian->inventory->nb_of_objects[i]
        >= level_values[i]) {
            return true;
        }
    }
    return false;
}
