/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pin
*/

#include <criterion/criterion.h>
#include "gui_protocol.h"

Test(gui_pin, test_gui_pin_true)
{
    char *args[] = {"./zappy_server", NULL};
    int ac = 1;
    zappy_t *zappy = build_server(ac, args);
    client_t *gui_client = calloc(1, sizeof(client_t));
    egg_t *egg = create_egg(1, 1, "Team1", 1);
    gui_client->is_graphic = true;
    gui_client->is_connected = true;
    gui_client->is_logged = true;
    gui_client->fd = 1;
    add_client_to_list(gui_client, zappy);
    trantorian_t *trantorian = create_trantorian(egg);
    send_gui_pin(trantorian, zappy);
    cr_assert_str_eq((zappy->responses.lh_first->content), "pin 1 1 1 1260 0 0 0 0 0 0\n");
}
