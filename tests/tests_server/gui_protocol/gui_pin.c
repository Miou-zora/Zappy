/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pin
*/

#include <criterion/criterion.h>
#include "gui_protocol.h"

// Test(send_gui_pin, valid_id)
// {
//     client_t *client = calloc(1, sizeof(client_t));
//     char *av[] = {"./zappy_server", "-p", "6395", "-x", "10", "-y", "10", "-n",
//     "toto", "-c", "10", "-f", "10", NULL};
//     zappy_t *zappy = build_server(14, av);
//     client_t *gui_client = calloc(1, sizeof(client_t));
//     gui_client->is_graphic = true;
//     LIST_INSERT_HEAD(&zappy->clients, gui_client, next);
//     client->is_connected = true;
//     client->is_logged = true;
//     client->is_graphic = false;
//     trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
//     trantorian->id = 1;
//     trantorian->position.x = 4;
//     trantorian->position.y = 4;
//     trantorian->inventory = calloc(1, sizeof(object_t));
//     client->trantorian = trantorian;
//     send_gui_pin(trantorian, client, zappy);
//     cr_assert_str_eq((zappy->responses.lh_first->content), "pin 1 4 4 0 0 0 0 0 0 0\n");
// }

// Test(send_gui_pin, valid_id2)
// {
//     client_t *client = calloc(1, sizeof(client_t));
//     char *av[] = {"./zappy_server", "-p", "6495", "-x", "10", "-y", "10", "-n",
//     "toto", "-c", "10", "-f", "10", NULL};
//     zappy_t *zappy = build_server(14, av);
//     client_t *gui_client = calloc(1, sizeof(client_t));
//     gui_client->is_graphic = true;
//     LIST_INSERT_HEAD(&zappy->clients, gui_client, next);
//     client->is_connected = true;
//     client->is_logged = true;
//     client->is_graphic = false;
//     trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));
//     trantorian->id = 1;
//     trantorian->position.x = 4;
//     trantorian->position.y = 4;
//     trantorian->inventory = calloc(1, sizeof(object_t));
//     trantorian->inventory->nb_of_objects[LINEMATE] = 3;
//     client->trantorian = trantorian;
//     send_gui_pin(trantorian, client, zappy);
//     cr_assert_str_eq((zappy->responses.lh_first->content), "pin 1 4 4 0 3 0 0 0 0 0\n");
// }
