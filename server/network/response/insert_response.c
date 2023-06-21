/*
** EPITECH PROJECT, 2023
** server
** File description:
** insert_response
*/

#include "server.h"
#include "network.h"
#include "response.h"

response_t *get_last_response(zappy_t *zappy)
{
    response_t *tmp = NULL;
    response_t *tmp2 = NULL;

    LIST_FOREACH(tmp, &zappy->responses, next) {
        tmp2 = tmp;
    }
    return (tmp2);
}

void add_response_to_list(response_t *response, zappy_t *zappy_s)
{
    if (response == NULL || zappy_s == NULL)
        return;
    if (zappy_s->responses.lh_first == NULL) {
        LIST_INSERT_HEAD(&zappy_s->responses, response, next);
        return;
    }
    LIST_INSERT_AFTER(get_last_response(zappy_s), response, next);
}
