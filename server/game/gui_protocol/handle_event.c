/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** handle_event
*/

#include "server.h"
#include "gui_protocol.h"

static void (*ptr[])(event_t *event, zappy_t *zappy) = {
    &handle_gui_msz,
    &handle_gui_sgt,
    &handle_gui_mct,
    &handle_gui_bct,
    &handle_gui_tna,
    &handle_gui_ppo,
    &handle_gui_plv,
    &handle_gui_pin,
    NULL
    };

static const char *names[] = {
    "msz",
    "sgt",
    "mct",
    "bct",
    "tna",
    "ppo",
    "plv",
    "pin",
    NULL
    };

bool handle_gui_event(event_t *event, zappy_t *zappy)
{
    if (event->request == NULL) {
        event->client->is_connected = false;
        return (false);
    }
    if (!event->client->is_graphic || !event->client->is_logged ||
        !event->client->is_connected)
        return (false);
    for (size_t i = 0; names[i] != NULL; i++) {
        if (strncmp(event->request, names[i], strlen(names[i])) == 0) {
            ptr[i](event, zappy);
            return (true);
        }
    }
    bad_command(event, zappy);
    return (false);
}
