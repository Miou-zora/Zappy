/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** clan
*/

#include "clan.h"

clan_member_t *create_clan_member(trantorian_t *trantorian)
{
    clan_member_t *clan_member = calloc(1, sizeof(clan_member_t));

    if (clan_member == NULL)
        return (NULL);
    clan_member->trantorian = trantorian;
    return (clan_member);
}

struct clan_member_head create_clan_members_chained_list()
{
    struct clan_member_head head;
    LIST_INIT(&head);
    return (head);
}

clan_t *create_clan(char *team_name)
{
    clan_t *clan = calloc(1, sizeof(clan_t));

    if (clan == NULL)
        return (NULL);
    clan->name = strdup(team_name);
    clan->all_members = create_clan_members_chained_list();
    return (clan);
}

struct clan_head create_clan_chained_list(void)
{
    struct clan_head head;
    LIST_INIT(&head);
    return (head);
}
