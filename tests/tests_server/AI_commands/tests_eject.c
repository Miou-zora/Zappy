/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_eject
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"
#include <criterion/criterion.h>

Test(do_eject, eject_trantorian_success)
{
    char *av[] = {"./zappy_server", "-p", "12847", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    egg_t *egg = create_egg(1, 1, "test", 1);
    trantorian_t *trantorian = create_trantorian(egg);
    trantorian->direction = UP;
    object_t *objects = calloc(1, sizeof(object_t));
    trantorian->inventory = objects;
    event_t *event = calloc(1, sizeof(event_t));
    client_t *client = calloc(1, sizeof(client_t));
    event->client = client;
    event->client->trantorian = trantorian;
    clan_t *clan = calloc(1, sizeof(clan_t));
    clan_member_t *member = calloc(1, sizeof(clan_member_t));

    egg_t *egg2 = create_egg(1, 1, "test", 2);
    trantorian_t *trantorian2 = create_trantorian(egg2);
    trantorian2->direction = UP;
    member->trantorian = trantorian2;
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);

    do_eject(client, zappy, NULL);
    cr_assert_str_eq(zappy->responses.lh_first->content, "eject: 5\n");
    response_t *response = LIST_NEXT(zappy->responses.lh_first, next);
    cr_assert_str_eq(response->content, "ok\n");
}

Test(do_eject, eject_trantorian_success2)
{
    char *av[] = {"./zappy_server", "-p", "63847", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    egg_t *egg = create_egg(1, 1, "test", 1);
    trantorian_t *trantorian = create_trantorian(egg);
    trantorian->direction = RIGHT;
    object_t *objects = calloc(1, sizeof(object_t));
    trantorian->inventory = objects;
    event_t *event = calloc(1, sizeof(event_t));
    client_t *client = calloc(1, sizeof(client_t));
    event->client = client;
    event->client->trantorian = trantorian;
    clan_t *clan = calloc(1, sizeof(clan_t));
    clan_member_t *member = calloc(1, sizeof(clan_member_t));

    egg_t *egg2 = create_egg(1, 1, "test", 2);
    trantorian_t *trantorian2 = create_trantorian(egg2);
    trantorian2->direction = LEFT;
    member->trantorian = trantorian2;
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);

    do_eject(client, zappy, NULL);
    cr_assert_str_eq(zappy->responses.lh_first->content, "eject: 1\n");
    response_t *response = LIST_NEXT(zappy->responses.lh_first, next);
    cr_assert_str_eq(response->content, "ok\n");
}

Test(do_eject, eject_trantorian_success3)
{
    char *av[] = {"./zappy_server", "-p", "12832", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    egg_t *egg = create_egg(1, 1, "test", 1);
    trantorian_t *trantorian = create_trantorian(egg);
    trantorian->direction = DOWN;
    object_t *objects = calloc(1, sizeof(object_t));
    trantorian->inventory = objects;
    event_t *event = calloc(1, sizeof(event_t));
    client_t *client = calloc(1, sizeof(client_t));
    event->client = client;
    event->client->trantorian = trantorian;
    clan_t *clan = calloc(1, sizeof(clan_t));
    clan_member_t *member = calloc(1, sizeof(clan_member_t));

    egg_t *egg2 = create_egg(1, 1, "test", 2);
    trantorian_t *trantorian2 = create_trantorian(egg2);
    trantorian2->direction = LEFT;
    member->trantorian = trantorian2;
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);

    do_eject(client, zappy, NULL);
    cr_assert_str_eq(zappy->responses.lh_first->content, "eject: 7\n");
    response_t *response = LIST_NEXT(zappy->responses.lh_first, next);
    cr_assert_str_eq(response->content, "ok\n");
}

Test(do_eject, eject_trantorian_success4)
{
    char *av[] = {"./zappy_server", "-p", "64363", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    egg_t *egg = create_egg(9, 1, "test", 1);
    trantorian_t *trantorian = create_trantorian(egg);
    trantorian->direction = RIGHT;
    object_t *objects = calloc(1, sizeof(object_t));
    trantorian->inventory = objects;
    event_t *event = calloc(1, sizeof(event_t));
    client_t *client = calloc(1, sizeof(client_t));
    event->client = client;
    event->client->trantorian = trantorian;
    clan_t *clan = calloc(1, sizeof(clan_t));
    clan_member_t *member = calloc(1, sizeof(clan_member_t));

    egg_t *egg2 = create_egg(9, 1, "test", 2);
    trantorian_t *trantorian2 = create_trantorian(egg2);
    trantorian2->direction = UP;
    member->trantorian = trantorian2;
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);

    do_eject(client, zappy, NULL);
    cr_assert_str_eq(zappy->responses.lh_first->content, "eject: 3\n");
    response_t *response = LIST_NEXT(zappy->responses.lh_first, next);
    cr_assert_str_eq(response->content, "ok\n");
}


Test(do_eject, eject_trantorian_fail)
{
    char *av[] = {"./zappy_server", "-p", "54282", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    egg_t *egg = create_egg(1, 1, "test", 1);
    trantorian_t *trantorian = create_trantorian(egg);
    trantorian->direction = UP;
    object_t *objects = calloc(1, sizeof(object_t));
    trantorian->inventory = objects;
    event_t *event = calloc(1, sizeof(event_t));
    client_t *client = calloc(1, sizeof(client_t));
    event->client = client;
    event->client->trantorian = trantorian;
    clan_t *clan = calloc(1, sizeof(clan_t));
    clan_member_t *member = calloc(1, sizeof(clan_member_t));

    egg_t *egg2 = create_egg(2, 1, "test", 2);
    trantorian_t *trantorian2 = create_trantorian(egg2);
    trantorian2->direction = UP;
    member->trantorian = trantorian2;
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);

    do_eject(client, zappy, NULL);
    cr_assert_str_eq(zappy->responses.lh_first->content, "ko\n");
}

Test(do_eject, destroy_eggs_success)
{
    char *av[] = {"./zappy_server", "-p", "64262", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    egg_t *egg = create_egg(1, 1, "test", 1);
    trantorian_t *trantorian = create_trantorian(egg);
    trantorian->direction = UP;
    object_t *objects = calloc(1, sizeof(object_t));
    trantorian->inventory = objects;
    event_t *event = calloc(1, sizeof(event_t));
    client_t *client = calloc(1, sizeof(client_t));
    event->client = client;
    event->client->trantorian = trantorian;
    egg_t *egg2 = create_egg(1, 1, "test", 2);
    LIST_INSERT_HEAD(&zappy->game_struct->all_eggs, egg2, next_egg);

    do_eject(client, zappy, NULL);
    cr_assert_str_eq(zappy->responses.lh_first->content, "ok\n");
}

Test(do_eject, destroy_eggs_fail)
{
    char *av[] = {"./zappy_server", "-p", "25395", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    egg_t *egg = create_egg(1, 1, "test", 1);
    trantorian_t *trantorian = create_trantorian(egg);
    trantorian->direction = UP;
    object_t *objects = calloc(1, sizeof(object_t));
    trantorian->inventory = objects;
    event_t *event = calloc(1, sizeof(event_t));
    client_t *client = calloc(1, sizeof(client_t));
    event->client = client;
    event->client->trantorian = trantorian;
    egg_t *egg2 = create_egg(2, 1, "test", 2);
    LIST_INSERT_HEAD(&zappy->game_struct->all_eggs, egg2, next_egg);

    do_eject(client, zappy, NULL);
    cr_assert_str_eq(zappy->responses.lh_first->content, "ko\n");
}