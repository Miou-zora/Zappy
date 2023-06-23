/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** create_list_clans
*/

#include "trantorian.h"
#include "server.h"

int create_clans(game_struct_t *game, argv_t *args)
{
    game->all_clans = create_clan_chained_list();
    clan_t *clan = NULL;

    for (int i = 0; args->names[i]; i++) {
        clan = create_clan(args->clientsNb, args->names[i]);
        if (!clan)
            return (84);
        add_clan_to_list(game, clan);
    }
    return (0);
}
