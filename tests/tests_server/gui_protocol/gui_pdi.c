/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pdi
*/

#include <criterion/criterion.h>
#include "server.h"
#include "gui_protocol.h"


Test(send_death_to_gui, testPdiCommand)
{
    client_t *client = calloc(1, sizeof(client_t));
    char *av[] = {"./zappy_server", "-p", "6661", "-x", "10", "-y", "10", "-n",
    "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);

    client->is_connected = true;
    client->is_logged = true;
    client->is_graphic = true;
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
    trantorian->id = 23;
    trantorian->inventory = calloc(1, sizeof(object_t));

    send_death_to_gui(trantorian, zappy);
    for (int i = 0; i < 10; i++) {
        LIST_REMOVE(zappy->responses.lh_first, next);
    }
    cr_assert_str_eq(zappy->responses.lh_first->content, "pdi 23\n");
}
