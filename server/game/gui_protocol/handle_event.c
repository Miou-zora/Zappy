/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** handle_event
*/

#include "server.h"
#include "gui_protocol.h"

//ptr function with gui_msz only for the moment
static void (*ptr[])(event_t *event, zappy_t *zappy) = {&gui_msz};

static const char *names[] = {"msz"};

bool handle_gui_event(event_t *event, zappy_t *zappy)
{
    if (event->request == NULL) {
        event->client->is_connected = false;
        return (false);
    }
    if (!event->client->is_graphic || !event->client->is_logged ||
        !event->client->is_connected)
        return (false);

    for (size_t i = 0; i < 1; i++) {
        if (strncmp(event->request, names[i], strlen(names[i])) == 0) {
            ptr[i](event, zappy);
            return (true);
        }
    }
    bad_command(event, zappy);
    return (false);
}
