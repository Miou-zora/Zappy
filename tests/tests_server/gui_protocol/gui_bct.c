/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_bct
*/

#include "server.h"
#include "gui_protocol.h"
#include <criterion/criterion.h>


Test(gui_bct, valid_coordinates)
{
    client_t *client = calloc(1, sizeof(client_t));
    char *av[] = {"./zappy_server", "-p", "6789", "-x", "10", "-y", "10", "-n",
    "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    event_t *event = create_event("bct 1 1\n", client);
    client->is_connected = true;
    client->is_logged = true;
    client->is_graphic = true;
    zappy->game_struct = init_game_struct(zappy->args);
    fill_map(zappy->game_struct->map);
    handle_gui_bct(event, zappy);
    cr_assert_not_null(zappy->responses.lh_first);
}

Test(gui_bct, negative_coordinates)
{
    client_t *client = calloc(1, sizeof(client_t));
    char *av[] = {"./zappy_server", "-p", "9876", "-x", "10", "-y", "10", "-n",
    "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    event_t *event = create_event("bct -1 -6\n", client);
    client->is_connected = false;
    client->is_logged = false;
    client->is_graphic = false;
    zappy->game_struct = init_game_struct(zappy->args);
    fill_map(zappy->game_struct->map);
    handle_gui_bct(event, zappy);
    for (int i = 0; i < 10; i++) {
        LIST_REMOVE(zappy->responses.lh_first, next);
    }
    cr_assert_null(zappy->responses.lh_first);
}

Test(gui_bct, too_big_coordinates)
{
    client_t *client = calloc(1, sizeof(client_t));
    char *av[] = {"./zappy_server", "-p", "9476", "-x", "10", "-y", "10", "-n",
    "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    event_t *event = create_event("bct 11 11\n", client);
    client->is_connected = false;
    client->is_logged = false;
    client->is_graphic = false;
    zappy->game_struct = init_game_struct(zappy->args);
    fill_map(zappy->game_struct->map);
    handle_gui_bct(event, zappy);
    for (int i = 0; i < 10; i++) {
        LIST_REMOVE(zappy->responses.lh_first, next);
    }
    cr_assert_null(zappy->responses.lh_first);
}

Test(gui_bct, no_arguments)
{
    client_t *client = calloc(1, sizeof(client_t));
    char *av[] = {"./zappy_server", "-p", "6523", "-x", "10", "-y", "10", "-n",
    "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    event_t *event = create_event("bct\n", client);
    client->is_connected = false;
    client->is_logged = false;
    client->is_graphic = false;
    zappy->game_struct = init_game_struct(zappy->args);
    fill_map(zappy->game_struct->map);
    handle_gui_bct(event, zappy);
    for (int i = 0; i < 10; i++) {
        LIST_REMOVE(zappy->responses.lh_first, next);
    }
    cr_assert_null(zappy->responses.lh_first);
}

Test(gui_bct, on_limits)
{
    client_t *client = calloc(1, sizeof(client_t));
    char *av[] = {"./zappy_server", "-p", "3214", "-x", "10", "-y", "10", "-n",
    "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    event_t *event = create_event("bct 10 10\n", client);
    client->is_connected = false;
    client->is_logged = false;
    client->is_graphic = false;
    zappy->game_struct = init_game_struct(zappy->args);
    fill_map(zappy->game_struct->map);
    handle_gui_bct(event, zappy);
    for (int i = 0; i < 10; i++) {
        LIST_REMOVE(zappy->responses.lh_first, next);
    }
    cr_assert_null(zappy->responses.lh_first);
}