/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pbc
*/

#include <criterion/criterion.h>
#include "gui_protocol.h"

Test(gui_pbc, test_gui_pbc_true)
{
    char *args[] = {"./zappy_server", NULL};
    int ac = 1;
    zappy_t *zappy = build_server(ac, args);
    client_t *gui_client = calloc(1, sizeof(client_t));
    gui_client->is_graphic = true;
    gui_client->is_connected = true;
    gui_client->is_logged = true;
    gui_client->fd = 1;
    add_client_to_list(gui_client, zappy);
    client_t client = {0};
    client.trantorian = calloc(1, sizeof(trantorian_t));
    client.is_connected = true;
    client.is_graphic = false;
    client.is_logged = true;
    client.trantorian->id = 1;
    client.trantorian->position.x = 1;
    client.trantorian->position.y = 1;
    client.trantorian->direction = UP;
    client.trantorian->level = 1;
    client.trantorian->team_name = strdup("Team1");
    client.is_graphic = false;
    notifie_gui_pbc("Coucou", client.trantorian, zappy);
    for (int i = 0; i < 12; i++) {
        LIST_REMOVE(zappy->responses.lh_first, next);
    }
    cr_assert_str_eq(zappy->responses.lh_first->content, "pbc 1 Coucou\n");
}
