/*
** EPITECH PROJECT, 2023
** Zappy-Mirror [WSL : Ubuntu]
** File description:
** count_stones
*/

#include "server.h"

static char *copy_at_tile_in_buffer(char *res, char *tmp,
    size_t count_nb_type_of_elem, char *element)
{
    for (size_t j = 0; j < count_nb_type_of_elem; j++) {
        tmp = calloc(1, sizeof(char) * (strlen(element) + 1));
        if (j - 1 == count_nb_type_of_elem - 1)
            sprintf(tmp, "%s", element);
        else
            sprintf(tmp, "%s ", element);
        res = realloc(res, sizeof(char) * (strlen(res) + strlen(tmp)));
        strcat(res, tmp);
        free(tmp);
    }
    return res;
}

char *all_elements_at_tile(size_t x, size_t y, zappy_t *zappy)
{
    size_t width = zappy->game_struct->map->width;
    char *array[7] = {"food", "linemate", "deraumere", "sibur", "mendiane",
        "phiras", "thystame"};
    char *tmp = calloc(1, sizeof(char) * 1);
    char *res = calloc(1, sizeof(char) * 1);
    size_t count_nb_type_of_elem = 0;

    for (size_t i = 0; i < NUMBER_OF_DIFFERENT_ELEMENTS; i++) {
        count_nb_type_of_elem = 0;
        if (zappy->game_struct->map->tile[x + y * width]->nb_of_objects[i]
            != 0) {
            count_nb_type_of_elem
            = zappy->game_struct->map->tile[x + y * width]->nb_of_objects[i];
            res =
            copy_at_tile_in_buffer(res, tmp, count_nb_type_of_elem, array[i]);
        }
    }
    return (res);
}
