/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** read
*/

#include "network.h"
#include <stdio.h>
#include <string.h>

int is_buffer_valid(char *buffer)
{
    for (int i = 0; buffer[i]; i++)
        if (buffer[i] == '\n')
            return (i);
    return (-1);
}

static void reset_idx(client_t *client)
{
    if (client->idx >= 1023) {
        memset(client->buffer, 0, 1024);
        client->idx = 0;
    }
}

static int read_socket(client_t *client, int buff_idx)
{
    if (read(client->fd, client->buffer, 1024 - buff_idx) <= 0) {
        client->is_connected = false;
        return (84);
    }
    return (0);
}

char *read_client(client_t *client)
{
    int index = 0;
    int buff_idx = 0;
    char *response = NULL;
    if (!client->is_connected)
        return (NULL);
    reset_idx(client);
    buff_idx = client->idx;
    if (read_socket(client, buff_idx) == 84)
        return (NULL);
    index = is_buffer_valid(client->buffer);
    if (index == -1) {
        client->idx += strlen(client->buffer);
        return (NULL);
    }
    response = strndup(client->buffer, index);
    memset(client->buffer, 0, 1024);
    client->idx = 0;
    return (response);
}
