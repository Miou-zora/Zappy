/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_suc
*/

#include <criterion/criterion.h>
#include "gui_protocol.h"

Test(gui_suc, test_gui_suc_true)
{
    char *args[] = {"./zappy_server -0", NULL};
    int ac = 1;
    zappy_t *zappy = build_server(ac, args);
    client_t *gui_client = calloc(1, sizeof(client_t));
    gui_client->is_graphic = true;
    gui_client->is_connected = true;
    gui_client->is_logged = true;
    gui_client->fd = 1;
    add_client_to_list(gui_client, zappy);
    notifie_gui_suc(gui_client, zappy);
}
