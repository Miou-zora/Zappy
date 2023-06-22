/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** destroy
*/

#include "server.h"

static void destroy_args(argv_t *args)
{
    for (int i = 0; args->names[i] != NULL; i++)
        free(args->names[i]);
    free(args->names);
    free(args);
}

void destroy_zappy(zappy_t *zappy)
{
    client_t *client = NULL;
    response_t *response = NULL;

    destroy_args(zappy->args);
    LIST_FOREACH(client, &zappy->clients, next)
        destroy_client(client);
    LIST_FOREACH(response, &zappy->responses, next)
        destroy_response(response);
    free(zappy);
}
