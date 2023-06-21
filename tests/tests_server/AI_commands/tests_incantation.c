/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_incantation
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"
#include <criterion/criterion.h>

Test(do_incantation, incantation_success)
{
    char *av[] = {"./zappy_server", "-p", "12326", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    egg_t *egg2 = create_egg(1, 1, "test", 1);
    trantorian_t *trantorian2 = create_trantorian(egg2);
    trantorian2->direction = UP;
    object_t *objects2 = calloc(1, sizeof(object_t));
    trantorian2->inventory = objects2;
    event_t *event2 = calloc(1, sizeof(event_t));
    client_t *client2 = calloc(1, sizeof(client_t));
    event2->client = client2;
    event2->client->trantorian = trantorian2;
    client2->trantorian->inventory->nb_of_objects[LINEMATE] = 1;
    do_incantation(client2, zappy, NULL);
    cr_assert_str_eq(zappy->responses.lh_first->content, "Elevation underway Current level: 1\n");
}

Test(do_incantation, incancation_failure)
{
    char *av[] = {"./zappy_server", "-p", "12328", "-x", "10", "-y", "10", "-n",
        "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    egg_t *egg2 = create_egg(2, 2, "tes2", 2);
    trantorian_t *trantorian2 = create_trantorian(egg2);
    trantorian2->direction = DOWN;
    object_t *objects2 = calloc(1, sizeof(object_t));
    trantorian2->inventory = objects2;
    event_t *event2 = calloc(1, sizeof(event_t));
    client_t *client2 = calloc(1, sizeof(client_t));
    event2->client = client2;
    event2->client->trantorian = trantorian2;
    client2->trantorian->inventory->nb_of_objects[LINEMATE] = 1;
    client2->trantorian->level = 2;
    do_incantation(client2, zappy, NULL);
    cr_assert_str_eq(zappy->responses.lh_first->content, "ko\n");
}
