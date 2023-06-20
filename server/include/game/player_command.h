/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** player_command
*/

#pragma once

typedef struct client_s client_t;
typedef struct zappy_s zappy_t;

/**
 * @brief Enum for the command
 *
 */
enum COMMAND {
    NONE = 0,
    FORWARD,
    TURN_RIGHT,
    TURN_LEFT,
    LOOK,
    INVENTORY,
    BROADCAST,
    CONNECT_NBR,
    FORK,
    EJECT,
    TAKE,
    SET,
    INCANTATION
};

/**
 * @brief Structure for the command
 *
 * @param timer The timer of the command
 * @param command The command
 * @param func The function to call when the timer is over
 * @param arg The argument of the command
 */
typedef struct command_s {
    int timer;
    char *arg;
    void (*func)(client_t *client, zappy_t *zappy, char *arg);
} command_t;

/**
 * @brief Try to add a command to the client
 *
 * @param client
 * @param command
 * @param timer
 * @param func
 * @return ** int ** 1 if the command is added, 0 if the command is not added
 */
int add_command(client_t *client, int timer,
    void (*func)(client_t *client, zappy_t *zappy, char *arg), char *arg);

/**
 * @brief It will check ir the first command is finished, move the commands
 * to the left
 *
 * @param client
 * @param zappy
 * @return ** void
 */
void re_organize_list_command(zappy_t *zappy);

/**
 * @brief Remove a command from the client
 *
 * @param client client
 * @param i idx
 */
void remove_command(client_t *client, int i);

/**
 * @brief Copy a command from the client
 *
 * @param client client
 * @param dest idx
 * @param src idx
 */
void copy_command(client_t *client, int dest, int src);
