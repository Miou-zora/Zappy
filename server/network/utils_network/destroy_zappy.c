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
    destroy_args(zappy->args);
    free(zappy);
}
