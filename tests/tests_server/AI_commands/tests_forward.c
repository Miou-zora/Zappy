/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_forward
*/

#include "server.h"
#include "trantorian.h"
#include <criterion/criterion.h>

void move_forward(client_t *client, zappy_t *zappy, char *param);

Test(move_forward, test_move_forward)
{
     char *av[] = {"./zappy_server", "-p", "12398", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    (void) zappy;
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

    move_forward(client, zappy, NULL);
    cr_assert_eq(trantorian->position.x, 0);
    cr_assert_eq(trantorian->position.y, 9);
    trantorian->direction = RIGHT;
    trantorian->position.x = 0;
    trantorian->position.y = 0;
    move_forward(client, zappy, NULL);
    cr_assert_eq(trantorian->position.x, 1);
    cr_assert_eq(trantorian->position.y, 0);
    trantorian->direction = DOWN;
    trantorian->position.x = 0;
    trantorian->position.y = 0;
    move_forward(client, zappy, NULL);
    cr_assert_eq(trantorian->position.x, 0);
    cr_assert_eq(trantorian->position.y, 1);
    trantorian->direction = LEFT;
    trantorian->position.x = 0;
    trantorian->position.y = 0;
    move_forward(client, zappy, NULL);
    cr_assert_eq(trantorian->position.x, 9);
    cr_assert_eq(trantorian->position.y, 0);
    trantorian->direction = DOWN;
    trantorian->position.x = 9;
    trantorian->position.y = 9;
    move_forward(client, zappy, NULL);
    cr_assert_eq(trantorian->position.x, 9);
    cr_assert_eq(trantorian->position.y, 0);
}