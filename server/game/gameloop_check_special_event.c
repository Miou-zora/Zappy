/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gameloop_check_special_event
*/

#include "server.h"

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
            event->client->trantorian = create_trantorian_from_event(
                event->request, zappy_s);
            return (true);
        }
    }
    return (false);
}
