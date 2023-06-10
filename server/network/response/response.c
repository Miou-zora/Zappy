/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** response
*/

#include "response.h"

response_t *create_response(char *msg)
{
    response_t *response = calloc(1, sizeof(response_t));

    if (response == NULL)
        return (NULL);
    response->content = strdup(msg);
    LIST_INIT(&response->clients);
    if (response->content == NULL)
        return (NULL);
    return (response);
}

int add_client_to_response(response_t *response, client_t *client)
{
    if (response == NULL || client == NULL)
        return (84);
    LIST_INSERT_HEAD(&response->clients, client, next);
    return (0);
}

int remove_client_from_response(response_t *response, client_t *client)
{
    if (response == NULL || client == NULL)
        return (84);
    LIST_REMOVE(client, next);
    return (0);
}

int destroy_response(response_t *response)
{
    if (response == NULL)
        return (84);
    free(response->content);
    free(response);
    return (0);
}
