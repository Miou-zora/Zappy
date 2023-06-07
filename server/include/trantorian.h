/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** trantorian
*/

#pragma once
#include "all_objects.h"
#include "server.h"
#include "egg.h"
#include "vector.h"

/**
 * @brief Declarate a enum for direction
*/
enum DIRECTION {
    RIGHT,
    UP,
    LEFT,
    DOWN
};

/**
 * @brief Declarate a struct for trantorian
 */
typedef struct trantorian_s {
    int life;
    int level;
    vector_t position;
    enum DIRECTION direction;
    bool is_incanting;
    bool is_dead;
    bool is_egging;
    object_t *inventory;
} trantorian_t;

trantorian_t *initialize_trantorian(egg_t *egg);
trantorian_t *initialize_empty_trantorian(void);
