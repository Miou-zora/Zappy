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
    client.trantorian->inventory = calloc(1, sizeof(object_t));
    client.trantorian->inventory->nb_of_objects[LINEMATE] = 3;
    client.trantorian->inventory->nb_of_objects[DERAUMERE] = 2;
    client.trantorian->inventory->nb_of_objects[SIBUR] = 1;
    client.trantorian->direction = UP;
    client.trantorian->level = 1;
    client.trantorian->team_name = strdup("Team1");
    send_gui_pin(client.trantorian, &client, zappy);
    cr_assert_str_eq((zappy->responses.lh_first->content), "pin 1 1 1 0 3 2 1 0 0 0\n");
}
