/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** egg
*/

#pragma once
#include "vector.h"
#include "sys/queue.h"

/**
 * @brief egg structure
 * @param pos_x x position of the egg
 * @param pos_y y position of the egg
 * @param team_name team name of the egg
 */

typedef struct egg_s {
    vector_t pos;
    char *team_name;
    int id;
    LIST_ENTRY(egg_s) next_egg;
} egg_t;

LIST_HEAD(egg_head, egg_s);

/**
 * @brief Add values to the egg
 *
 * @param pos_x x position of the egg
 * @param pos_y y position of the egg
 * @param team_name name of the team
 * @return void
 */
egg_t *create_egg(int pos_x, int pos_y, char *team_name, int id);

/**
 * @brief Create a egg chained list with head object
 *
 * @return egg_t*
 */
struct egg_head create_egg_chained_list(void);
