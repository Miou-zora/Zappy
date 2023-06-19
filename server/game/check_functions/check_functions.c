/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** check_functions
*/

#include "check_functions.h"

void update_trantorian_life(trantorian_t *trantorian)
{
    if (trantorian->inventory->nb_of_objects[FOOD] == 0) {
        trantorian->is_dead = true;
    }
}

void update_all_trantorians_life(struct clan_head *all_clans)
{
    clan_t *clan = NULL;
    clan_member_t *member = NULL;

    LIST_FOREACH(clan, all_clans, next_clan) {
        LIST_FOREACH(member, &(clan->all_members),
            next_clan_member) {
            update_trantorian_life(member->trantorian);
        }
    }
}
