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
    char *res = calloc(1, sizeof(char) * (strlen(str) + 3));

    res[0] = '[';
    strcat(res, str);
    res[strlen(res)] = ']';
    return res;
}

char *look_up(client_t *client, zappy_t *zappy)
{
    vector_t ppos = {client->trantorian->position.x,
    client->trantorian->position.y};
    char *res = calloc(1, sizeof(char));
    char *tile = NULL;

    for (size_t i = 0; i <= (size_t)client->trantorian->level; i++) {
        for (size_t j = 0; j < 1 + (2 * i); j++) {
            vector_t tmp_vector = check_edges((int)(ppos.x + (int)j),
            (int)(ppos.y - (int)i), zappy->game_struct->map);
            tile = look_at_tile(tmp_vector.x, tmp_vector.y, zappy);
            res = realloc(res, (strlen(res) + strlen(tile) + 2) * sizeof(char));
            strcat(res, tile);
            add_comma_to_buffer(res);
        }
        ppos.x--;
    }
    return (add_hook(rm_spaces_before_coma(res)));
}

char *look_down(client_t *client, zappy_t *zappy)
{
    vector_t ppos = {client->trantorian->position.x,
    client->trantorian->position.y};
    char *res = calloc(1, sizeof(char));
    char *tile = NULL;

    for (size_t i = 0; i <= (size_t)client->trantorian->level; i++) {
        for (size_t j = 0; j < 1 + (2 * i); j++) {
            vector_t tmp_vector = check_edges((int)(ppos.x - (int)j),
            (int)(ppos.y + (int)i), zappy->game_struct->map);
            tile = look_at_tile(tmp_vector.x, tmp_vector.y, zappy);
            res = realloc(res, (strlen(res) + strlen(tile) + 2) * sizeof(char));
            strcat(res, tile);
            add_comma_to_buffer(res);
        }
        ppos.x++;
    }
    return (add_hook(rm_spaces_before_coma(res)));
}
