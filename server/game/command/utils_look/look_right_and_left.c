/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** look_right_and_left
*/

#include "server.h"
#include "look.h"

char *look_right(client_t *client, zappy_t *zappy)
{
    vector_t vector = {client->trantorian->position.x,
    client->trantorian->position.y};
    size_t look_player_pos = 1; size_t res_length = 0;
    char *res = calloc(1, sizeof(char));
    char *tile = NULL;

    for (size_t i = 0; i <= (size_t)client->trantorian->level; i++) {
        for (size_t j = 0; j < look_player_pos + (2 * i); j++) {
            vector_t tmp_vector = check_edges((int)(vector.x + (int)i),
            (int)(vector.y + (int)j), zappy->game_struct);
            tile = strdup(look_at_tile(tmp_vector.x, tmp_vector.y, zappy));
            res = realloc(res, (res_length + strlen(tile) + 2) * sizeof(char));
            strcat(res, tile);
            res_length += strlen(tile);
            res = strdup(add_the_coma(look_player_pos, i, j, strdup(res)));
            free(tile);
        }
        vector.y--;
    }
    return (add_hook(rm_spaces_before_coma(res)));
}

char *look_left(client_t *client, zappy_t *zappy)
{
    vector_t vector = {client->trantorian->position.x,
    client->trantorian->position.y};
    size_t look_player_pos = 1; size_t res_length = 0;
    char *res = calloc(1, sizeof(char));
    char *tile = NULL;

    for (size_t i = 0; i <= (size_t)client->trantorian->level; i++) {
        for (size_t j = 0; j < look_player_pos + (2 * i); j++) {
            vector_t tmp_vector = check_edges((int)(vector.x - (int)i),
            (int)(vector.y - (int)j), zappy->game_struct);
            tile = strdup(look_at_tile(tmp_vector.x, tmp_vector.y, zappy));
            res = realloc(res, (res_length + strlen(tile) + 2) * sizeof(char));
            strcat(res, tile);
            res_length += strlen(tile);
            res = strdup(add_the_coma(look_player_pos, i, j, strdup(res)));
            free(tile);
        }
        vector.y++;
    }
    return (add_hook(rm_spaces_before_coma(res)));
}
