/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** trantorian
*/

#pragma once
#include "all_objects.h"

/**
 * @brief Declarate a struct for trantorian
 */
typedef struct trantorian_t
{
    int life;
    int level;
    int position[2];
    int nb_of_clans_members;
    object_t inventory;
};
