/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** initialize_trantorian
*/

#include "trantorian.h"
#include "server.h"
#include "game_struct.h"
#include "player_command.h"

static egg_t *find_egg_by_team_name(char *name, game_struct_t *game_struct)
{
    egg_t *egg = NULL;

    LIST_FOREACH(egg, &game_struct->all_eggs, next_egg) {
        if (strncmp(egg->team_name, name, strlen(egg->team_name)) == 0) {
            LIST_REMOVE(egg, next_egg);
            return (egg);
        }
    }
    return (NULL);
}

trantorian_t *create_trantorian_from_event(char *team_name, zappy_t *server)
{
    trantorian_t *trantorian = NULL;
    egg_t *egg = find_egg_by_team_name(team_name, server->game_struct);
    clan_t *clan = NULL;

    if (!egg)
        return (NULL);
    trantorian = create_trantorian(egg);
    if (!trantorian)
        return (NULL);
    trantorian->team_name = strdup(team_name);
    LIST_FOREACH(clan, &server->game_struct->all_clans, next_clan) {
        if (strcmp(clan->name, team_name) == 0) {
            add_clan_member_to_list(clan, create_clan_member(trantorian));
        }
    }
    return (trantorian);
}

trantorian_t *create_trantorian(egg_t* egg)
{
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));

    trantorian->level = 1;
    trantorian->inventory = calloc(1, sizeof(object_t));
    trantorian->inventory->nb_of_objects[FOOD] = 1260;
    trantorian->position.x = egg->pos.x;
    trantorian->position.y = egg->pos.y;
    trantorian->id = egg->id;
    trantorian->direction = rand() % 4;
    if (trantorian->direction == 0)
        trantorian->direction = 1;
    return (trantorian);
}

struct trantorian_head create_trantorian_chained_list(void)
{
    struct trantorian_head head;
    LIST_INIT(&head);
    return (head);
}
