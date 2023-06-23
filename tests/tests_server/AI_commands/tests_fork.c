/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_fork
*/

#include "server.h"
#include "trantorian.h"
#include <criterion/criterion.h>
#include "game.h"

Test(do_fork, test_do_fork)
{
    char *av[] = {"./zappy_server", "-p", "8923", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    egg_t* egg = create_egg(0, 0, "toto", 1);
    trantorian_t *trantorian = create_trantorian(egg);
    trantorian->direction = UP;

    event_t *event = calloc(1, sizeof(event_t));
    client_t *client = calloc(1, sizeof(client_t));
    event->client = client;
    event->client->trantorian = trantorian;
    trantorian->team_name = strdup("toto");
    clan_t *clan = create_clan(10, "toto");
    clan->name = strdup("toto");
    clan_member_t *clan_member = calloc(1, sizeof(clan_member_t));
    clan_member->trantorian = trantorian;
    LIST_INSERT_HEAD(&clan->all_members, clan_member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);
    do_fork(client, zappy, NULL);
    cr_assert_eq(clan->max_nb_of_members, 11);
}
