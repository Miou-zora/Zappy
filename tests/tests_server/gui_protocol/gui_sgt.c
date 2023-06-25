/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_sgt
*/

#include "gui_protocol.h"
#include "server.h"
#include <criterion/criterion.h>

Test(gui_sgt, valid_case)
{
    char *args[] = {"./zappy_server", "-p", "7670", "-x", "10", "-y", "10",
        "-n", "Team1", "Team2", "-c", "10", "-f", "10", NULL};
    int ac = 14;
    zappy_t *zappy = build_server(ac, args);
    client_t *gui_client = calloc(1, sizeof(client_t));
    gui_client->is_graphic = true;
    gui_client->is_connected = true;
    gui_client->is_logged = true;
    for (int i = 0; i < 20; i++) {
        LIST_REMOVE(zappy->responses.lh_first, next);
    }
    event_t *event = create_event("sgt\n", gui_client);
    handle_gui_sgt(event, zappy);
    cr_assert_str_eq(zappy->responses.lh_first->content, "sgt 10\n");
}

Test(gui_sgt, invalid_case)
{
    char *args[] = {"./zappy_server", "-p", "7610", "-x", "10", "-y", "10",
        "-n", "Team1", "Team2", "-c", "10", "-f", "10", NULL};
    int ac = 14;
    zappy_t *zappy = build_server(ac, args);
    client_t *gui_client = calloc(1, sizeof(client_t));
    gui_client->is_graphic = false;
    gui_client->is_connected = true;
    gui_client->is_logged = true;
    for (int i = 0; i < 20; i++) {
        LIST_REMOVE(zappy->responses.lh_first, next);
    }
    event_t *event = create_event("sgt\n", gui_client);
    handle_gui_sgt(event, zappy);
    cr_assert_eq(zappy->responses.lh_first, NULL);
}
