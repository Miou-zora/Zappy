/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** all_objects
*/

#pragma once


/**
 * @brief Create a enum for all objects
 */
enum {
    FOOD,
    LINEMATE,
    DERAUMERE,
    SIBUR,
    MENDIANE,
    PHIRAS,
    THYSTAME
};


/**
 * @brief Create a struct for all objects
 */
typedef struct object_s {
    int nb_of_objects[7];
} object_t;

