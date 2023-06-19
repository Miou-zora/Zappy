/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pnw
*/

#include "server.h"
#include "gui_protocol.h"
#include "trantorian.h"
#include <criterion/criterion.h>

Test(gui_pnw, test_gui_pnw)
{
    char *args[] = {"./zappy_server", "-p", "6670", "-x", "10", "-y", "10",
        "-n", "Team1", "Team2", "-c", "10", "-f", "10", NULL};
    int ac = 14;
    zappy_t *zappy = build_server(ac, args);
    client_t *gui_client = calloc(1, sizeof(client_t));
    gui_client->is_graphic = true;
    LIST_INSERT_HEAD(&zappy->clients, gui_client, next);
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
    client.is_graphic = true;
    gui_pnw(&client, zappy);
    cr_assert_str_eq(zappy->responses.lh_first->content, "pnw 1 1 1 1 1 Team1\n");
}
