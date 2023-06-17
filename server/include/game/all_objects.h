/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** all_objects
*/

#pragma once

#define NUMBER_OF_DIFFERENT_ELEMENTS 7
#include <stdio.h>

/**
 * @brief Create a enum for all objects
 */
enum ELEMENTS {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
};

enum ELEMENTS_DENSITY {
    FOOD_DENSITY = 500,
    LINEMATE_DENSITY = 300,
    DERAUMERE_DENSITY = 150,
    SIBUR_DENSITY = 100,
    MENDIANE_DENSITY = 100,
    PHIRAS_DENSITY = 80,
    THYSTAME_DENSITY = 50
};

/**
 * @brief Create a struct for all objects
 */
typedef struct object_s {
    size_t nb_of_objects[NUMBER_OF_DIFFERENT_ELEMENTS];
} object_t;
