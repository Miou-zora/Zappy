/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_tna
*/

#include "server.h"
#include "gui_protocol.h"
#include <criterion/criterion.h>

Test(gui_tna, valid_command)
{
    client_t *client = calloc(1, sizeof(client_t));
    char *av[] = {"./zappy_server", "-p", "7319", "-x", "10", "-y", "10", "-n",
    "toto", "titi", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    event_t *event = create_event("tna\n", client);
    client->is_connected = true;
    client->is_logged = true;
    client->is_graphic = true;
    zappy->game_struct = init_game_struct(zappy->args);
    handle_gui_tna(event, zappy);
    cr_assert_not_null(zappy->responses.lh_first);

    char names[2][5] = {"toto", "titi"};
    for (size_t i = 0; zappy->args->names[i] != NULL; i++) {
        cr_assert_str_eq(zappy->args->names[i], names[i]);
    }
}
