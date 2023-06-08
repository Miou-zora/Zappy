/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** clan
*/

#include "clan.h"

clan_t *create_clan(char *team_name)
{
    clan_t *clan = calloc(1, sizeof(clan_t));

    clan->name = strdup(team_name);
    clan->clan_member = calloc(1, sizeof(clan_member_t));
    clan->clan_member->trantorian = initialize_empty_trantorian();
    clan->clan_member->is_first = true;
    return (clan);
}

clan_t *add_member_to_clan(clan_t *clan, clan_member_t *trantorian)
{
    while (clan->clan_member->next != NULL)
        clan->clan_member = clan->clan_member->next;

    clan->clan_member->next = trantorian;
    clan->nb_of_members++;
    return (clan);
}

clan_t *remove_member_from_clan(clan_t *clan, clan_member_t *trantorian)
{
    clan_member_t *to_remove_trantorian = clan->clan_member;

    while (clan->clan_member->next != NULL)
        clan->clan_member = clan->clan_member->next;
    if (clan->clan_member == trantorian) {
        clan->clan_member = NULL;
        return (clan);
    }

    for (int i = 0; clan->clan_member->next != NULL; i++) {
        if (clan->clan_member->next == trantorian) {
            to_remove_trantorian = clan->clan_member->next;
            clan->clan_member->next = clan->clan_member->next->next;
            free(to_remove_trantorian);
            clan->nb_of_members--;
            return (clan);
        }
        clan->clan_member = clan->clan_member->next;
    }
    return (clan);
}
