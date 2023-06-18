/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** trantorian
*/

#pragma once
#include "all_objects.h"
#include "egg.h"
#include "vector.h"
#include "client.h"
#include "player_command.h"
#define MAX_COMMAND 10

typedef struct game_struct_s game_struct_t;
typedef struct zappy_s zappy_t;

/**
 * @brief Declarate a enum for direction
*/
enum DIRECTION {
    UP = 1,
    RIGHT,
    DOWN,
    LEFT
};

/**
 * @brief Declarate a struct for trantorian
 */
typedef struct trantorian_s {
    int level;
    int id;
    char *team_name;
    vector_t position;
    enum DIRECTION direction;
    bool is_incanting;
    bool is_dead;
    bool is_egging;
    object_t *inventory;
    client_t *client;
    command_t command[MAX_COMMAND];
    LIST_ENTRY(trantorian_s) next_trantorian;
} trantorian_t;

/**
 * @brief Initialize the trantorian
 * @param egg_t
*/
trantorian_t *create_trantorian(egg_t *egg);

/**
 * @brief Create trantorian from event
 * @param char team_name
 * @param zappy_t server
*/
trantorian_t *create_trantorian_from_event(char *team_name, zappy_t *server);


LIST_HEAD(trantorian_head, trantorian_s);
/**
 * @brief Create a trantorian chained list with head object
*/
struct trantorian_head create_trantorian_chained_list(void);
