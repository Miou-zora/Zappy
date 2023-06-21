/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_set_object
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"
#include <criterion/criterion.h>

Test(set_object, set_object_success)
{
    char *av[] = {"./zappy_server", "-p", "13597", "-x", "10", "-y", "10", "-n",
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
    trantorian->inventory->nb_of_objects[LINEMATE] = 1;

    set_object(client, zappy, "LINEMATE");
    cr_assert_str_eq(zappy->responses.lh_first->content, "ok\n");
}

Test(set_object, set_object_fail)
{
    char *av[] = {"./zappy_server", "-p", "16147", "-x", "10", "-y", "10", "-n",
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
    trantorian->inventory->nb_of_objects[LINEMATE] = 1;

    set_object(client, zappy, "MENDIANE");
    cr_assert_str_eq(zappy->responses.lh_first->content, "ko\n");
}