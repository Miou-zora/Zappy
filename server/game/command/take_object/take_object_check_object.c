/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** take_object_check_object
*/

#include "trantorian.h"
#include "game.h"
#include "incantation.h"

int get_object_index(const char* param)
{
    char* objects[] = {"food", "linemate", "deraumere", "sibur",
        "mendiane", "phiras", "thystame"};

    for (size_t i = 0; i < NUMBER_OF_DIFFERENT_ELEMENTS; i++) {
        if (strcmp(param, objects[i]) == 0) {
            return ((int) i);
        }
    }
    return -1;
}
