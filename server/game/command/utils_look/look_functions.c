/*
** EPITECH PROJECT, 2023
** Zappy-Mirror [WSL : Ubuntu]
** File description:
** look_functions
*/

#include "server.h"
#include "look.h"

char *add_the_coma(size_t first_size, size_t i, size_t j,
char *res)
{
    if (j != first_size + 2 * i || first_size + 2 * i - 1 == 0) {
        res = realloc(res, sizeof(char) * (strlen(res) + 2));
        strcat(res, ",");
    }
    return (res);
}

vector_t check_edges(int x, int y, game_struct_t *game)
{
    vector_t res = {0, 0};

    if (x >= game->map->width)
        x %= game->map->width;
    if (x < 0) {
        x %= game->map->width;
        x += game->map->width;
    }
    if (y >= game->map->height)
        y %= game->map->height;
    if (y < 0) {
        y %= game->map->height;
        y += game->map->height;
    }
    res.x = (size_t)x;
    res.y = (size_t)y;
    return res;
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
    vector_t vector = {client->trantorian->position.x,
    client->trantorian->position.y}; size_t look_player_pos = 1;
    char *res = calloc(1, sizeof(char));
    size_t res_length = 0;
    char *tile = NULL;

    for (size_t i = 0; i <= (size_t)client->trantorian->level; i++) {
        for (size_t j = 0; j < look_player_pos + (2 * i); j++) {
            vector_t tmp_vector = check_edges((int)(vector.x + (int)j),
            (int)(vector.y - (int)i), zappy->game_struct);
            tile = strdup(look_at_tile(tmp_vector.x, tmp_vector.y, zappy));
            res = realloc(res, (res_length + strlen(tile) + 2) * sizeof(char));
            strcat(res, tile);
            res_length += strlen(tile);
            res = strdup(add_the_coma(look_player_pos, i, j, strdup(res)));
            free(tile);
        }
        vector.x--;
    }
    return (add_hook(rm_spaces_before_coma(res)));
}

char *look_down(client_t *client, zappy_t *zappy)
{
    vector_t vector = {client->trantorian->position.x,
    client->trantorian->position.y}; size_t look_player_pos = 1;
    char *res = calloc(1, sizeof(char));
    size_t res_length = 0;
    char *tile = NULL;

    for (size_t i = 0; i <= (size_t)client->trantorian->level; i++) {
        for (size_t j = 0; j < look_player_pos + (2 * i); j++) {
            vector_t tmp_vector = check_edges((int)(vector.x - (int)j),
            (int)(vector.y + (int)i), zappy->game_struct);
            tile = strdup(look_at_tile(tmp_vector.x, tmp_vector.y, zappy));
            res = realloc(res, (res_length + strlen(tile) + 2) * sizeof(char));
            strcat(res, tile);
            res_length += strlen(tile);
            res = strdup(add_the_coma(look_player_pos, i, j, strdup(res)));
            free(tile);
        }
        vector.x++;
    }
    return (add_hook(rm_spaces_before_coma(res)));
}
