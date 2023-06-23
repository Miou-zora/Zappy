/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** update_players
*/

#include "server.h"
#include "gui_protocol.h"

client_t *get_gui_client(struct client_list *clients)
{
    client_t *gui_client;

    LIST_FOREACH(gui_client, clients, next) {
        if (gui_client->is_graphic)
            return (gui_client);
    }
    return (NULL);
}

void update_trantorian_life(trantorian_t *trantorian, zappy_t *zappy)
{
    clan_t *clan = NULL;
    clan_member_t *member = NULL;

    if (trantorian->is_dead == true) {
        LIST_FOREACH(clan, &zappy->game_struct->all_clans, next_clan) {
            LIST_FOREACH(member, &clan->all_members, next_clan_member) {
                if (member->trantorian == trantorian) {
                    LIST_REMOVE(member, next_clan_member);
                    free(member);
                }
            }
        }
        send_death_to_gui(trantorian, zappy);
    }
}

void update_players_by_clans(zappy_t *zappy, clan_t *clan)
{
    struct clan_member_s *tmp_clan = NULL;
    struct trantorian_s *tmp = NULL;

    LIST_FOREACH(tmp_clan, &clan->all_members, next_clan_member) {
        tmp = tmp_clan->trantorian;
        update_trantorian_life(tmp_clan->trantorian, zappy);
        if (tmp->command[0].timer == 0 && tmp->command[0].func != NULL) {
            tmp->command[0].func(tmp->client, zappy, tmp->command[0].arg);
        }
        if (tmp->command[0].timer > 0) {
            tmp->command[0].timer -= 1;
        }
        if (tmp->inventory->nb_of_objects[FOOD] > 0)
            tmp->inventory->nb_of_objects[FOOD]--;
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
