/*
** EPITECH PROJECT, 2023
** Zappy-Mirror [WSL : Ubuntu]
** File description:
** look_functions
*/

#include "server.h"
#include "game.h"

char *add_the_coma(size_t first_size, size_t i, size_t j,
    char *res)
{
    if (j != first_size + 2 * i || first_size + 2 * i - 1 == 0) {
        res = realloc(res, sizeof(char) * (strlen(res) + 2));
        strcat(res, ",");
    }
    return (res);
}

vector_t check_edges(int x, int y, map_t *map)
{
    vector_t res = {0, 0};
    res.x = x % map->width;
    res.y = y % map->height;
    if (res.x < 0)
        res.x += map->width;
    if (res.y < 0)
        res.y += map->height;
    return (res);
}

char *add_hook(char *str)
{
    char *res = NULL;
    if (str == NULL)
        return (NULL);
    str[strlen(str) - 1] = '\0';
    str[strlen(str) - 1] = '\0';

    if (asprintf(&res, "[%s]\n", str) == -1) {
        return (NULL);
    }
    return (res);
}
