/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_turn
*/

#include "server.h"
#include <criterion/criterion.h>

Test(left, turn_left)
{
    char *av[] = {"./zappy_server", "-p", "12348", "-x", "10", "-y", "10", "-n",
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

    left(event, zappy, NULL);
    cr_assert_eq(trantorian->direction, LEFT);
    left(event, zappy, NULL);
    cr_assert_eq(trantorian->direction, DOWN);
}

Test(right, turn_right)
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

    right(event, zappy, NULL);
    cr_assert_eq(trantorian->direction, RIGHT);
    right(event, zappy, NULL);
    cr_assert_eq(trantorian->direction, DOWN);
}