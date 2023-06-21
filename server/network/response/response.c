/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** response
*/

#include "response.h"
#include "client.h"
#include "server.h"

response_t *create_response(char *msg)
{
    response_t *response = calloc(1, sizeof(response_t));

    if (response == NULL)
        return (NULL);
    response->content = strdup(msg);
    if (response->content == NULL)
        return (NULL);
    LIST_INIT(&response->clients);
    return (response);
}

int add_client_to_response(response_t *response, client_t *client)
{
    if (response == NULL || client == NULL)
        return (84);
    if (client->fd == -1 || !client->is_connected)
        return (84);
    LIST_INSERT_HEAD(&response->clients, client, next);
    return (0);
}

int remove_client_from_response(response_t *response, client_t *client)
{
    client_t *tmp = NULL;
    if (response == NULL || client == NULL)
        return (84);
    LIST_FOREACH(tmp, &response->clients, next) {
        if (tmp == client) {
            LIST_REMOVE(tmp, next);
            return (0);
        }
    }
    return (84);
}

int destroy_response(response_t *response)
{
    if (response == NULL)
        return (84);
    free(response->content);
    free(response);
    return (0);
}
