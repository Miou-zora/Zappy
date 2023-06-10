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

char *read_client(int fd)
{
    char buffer[BUFFER_SIZE] = {0};
    int len = 0;
    int read_ret = 0;

    len = read(fd, buffer, BUFFER_SIZE);

    if (len <= 0)
        return (NULL);
    while (is_buffer_valid(buffer) == -1) {
        read_ret = read(fd, buffer + len, BUFFER_SIZE - len);
        if (read_ret <= 0)
            return (NULL);
        len += read_ret;
    }
    return (strndup(buffer, is_buffer_valid(buffer) + 1));
}
