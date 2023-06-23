/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_look
*/

#include "server.h"
#include "look.h"
#include <criterion/criterion.h>

Test(nb_of_trantorians_at_pos, test_nb_trantorian)
{
    char *av[] = {"./zappy_server", "-p", "12331", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
    trantorian->direction = UP;
    trantorian->position.x = 0;
    trantorian->position.y = 0;

    trantorian_t *trantorian2 = calloc(1, sizeof(trantorian_t));
    trantorian2->direction = UP;
    trantorian2->position.x = 0;
    trantorian2->position.y = 0;

    clan_member_t *member = create_clan_member(trantorian);
    clan_member_t *member2 = create_clan_member(trantorian2);
    clan_t *clan = create_clan(1, "test");
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);

    cr_assert_eq(nb_of_trantorians_at_pos((size_t) 0, (size_t)0, zappy), 1);
    LIST_INSERT_HEAD(&clan->all_members, member2, next_clan_member);
    cr_assert_eq(nb_of_trantorians_at_pos((size_t) 0, (size_t)0, zappy), 2);
}

Test(nb_of_eggs_at_pos, test_nb_eggs)
{
    char *av[] = {"./zappy_server", "-p", "12332", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    egg_t *egg = calloc(1, sizeof(egg_t));
    egg->pos.x = 0;
    egg->pos.y = 0;
    egg_t *egg2 = calloc(1, sizeof(egg_t));
    egg2->pos.x = 2;
    egg2->pos.y = 0;
    LIST_INSERT_HEAD(&zappy->game_struct->all_eggs, egg, next_egg);
    cr_assert_eq(nb_of_eggs_at_pos((size_t) 0, (size_t)0, zappy), 1);
    LIST_INSERT_HEAD(&zappy->game_struct->all_eggs, egg2, next_egg);
    cr_assert_eq(nb_of_eggs_at_pos((size_t) 0, (size_t)0, zappy), 1);
}

Test(all_elements_at_tile, test_nb_elements)
{
    char *av[] = {"./zappy_server", "-p", "9856", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    zappy->game_struct->map->tile[1][4].nb_of_objects[0] = 1;
    zappy->game_struct->map->tile[1][4].nb_of_objects[1] = 2;
    zappy->game_struct->map->tile[1][4].nb_of_objects[2] = 3;
    zappy->game_struct->map->tile[1][4].nb_of_objects[3] = 4;
    zappy->game_struct->map->tile[1][4].nb_of_objects[4] = 5;
    zappy->game_struct->map->tile[1][4].nb_of_objects[5] = 6;
    zappy->game_struct->map->tile[1][4].nb_of_objects[6] = 7;
    char *expected_resp = "food linemate linemate deraumere deraumere deraumere sibur sibur sibur sibur mendiane mendiane mendiane mendiane mendiane phiras phiras phiras phiras phiras phiras thystame thystame thystame thystame thystame thystame thystame ";

    cr_assert_str_eq(all_elements_at_tile((size_t) 4, (size_t)1, zappy), expected_resp);
}

Test(look_at_tile, test_look_at_tile)
{
    char *av[] = {"./zappy_server", "-p", "9872", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    zappy->game_struct->map->tile[4][4].nb_of_objects[FOOD] = 1;
    zappy->game_struct->map->tile[4][4].nb_of_objects[LINEMATE] = 2;
    zappy->game_struct->map->tile[4][4].nb_of_objects[DERAUMERE] = 2;
    zappy->game_struct->map->tile[4][4].nb_of_objects[SIBUR] = 2;
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
    trantorian->position.x = 4;
    trantorian->position.y = 4;

    clan_t *clan = calloc(1, sizeof(clan_t));
    clan_member_t *member = calloc(1, sizeof(clan_member_t));
    member->trantorian = trantorian;
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);

    char *expected = "food linemate linemate deraumere deraumere sibur sibur player";

    cr_assert_str_eq(look_at_tile((size_t) 4, (size_t) 4, zappy), expected);
}
Test(look_up, test_look_up)
{
    char *av[] = {"./zappy_server", "-p", "9869", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    zappy->game_struct->map = create_map(10, 10);
    zappy->game_struct->map->tile[9][9].nb_of_objects[FOOD] = 2;
    zappy->game_struct->map->tile[9][9].nb_of_objects[LINEMATE] = 2;
    zappy->game_struct->map->tile[9][0].nb_of_objects[DERAUMERE] = 2;
    zappy->game_struct->map->tile[9][0].nb_of_objects[SIBUR] = 2;
    zappy->game_struct->map->tile[9][1].nb_of_objects[SIBUR] = 1;
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
    trantorian->position.x = 0;
    trantorian->position.y = 0;
    trantorian->direction= UP;
    trantorian->level = 1;
    client_t *client = calloc(1, sizeof(client_t));
    client->trantorian = trantorian;
    event_t *event = create_event("Look\n", client);
    event->client = client;
    clan_t *clan = calloc(1, sizeof(clan_t));
    clan_member_t *member = calloc(1, sizeof(clan_member_t));
    member->trantorian = trantorian;
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);
    char *expected_resp = "[player, food food linemate linemate, deraumere deraumere sibur sibur, sibur]";
    char*resp = look_up(client, zappy);
    cr_assert_str_eq(resp, expected_resp);
}

Test(look_up, test_look_up_level_3)
{
    char *av[] = {"./zappy_server", "-p", "9239", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    zappy->game_struct->map = create_map(10, 10);
    zappy->game_struct->map->tile[4][4].nb_of_objects[FOOD] = 1;
    zappy->game_struct->map->tile[4][5].nb_of_objects[LINEMATE] = 1;
    zappy->game_struct->map->tile[4][6].nb_of_objects[DERAUMERE] = 1;
    zappy->game_struct->map->tile[3][3].nb_of_objects[SIBUR] = 1;
    zappy->game_struct->map->tile[3][4].nb_of_objects[SIBUR] = 1;
    zappy->game_struct->map->tile[3][5].nb_of_objects[PHIRAS] = 1;
    zappy->game_struct->map->tile[3][6].nb_of_objects[THYSTAME] = 1;
    zappy->game_struct->map->tile[3][7].nb_of_objects[MENDIANE] = 1;
    zappy->game_struct->map->tile[2][2].nb_of_objects[MENDIANE] = 1;
    zappy->game_struct->map->tile[2][3].nb_of_objects[DERAUMERE] = 1;
    zappy->game_struct->map->tile[2][4].nb_of_objects[LINEMATE] = 1;
    zappy->game_struct->map->tile[2][5].nb_of_objects[SIBUR] = 1;
    zappy->game_struct->map->tile[2][6].nb_of_objects[PHIRAS] = 1;
    zappy->game_struct->map->tile[2][7].nb_of_objects[THYSTAME] = 1;
    zappy->game_struct->map->tile[2][8].nb_of_objects[MENDIANE] = 1;

    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
    trantorian->position.x = 5;
    trantorian->position.y = 5;
    trantorian->direction= UP;
    trantorian->level = 3;
    client_t *client = calloc(1, sizeof(client_t));
    client->trantorian = trantorian;
    event_t *event = create_event("Look\n", client);
    event->client = client;
    clan_t *clan = calloc(1, sizeof(clan_t));
    clan_member_t *member = calloc(1, sizeof(clan_member_t));
    member->trantorian = trantorian;
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);
    char *expected_resp = "[player, food, linemate, deraumere, sibur, sibur, phiras, thystame, mendiane, mendiane, deraumere, linemate, sibur, phiras, thystame, mendiane]";
    char *res = look_up(client, zappy);
    cr_assert_str_eq(res, expected_resp);
}

Test(look_down, test_down_level_3)
{
    char *av[] = {"./zappy_server", "-p", "9289", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    zappy->game_struct->map = create_map(10, 10);
    zappy->game_struct->map->tile[6][4].nb_of_objects[FOOD] = 6;
    zappy->game_struct->map->tile[6][5].nb_of_objects[LINEMATE] = 1;
    zappy->game_struct->map->tile[6][6].nb_of_objects[DERAUMERE] = 1;
    zappy->game_struct->map->tile[7][3].nb_of_objects[SIBUR] = 1;
    zappy->game_struct->map->tile[7][4].nb_of_objects[SIBUR] = 1;
    zappy->game_struct->map->tile[7][5].nb_of_objects[PHIRAS] = 1;
    zappy->game_struct->map->tile[7][6].nb_of_objects[THYSTAME] = 1;
    zappy->game_struct->map->tile[7][7].nb_of_objects[MENDIANE] = 1;
    zappy->game_struct->map->tile[8][2].nb_of_objects[MENDIANE] = 1;
    zappy->game_struct->map->tile[8][3].nb_of_objects[DERAUMERE] = 1;
    zappy->game_struct->map->tile[8][4].nb_of_objects[LINEMATE] = 1;
    zappy->game_struct->map->tile[8][5].nb_of_objects[SIBUR] = 1;
    zappy->game_struct->map->tile[8][6].nb_of_objects[PHIRAS] = 1;
    zappy->game_struct->map->tile[8][7].nb_of_objects[THYSTAME] = 1;
    zappy->game_struct->map->tile[8][8].nb_of_objects[MENDIANE] = 1;

    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
    trantorian->position.x = 5;
    trantorian->position.y = 5;
    trantorian->direction= DOWN;
    trantorian->level = 3;
    client_t *client = calloc(1, sizeof(client_t));
    client->trantorian = trantorian;
    event_t *event = create_event("Look\n", client);
    event->client = client;
    clan_t *clan = calloc(1, sizeof(clan_t));
    clan_member_t *member = calloc(1, sizeof(clan_member_t));
    member->trantorian = trantorian;
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);
    char *expected_resp = "[player, deraumere, linemate, food food food food food food, mendiane, thystame, phiras, sibur, sibur, mendiane, thystame, phiras, sibur, linemate, deraumere, mendiane]";
    char *res = look_down(client, zappy);
    cr_assert_str_eq(res, expected_resp);
}

Test(look_left, test_look_left)
{
    char *av[] = {"./zappy_server", "-p", "4539", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    zappy->game_struct->map = create_map(10, 10);
    zappy->game_struct->map->tile[5][8].nb_of_objects[FOOD] = 2; //tile 1
    zappy->game_struct->map->tile[4][8].nb_of_objects[LINEMATE] = 1; //tile 2
    zappy->game_struct->map->tile[3][8].nb_of_objects[DERAUMERE] = 1; //tile 3
    zappy->game_struct->map->tile[6][7].nb_of_objects[SIBUR] = 1; //tile 4
    zappy->game_struct->map->tile[5][7].nb_of_objects[SIBUR] = 1; //tile 5
    zappy->game_struct->map->tile[4][7].nb_of_objects[PHIRAS] = 1; //tile 6
    zappy->game_struct->map->tile[3][7].nb_of_objects[THYSTAME] = 1; //tile 7
    zappy->game_struct->map->tile[2][7].nb_of_objects[MENDIANE] = 1; //tile 8

    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
    trantorian->position.x = 9;
    trantorian->position.y = 4;
    trantorian->direction= LEFT;
    trantorian->level = 2;
    client_t *client = calloc(1, sizeof(client_t));
    client->trantorian = trantorian;
    event_t *event = create_event("Look\n", client);
    event->client = client;
    clan_t *clan = calloc(1, sizeof(clan_t));
    clan_member_t *member = calloc(1, sizeof(clan_member_t));
    member->trantorian = trantorian;
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);
    char *expected_resp = "[player, food food, linemate, deraumere, sibur, sibur, phiras, thystame, mendiane]";
    char *res = look_left(client, zappy);
    cr_assert_str_eq(res, expected_resp);
}

Test(look_right, test_look_right)
{
    char *av[] = {"./zappy_server", "-p", "4429", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    zappy->game_struct->map = create_map(10, 10); // reset the map because they spwan default
    zappy->game_struct->map->tile[4][6].nb_of_objects[FOOD] = 6;
    zappy->game_struct->map->tile[5][6].nb_of_objects[LINEMATE] = 1;
    zappy->game_struct->map->tile[6][6].nb_of_objects[DERAUMERE] = 1;
    zappy->game_struct->map->tile[3][7].nb_of_objects[SIBUR] = 1;
    zappy->game_struct->map->tile[4][7].nb_of_objects[SIBUR] = 1;
    zappy->game_struct->map->tile[5][7].nb_of_objects[PHIRAS] = 1;
    zappy->game_struct->map->tile[6][7].nb_of_objects[THYSTAME] = 1;
    zappy->game_struct->map->tile[7][7].nb_of_objects[MENDIANE] = 1;

    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
    trantorian->position.x = 5;
    trantorian->position.y = 5;
    trantorian->direction= RIGHT;
    trantorian->level = 2;
    client_t *client = calloc(1, sizeof(client_t));
    client->trantorian = trantorian;
    event_t *event = create_event("Look\n", client);
    event->client = client;
    clan_t *clan = calloc(1, sizeof(clan_t));
    clan_member_t *member = calloc(1, sizeof(clan_member_t));
    member->trantorian = trantorian;
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);
    char *expected_resp = "[player, food food food food food food, linemate, deraumere, sibur, sibur, phiras, thystame, mendiane]";
    char *res = look_right(client, zappy);
    cr_assert_str_eq(res, expected_resp);
}