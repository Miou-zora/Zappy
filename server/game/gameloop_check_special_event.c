/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gameloop_check_special_event
*/

#include "server.h"
#include "gui_protocol.h"

bool is_graphical(event_t *event, zappy_t *zappy_s)
{
    if (strncmp(event->request, "GRAPHIC", 7) == 0) {
        display_log("New graphical client");
        event->client->is_graphic = true;
        event->client->is_logged = true;
        notifie_gui_msz(event->client, zappy_s);
        notifie_gui_sgt(event->client, zappy_s);
        handle_gui_mct(event, zappy_s);
        handle_gui_tna(event, zappy_s);
        return (true);
    }
    event->client->is_connected = false;
    return (false);
}

static void create_new_trantorian(event_t *event, zappy_t *zappy_s)
{
    trantorian_t *trantorian = create_trantorian_from_event(
    event->request, zappy_s);
    if (!trantorian) {
        display_log("Error: trantorian not created\n");
        return;
    }
    (void)trantorian;
    event->client->is_logged = true;
    event->client->is_graphic = false;
    event->client->is_connected = true;
    trantorian->client = event->client;
    event->client->trantorian = trantorian;
    notifie_gui_pnw(event->client, zappy_s);
}

bool special_event(event_t *event, zappy_t *zappy_s)
{
    if (event->client->is_logged == true)
        return (false);
    if (event->request == NULL) {
        event_connection(event, zappy_s);
        return (true);
    }

    for (size_t i = 0; zappy_s->args->names[i] != NULL; i++) {
        if (strncmp(event->request, zappy_s->args->names[i],
            strlen(zappy_s->args->names[i])) == 0) {
            display_log("New trantorian client");
            create_new_trantorian(event, zappy_s);
            return (true);
        }
    }
    return (is_graphical(event, zappy_s));
}
