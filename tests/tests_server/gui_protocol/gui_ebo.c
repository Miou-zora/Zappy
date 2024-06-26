/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_ebo
*/

#include <criterion/criterion.h>
#include "gui_protocol.h"

Test(gui_ebo, test_gui_ebo_true)
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
    egg_t *egg = create_egg(1, 1, "Team1", 1);
    LIST_INSERT_HEAD(&zappy->game_struct->all_eggs, egg, next_egg);
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
    notifie_gui_ebo(&client, zappy);
    cr_assert_str_eq((zappy->responses.lh_first->content), "ebo 1\n");
}
