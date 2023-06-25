/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** utils_position
*/

#include "server.h"
#include "trantorian.h"
#include "game.h"

void refactor_vector_non_euclidian(vector_t *diff,
    vector_t *compensation, map_t *map)
{
    if (diff->x == 0 && diff->y > (map->height / 2)) {
        diff->y = map->height - diff->y;
        compensation->y *= -1;
        return;
    } else if (diff->y == 0 && diff->x > (map->width / 2)) {
        diff->x = map->width - diff->x;
        compensation->x *= -1;
        return;
    }
    if (diff->x > (map->width / 2)) {
        diff->x = map->width - diff->x;
        compensation->x *= -1;
    } else if (diff->y > (map->height / 2)) {
        diff->y = map->height - diff->y;
        compensation->y *= -1;
    }
}

void compute_shortest_path(zappy_t *zappy, char *msg,
    trantorian_t *src, trantorian_t *dest)
{
    vector_t cp_src = src->position;
    vector_t diff = compute_difference(&cp_src, &dest->position);
    vector_t compensation = comptute_compensation(&cp_src, &dest->position);
    map_t *map = zappy->game_struct->map;
    int cmp = diff.x - diff.y;
    int error = 0;
    refactor_vector_non_euclidian(&diff, &compensation, map);
    while (is_not_near(dest, &cp_src)) {
        error = 2 * cmp;
        if (error > -diff.y) {
            cmp -= diff.y;
            cp_src.x = safe_x(cp_src.x + compensation.x, map->width);
        }
        if (error < diff.x) {
            cmp += diff.x;
            cp_src.y = safe_y(cp_src.y + compensation.y, map->height);
        }
    }
    send_broadcast_response(zappy, dest, &cp_src, msg);
}

void compute_message_movement(zappy_t *zappy, trantorian_t *src, char *msg)
{
    client_t *client = NULL;
    trantorian_t *target = NULL;

    LIST_FOREACH(client, &zappy->clients, next) {
        if (client->trantorian != NULL && client->trantorian != src) {
            target = client->trantorian;
            compute_shortest_path(zappy, msg, src, target);
        }
    }
    send_response_emetter(zappy, msg, src);
    notifie_gui_pbc(msg, src, zappy);
}
