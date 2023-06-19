/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gameloop_check_special_event
*/

#include "server.h"
#include "gui_protocol.h"

//gui_mct(event->client, zappy_s);
//gui_tna(event->client, zappy_s);
bool is_graphical(event_t *event, zappy_t *zappy_s)
{
    if (strcmp(event->request, "GUI\n") == 0) {
        event->client->is_graphic = true;
        event->client->is_logged = true;
        return (true);
    }
    event->client->is_connected = false;
    gui_msz(event, zappy_s);
    gui_sgt(event, zappy_s);
    return (false);
}

bool special_event(event_t *event, zappy_t *zappy_s)
{
    if (event->request == NULL) {
        connection(event, zappy_s);
        return (true);
    }
    for (size_t i = 0; zappy_s->args->names[i] != NULL; i++) {
        if (strncmp(event->request, zappy_s->args->names[i],
        strlen(zappy_s->args->names[i])) == 0) {
            event->client->is_logged = true;
            event->client->is_graphic = false;
            event->client->trantorian = create_trantorian_from_event(
                event->request, zappy_s);
            gui_pnw(event->client, zappy_s);
            return (true);
        }
    }
    return (is_graphical(event, zappy_s));
}
