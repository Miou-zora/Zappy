/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_forward
*/

#include "server.h"
#include "trantorian.h"
#include <criterion/criterion.h>

Test(move_into_the_good_way, test_move_into_the_good_way)
{
     char *av[] = {"./zappy_server", "-p", "12347", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    zappy->args = malloc(sizeof(argv_t));
    zappy->args->width = 10;
    zappy->args->height = 10;
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
    trantorian->direction = UP;
    trantorian->position.x = 0;
    trantorian->position.y = 0;
    event_t *event = calloc(1, sizeof(event_t));
    client_t *client = calloc(1, sizeof(client_t));
    event->client = client;
    event->client->trantorian = trantorian;

    move_into_the_good_way(event, zappy, NULL);
    printf(" DIRECTION = %d", client->trantorian->direction);
    fflush(stdout);
    printf("x = %ld\ny = %ld\n", event->client->trantorian->position.x, event->client->trantorian->position.y);
    fflush(stdout);
    cr_assert_eq(trantorian->position.x, 0);
    cr_assert_eq(trantorian->position.y, 9);
    trantorian->direction = RIGHT;
    trantorian->position.x = 0;
    trantorian->position.y = 0;
    move_into_the_good_way(event, zappy, NULL);
    cr_assert_eq(trantorian->position.x, 1);
    cr_assert_eq(trantorian->position.y, 0);
    trantorian->direction = DOWN;
    trantorian->position.x = 0;
    trantorian->position.y = 0;
    move_into_the_good_way(event, zappy, NULL);
    cr_assert_eq(trantorian->position.x, 0);
    cr_assert_eq(trantorian->position.y, 1);
    trantorian->direction = LEFT;
    trantorian->position.x = 0;
    trantorian->position.y = 0;
    move_into_the_good_way(event, zappy, NULL);
    cr_assert_eq(trantorian->position.x, 9);
    cr_assert_eq(trantorian->position.y, 0);
    trantorian->direction = DOWN;
    trantorian->position.x = 9;
    trantorian->position.y = 9;
    move_into_the_good_way(event, zappy, NULL);
    cr_assert_eq(trantorian->position.x, 9);
    cr_assert_eq(trantorian->position.y, 0);
}