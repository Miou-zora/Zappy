/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** event
*/

#include "event.h"
#include <string.h>

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
