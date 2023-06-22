/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** player_command
*/

#include "player_command.h"
#include "trantorian.h"
#include "server.h"

void remove_command(client_t *client, int i)
{
    client->trantorian->command[i].timer = 0;
    client->trantorian->command[i].arg = NULL;
    client->trantorian->command[i].func = NULL;
}

void copy_command(client_t *client, int dest, int src)
{
    client->trantorian->command[dest].timer =
        client->trantorian->command[src].timer;
    client->trantorian->command[dest].arg =
        client->trantorian->command[src].arg;
    client->trantorian->command[dest].func =
        client->trantorian->command[src].func;
    remove_command(client, src);
}

int add_command(client_t *client, int timer,
    void (*func)(client_t *client, zappy_t *zappy, char *arg), char *arg)
{
    for (int i = 0; i < MAX_COMMAND; i++) {
        if (client->trantorian->command[i].timer == 0
            && client->trantorian->command[i].func == NULL) {
            client->trantorian->command[i].timer = timer;
            client->trantorian->command[i].arg = arg;
            client->trantorian->command[i].func = func;
            return (1);
        }
    }
    return (0);
}

void reset_list_command_client(client_t *client)
{
    if (client->trantorian == NULL)
        return;
    if (client->trantorian->command[0].func != NULL
        && client->trantorian->command[0].timer > 0)
        return;
    for (int i = 0; i < MAX_COMMAND - 1; i++) {
        if (client->trantorian->command[i].timer == 0
        && client->trantorian->command[i].func == NULL) {
            copy_command(client, i, i + 1);
        }
    }
}

void re_organize_list_command(zappy_t *zappy)
{
    client_t *client = NULL;

    LIST_FOREACH(client, &zappy->clients, next) {
        reset_list_command_client(client);
    }
}
