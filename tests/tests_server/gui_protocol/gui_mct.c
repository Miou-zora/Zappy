/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_mct
*/

#include "server.h"
#include "gui_protocol.h"
#include <criterion/criterion.h>

Test(gui_mct, number_of_responses)
{
    client_t *client = calloc(1, sizeof(client_t));
    char *av[] = {"./zappy_server", "-p", "3333", "-x", "10", "-y", "10", "-n",
    "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    event_t *event = create_event(NULL, client);
    client->is_connected = true;
    client->is_logged = true;
    client->is_graphic = true;
    int nb_responses = 0;
    zappy->game_struct = init_game_struct(zappy->args);
    fill_map(zappy->game_struct->map);
    handle_gui_mct(event, zappy);
    for (response_t *response = zappy->responses.lh_first; response; response = response->next.le_next)
        nb_responses++;
    cr_assert_eq(nb_responses, 110);
}

Test(gui_mct, response_content)
{
    client_t *client = calloc(1, sizeof(client_t));
    char *av[] = {"./zappy_server", "-p", "3433", "-x", "10", "-y", "10", "-n",
    "toto", "-c", "10", "-f", "10", NULL};
    zappy_t *zappy = build_server(13, av);
    event_t *event = create_event(NULL, client);
    client->is_connected = false;
    client->is_logged = false;
    client->is_graphic = false;
    zappy->game_struct = init_game_struct(zappy->args);
    fill_map(zappy->game_struct->map);
    handle_gui_mct(event, zappy);
    for (int i = 0; i < 10; i++) {
        LIST_REMOVE(zappy->responses.lh_first, next);
    }
    cr_assert_null(zappy->responses.lh_first);
}