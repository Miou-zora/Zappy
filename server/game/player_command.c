/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** player_command
*/

#include "player_command.h"
#include "trantorian.h"

void remove_command(client_t *client, int i)
{
    client->trantorian->command[i].timer = 0;
    client->trantorian->command[i].command = NONE;
    client->trantorian->command[i].func = NULL;
}

void copy_command(client_t *client, int dest, int src)
{
    client->trantorian->command[dest].timer =
        client->trantorian->command[src].timer;
    client->trantorian->command[dest].command =
        client->trantorian->command[src].command;
    client->trantorian->command[dest].func =
        client->trantorian->command[src].func;
    remove_command(client, src);
}

int add_command(client_t *client, enum COMMAND command, int timer,
    void (*func)(client_t *client, zappy_t *zappy, char *arg))
{
    for (int i = 0; i < MAX_COMMAND; i++) {
        if (client->trantorian->command[i].timer == 0
        && client->trantorian->command[i].command == NONE) {
            client->trantorian->command[i].timer = timer;
            client->trantorian->command[i].command = command;
            client->trantorian->command[i].func = func;
            return (1);
        }
    }
    return (0);
}

void reset_commands(client_t *client)
{
    for (int i = 0; i < MAX_COMMAND; i++)
        remove_command(client, i);
}

void re_organize_list_command(client_t *client)
{
    if (client->trantorian->command[0].command != NONE)
        return;

    for (int i = 0; i < MAX_COMMAND - 1; i++) {
        if (client->trantorian->command[i].timer == 0
        && client->trantorian->command[i].command == NONE) {
            copy_command(client, i, i + 1);
        }
    }
}
