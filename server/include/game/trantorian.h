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
    vector_t position;
    enum DIRECTION direction;
    bool is_incanting;
    bool is_dead;
    bool is_egging;
    object_t *inventory;
    LIST_ENTRY(trantorian_s) next_trantorian;
} trantorian_t;

/**
 * @brief Initialize the trantorian
 * @param egg_t
*/
trantorian_t *create_trantorian(egg_t *egg);

LIST_HEAD(trantorian_head, trantorian_s);
/**
 * @brief Create a trantorian chained list with head object
*/
struct trantorian_head create_trantorian_chained_list(void);
