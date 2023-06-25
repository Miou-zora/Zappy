/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pgt
*/

#include "server.h"
#include "game.h"
#include <criterion/criterion.h>

Test(take_object, gui_pgt_success)
{
    char *av[] = {"./zappy_server", "-p", "3258", "-x", "10", "-y", "10", "-n",
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
    map_t *map = zappy->game_struct->map;
    map->tile[client->trantorian->position.y]
        [client->trantorian->position.x].nb_of_objects[FOOD] = 1;

    take_object(client, zappy, "food");
    for (int i = 0; i < 10; i++) {
        LIST_REMOVE(zappy->responses.lh_first, next);
    }
    cr_assert_str_eq(zappy->responses.lh_first->content, "ok\n");
    response_t * response = LIST_FIRST(&zappy->responses);
    LIST_REMOVE(response, next);
    cr_assert_str_eq(zappy->responses.lh_first->content, "pgt 1 0\n");

}