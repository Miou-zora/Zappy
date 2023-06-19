/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_inventory
*/

#include "server.h"
#include "trantorian.h"
#include <criterion/criterion.h>

Test(inventory, inventory_without_nothing)
{
    char *av[] = {"./zappy_server", "-p", "12352", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
    trantorian->direction = UP;
    object_t *objects = calloc(1, sizeof(object_t));
    trantorian->inventory = objects;
    event_t *event = calloc(1, sizeof(event_t));
    client_t *client = calloc(1, sizeof(client_t));
    event->client = client;
    event->client->trantorian = trantorian;

    inventory(event, zappy, NULL);
    char *expected_resp = "[food 0, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0]";
    cr_assert_str_eq(zappy->responses.lh_first->content, expected_resp);
}

Test(inventory, inventory_with_food)
{
    char *av[] = {"./zappy_server", "-p", "12353", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
    trantorian->direction = UP;
    object_t *objects = calloc(1, sizeof(object_t));
    trantorian->inventory = objects;
    event_t *event = calloc(1, sizeof(event_t));
    client_t *client = calloc(1, sizeof(client_t));
    event->client = client;
    event->client->trantorian = trantorian;
    objects->nb_of_objects[0] = 10;

    inventory(event, zappy, NULL);
    char *expected_resp = "[food 10, linemate 0, deraumere 0, sibur 0, mendiane 0, phiras 0, thystame 0]";
    cr_assert_str_eq(zappy->responses.lh_first->content, expected_resp);
}