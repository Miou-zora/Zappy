/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_edi
*/

#include <criterion/criterion.h>
#include "gui_protocol.h"

Test(gui_edi, test_gui_edi_true)
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
    egg_t *egg = create_egg(1, 1, "Team1", 1);
    client.trantorian = create_trantorian(egg);
    client.is_connected = true;
    client.is_graphic = false;
    client.is_logged = true;
    client.trantorian->direction = UP;
    client.trantorian->level = 1;
    client.trantorian->team_name = strdup("Team1");
    client.is_graphic = false;
    notifie_gui_edi(egg, zappy);
    cr_assert_str_eq((zappy->responses.lh_first->content), "edi 1\n");
}
