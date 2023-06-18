/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** clan
*/

#include "clan.h"
#include "game_struct.h"
#include <string.h>

clan_member_t *create_clan_member(trantorian_t *trantorian)
{
    clan_member_t *clan_member = calloc(1, sizeof(clan_member_t));

    if (clan_member == NULL)
        return (NULL);
    clan_member->trantorian = trantorian;
    return (clan_member);
}

void add_trantorian_team(game_struct_t *game_struct, trantorian_t *trantorian,
    char *team_name)
{
    clan_t *temp = NULL;

    LIST_FOREACH(temp, &game_struct->all_clans, next_clan) {
        if (strcmp(temp->name, team_name) == 0) {
            LIST_INSERT_HEAD(&temp->all_members,
            create_clan_member(trantorian), next_clan_member);
            return;
        }
    }
}

struct clan_member_head create_clan_members_chained_list(void)
{
    struct clan_member_head head;
    LIST_INIT(&head);
    return (head);
}

clan_t *create_clan(size_t max_members, char *team_name)
{
    clan_t *clan = calloc(1, sizeof(clan_t));

    if (clan == NULL)
        return (NULL);
    clan->name = strdup(team_name);
    clan->max_nb_of_members = max_members;
    clan->all_members = create_clan_members_chained_list();
    return (clan);
}

struct clan_head create_clan_chained_list(void)
{
    struct clan_head head;
    LIST_INIT(&head);
    return (head);
}
