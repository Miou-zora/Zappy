/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** check_win
*/

#include "server.h"
#include "gui_protocol.h"

bool check_win_game(zappy_t *zappy)
{
    int nb_member_level8 = 0;
    clan_t *clan = NULL;
    clan_member_t *member = NULL;

    LIST_FOREACH(clan, &zappy->game_struct->all_clans, next_clan) {
        nb_member_level8 = 0;
        LIST_FOREACH(member, &clan->all_members, next_clan_member) {
            if (member->trantorian->level == 8)
                nb_member_level8++;
        }
        if (nb_member_level8 == 6) {
            notifie_gui_seg(zappy, clan->name);
            return (true);
        }
    }
    return (false);
}
