/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_msz
*/

#include "gui_protocol.h"
#include "server.h"
#include <criterion/criterion.h>

Test(gui_msz, gui_msz_valid_case)
{
    client_t *client = calloc(1, sizeof(client_t));
    char *av[] = {"./zappy_server", "-p", "6660", "-x", "10", "-y", "10", "-n",
    "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    event_t *event = create_event(NULL, client);

    client->is_connected = true;
    client->is_logged = true;
    client->is_graphic = true;

    gui_msz(event, zappy);
    cr_assert_not_null(zappy->responses.lh_first);
    cr_assert_str_eq(zappy->responses.lh_first->content, "msz 10 10\n");
}

Test(gui_msz, gui_msz_invalid_case)
{
    client_t *client = calloc(1, sizeof(client_t));
    char *av[] = {"./zappy_server", "-p", "6666", "-x", "10", "-y", "10", "-n",
    "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    event_t *event = create_event(NULL, client);

    client->is_connected = false;
    client->is_logged = false;
    client->is_graphic = false;

    gui_msz(event, zappy);
    cr_assert_null(zappy->responses.lh_first);
}
