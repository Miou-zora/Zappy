/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** update_players
*/

#include "server.h"
#include "trantorian.h"
#include "check_functions.h"
#include "gui_protocol.h"
#include "clan.h"

void update_players_by_clans(zappy_t *zappy, clan_t *clan)
{
    struct clan_member_s *tmp_clan = NULL;
    struct trantorian_s *tmp = NULL;

    LIST_FOREACH(tmp_clan, &clan->all_members, next_clan_member) {
        tmp = tmp_clan->trantorian;
        if (tmp->command[0].timer == 0 && tmp->command[0].func != NULL) {
            tmp->command[0].func(tmp->client, zappy, tmp->command[0].arg);
        }
        if (tmp->command[0].timer > 0) {
            tmp->command[0].timer -= 1;
        }
    }
}

void update_players(zappy_t *zappy)
{
    clan_t *clan = NULL;

    LIST_FOREACH(clan, &zappy->game_struct->all_clans, next_clan) {
        update_players_by_clans(zappy, clan);
    }
    re_organize_list_command(zappy);
}
