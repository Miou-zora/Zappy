/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** clans_lists
*/

#include "clan.h"
#include "game_struct.h"

clan_t *get_last_clan(game_struct_t *game_struct)
{
    clan_t *temp = NULL;
    clan_t *last = NULL;

    LIST_FOREACH(temp, &game_struct->all_clans, next_clan) {
        last = temp;
    }
    return (last);
}

void add_clan_to_list(game_struct_t *game_struct, clan_t *clan)
{
    if (game_struct->all_clans.lh_first == NULL) {
        LIST_INSERT_HEAD(&game_struct->all_clans, clan, next_clan);
        return;
    }
    LIST_INSERT_AFTER(get_last_clan(game_struct), clan, next_clan);
}

clan_member_t *get_last_clan_member(clan_t *clan)
{
    clan_member_t *temp = NULL;
    clan_member_t *last = NULL;

    LIST_FOREACH(temp, &clan->all_members, next_clan_member) {
        last = temp;
    }
    return (last);
}

void add_clan_member_to_list(clan_t *clan, clan_member_t *member)
{
    if (clan->all_members.lh_first == NULL) {
        LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
        return;
    }
    LIST_INSERT_AFTER(get_last_clan_member(clan), member, next_clan_member);

}
