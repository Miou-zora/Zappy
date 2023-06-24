/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** check_inventory_lvl
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"

static void trantorians_concerned_incante(trantorian_t *trantorian,
    client_t *trantorian2)
{
    if (trantorian->command[0].func == NULL) {
        trantorian->command[0].timer = 300;
        trantorian->command[0].func = &do_incantation;
    } else {
        for (int i = 0; i < MAX_COMMAND - 1; i++)
            copy_command(trantorian2, i, i + 1);
        trantorian->command[0].func = &do_incantation;
        trantorian->command[0].timer = 300;
    }
}

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
                && clan_member->trantorian->level
                == client->trantorian->level) {
                nb_players++;
                trantorians_concerned_incante(clan_member->trantorian,
                    clan_member->trantorian->client);
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

bool check_inventory_trantorian(client_t *client, size_t *level_values,
    zappy_t *zappy)
{
    size_t level_trantorian = client->trantorian->level;
    bool return_value = false;

    for (size_t i = 1; i < 7; i++) {
        if (level_trantorian == i
            && client->trantorian->inventory->nb_of_objects[i]
            >= level_values[i]) {
            return_value = check_players_on_tile(client, zappy, level_values);
        }
    }
    return return_value;
}
