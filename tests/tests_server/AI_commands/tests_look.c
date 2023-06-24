/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_look
*/

#include "server.h"
#include "look.h"
#include <criterion/criterion.h>

Test(look_up, test_look_up_level_3)
{
    char *av[] = {"./zappy_server", "-p", "9239", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    zappy->game_struct->map = create_map(10, 10);
    zappy->game_struct->map->tile[5][0].nb_of_objects[FOOD] = 1;
    zappy->game_struct->map->tile[5][1].nb_of_objects[LINEMATE] = 1;
    zappy->game_struct->map->tile[5][2].nb_of_objects[DERAUMERE] = 1;
    zappy->game_struct->map->tile[4][9].nb_of_objects[SIBUR] = 1;
    zappy->game_struct->map->tile[4][0].nb_of_objects[SIBUR] = 1;
    zappy->game_struct->map->tile[4][1].nb_of_objects[PHIRAS] = 1;
    zappy->game_struct->map->tile[4][2].nb_of_objects[THYSTAME] = 1;
    zappy->game_struct->map->tile[4][3].nb_of_objects[MENDIANE] = 1;
    zappy->game_struct->map->tile[3][8].nb_of_objects[MENDIANE] = 1;
    zappy->game_struct->map->tile[3][9].nb_of_objects[DERAUMERE] = 1;
    zappy->game_struct->map->tile[3][0].nb_of_objects[LINEMATE] = 1;
    zappy->game_struct->map->tile[3][1].nb_of_objects[SIBUR] = 1;
    zappy->game_struct->map->tile[3][2].nb_of_objects[PHIRAS] = 1;
    zappy->game_struct->map->tile[3][3].nb_of_objects[THYSTAME] = 1;
    zappy->game_struct->map->tile[3][4].nb_of_objects[MENDIANE] = 1;

    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
    trantorian->position.x = 1;
    trantorian->position.y = 6;
    trantorian->direction= UP;
    trantorian->level = 3;
    vector_t cpos = {.x = -1, .y =0};
    client_t *client = calloc(1, sizeof(client_t));
    client->trantorian = trantorian;
    event_t *event = create_event("Look\n", client);
    event->client = client;
    clan_t *clan = calloc(1, sizeof(clan_t));
    clan_member_t *member = calloc(1, sizeof(clan_member_t));
    member->trantorian = trantorian;
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);
    char *expected_resp = "[player, food, linemate, deraumere, sibur, sibur, phiras, thystame, mendiane, mendiane, deraumere, linemate, sibur, phiras, thystame, mendiane]\n";
    char *res = send_look(client, zappy, cpos);
    printf("|%s|\n", res);
    printf("|%s|\n", expected_resp);
    cr_assert_str_eq(res, expected_resp);
}


Test(look_down, test_down_level_3)
{
    char *av[] = {"./zappy_server", "-p", "9289", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    zappy->game_struct->map = create_map(10, 10);
    zappy->game_struct->map->tile[1][5].nb_of_objects[FOOD] = 6; //tile 1
    zappy->game_struct->map->tile[1][4].nb_of_objects[LINEMATE] = 1; //tile 2
    zappy->game_struct->map->tile[1][3].nb_of_objects[DERAUMERE] = 1; //tile 3
    zappy->game_struct->map->tile[2][6].nb_of_objects[SIBUR] = 1; //tile 4
    zappy->game_struct->map->tile[2][5].nb_of_objects[SIBUR] = 1; //tile 5
    zappy->game_struct->map->tile[2][4].nb_of_objects[PHIRAS] = 1; //tile 6
    zappy->game_struct->map->tile[2][3].nb_of_objects[THYSTAME] = 1; //tile 7
    zappy->game_struct->map->tile[2][2].nb_of_objects[MENDIANE] = 1; //tile 8
    zappy->game_struct->map->tile[3][7].nb_of_objects[MENDIANE] = 1; //tile 9
    zappy->game_struct->map->tile[3][6].nb_of_objects[DERAUMERE] = 1; //tile 10
    zappy->game_struct->map->tile[3][5].nb_of_objects[LINEMATE] = 1; //tile 11
    zappy->game_struct->map->tile[3][4].nb_of_objects[SIBUR] = 1; //tile 12
    zappy->game_struct->map->tile[3][3].nb_of_objects[PHIRAS] = 1; //tile 13
    zappy->game_struct->map->tile[3][2].nb_of_objects[THYSTAME] = 1; //tile 14
    zappy->game_struct->map->tile[3][1].nb_of_objects[MENDIANE] = 1; //tile 15

    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
    trantorian->position.x = 4;
    trantorian->position.y = 0;
    trantorian->direction= DOWN;
    trantorian->level = 3;
    client_t *client = calloc(1, sizeof(client_t));
    client->trantorian = trantorian;
    event_t *event = create_event("Look\n", client);
    event->client = client;
    vector_t cpos = {.x = -1, .y =0};
    clan_t *clan = calloc(1, sizeof(clan_t));
    clan_member_t *member = calloc(1, sizeof(clan_member_t));
    member->trantorian = trantorian;
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);
    char *expected_resp = "[player, deraumere, linemate, food food food food food food, mendiane, thystame, phiras, sibur, sibur, mendiane, thystame, phiras, sibur, linemate, deraumere, mendiane]\n";
    char *res = send_look(client, zappy, cpos);
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
    vector_t cpos = {.x = 0, .y = 1};
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);
    char *expected_resp = "[player, food food, linemate, deraumere, sibur, sibur, phiras, thystame, mendiane]\n";
    char *res = send_look(client, zappy, cpos);
    cr_assert_str_eq(res, expected_resp);
}

Test(look_right, test_look_right)
{
    char *av[] = {"./zappy_server", "-p", "4429", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    zappy->game_struct->map = create_map(10, 10); // reset the map because they spwan default
    zappy->game_struct->map->tile[3][1].nb_of_objects[FOOD] = 6;
    zappy->game_struct->map->tile[4][1].nb_of_objects[LINEMATE] = 1;
    zappy->game_struct->map->tile[5][1].nb_of_objects[DERAUMERE] = 1;
    zappy->game_struct->map->tile[2][2].nb_of_objects[SIBUR] = 1;
    zappy->game_struct->map->tile[3][2].nb_of_objects[SIBUR] = 1;
    zappy->game_struct->map->tile[4][2].nb_of_objects[PHIRAS] = 1;
    zappy->game_struct->map->tile[5][2].nb_of_objects[THYSTAME] = 1;
    zappy->game_struct->map->tile[6][2].nb_of_objects[MENDIANE] = 1;

    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
    trantorian->position.x = 0;
    trantorian->position.y = 4;
    trantorian->direction= RIGHT;
    trantorian->level = 2;
    client_t *client = calloc(1, sizeof(client_t));
    client->trantorian = trantorian;
    event_t *event = create_event("Look\n", client);
    event->client = client;
    clan_t *clan = calloc(1, sizeof(clan_t));
    clan_member_t *member = calloc(1, sizeof(clan_member_t));
    vector_t cpos = {.x = 0, .y = -1};
    member->trantorian = trantorian;
    LIST_INSERT_HEAD(&clan->all_members, member, next_clan_member);
    LIST_INSERT_HEAD(&zappy->game_struct->all_clans, clan, next_clan);
    char *expected_resp = "[player, food food food food food food, linemate, deraumere, sibur, sibur, phiras, thystame, mendiane]\n";
    char *res = send_look(client, zappy, cpos);
    cr_assert_str_eq(res, expected_resp);
}