/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** event
*/

#include "event.h"
#include "server.h"
#include <string.h>

event_t *get_last_event(zappy_t *zappy)
{
    event_t *tmp = NULL;
    event_t *tmp2 = NULL;

    LIST_FOREACH(tmp, &zappy->events, next) {
        tmp2 = tmp;
    }
    return (tmp2);
}

void add_event_to_list(event_t *event, zappy_t *zappy_s)
{
    if (event == NULL || zappy_s == NULL)
        return;
    if (zappy_s->events.lh_first == NULL) {
        LIST_INSERT_HEAD(&zappy_s->events, event, next);
        return;
    }
    LIST_INSERT_AFTER(get_last_event(zappy_s), event, next);
}

event_t *create_event(char *request, client_t *client)
{
    event_t *event = calloc(1, sizeof(event_t));

    if (!event)
        return (NULL);
    if (request) {
        event->request = strdup(request);
        if (!event->request)
            return (NULL);
    }
    event->client = client;
    return (event);
}

void destroy_event(event_t *event)
{
    free(event->request);
    free(event);
}
