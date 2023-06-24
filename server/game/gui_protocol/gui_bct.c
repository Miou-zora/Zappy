/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_bct
*/

#include "server.h"
#include "gui_protocol.h"

void send_gui_bct(int x, int y, zappy_t *zappy)
{
    map_t *map = zappy->game_struct->map;
    char buffer[1024] = {0};
    response_t *response = NULL;

    if (sprintf(buffer, "bct %d %d %ld %ld %ld %ld %ld %ld %ld\n", x, y,
        map->tile[y][x].nb_of_objects[0], map->tile[y][x].nb_of_objects[1],
        map->tile[y][x].nb_of_objects[2], map->tile[y][x].nb_of_objects[3],
        map->tile[y][x].nb_of_objects[4], map->tile[y][x].nb_of_objects[5],
        map->tile[y][x].nb_of_objects[6]) < 0)
        return;
    response = create_response(buffer);
    if (response == NULL)
        return;
    send_response_to_all_gui_clients(response, zappy);
}

void create_response_to_event(int x, int y, zappy_t *zappy)
{
    map_t *map = zappy->game_struct->map;
    char buffer[1024] = {0};
    response_t *response;

    if (sprintf(buffer, "bct %d %d %ld %ld %ld %ld %ld %ld %ld\n", x, y,
        map->tile[y][x].nb_of_objects[0], map->tile[y][x].nb_of_objects[1],
        map->tile[y][x].nb_of_objects[2], map->tile[y][x].nb_of_objects[3],
        map->tile[y][x].nb_of_objects[4], map->tile[y][x].nb_of_objects[5],
        map->tile[y][x].nb_of_objects[6]) < 0)
        return;
    response = create_response(buffer);
    if (response == NULL)
        return;
    send_response_to_all_gui_clients(response, zappy);
}

void handle_gui_bct(event_t *event, zappy_t *zappy)
{
    argv_t *map_setting = zappy->args;
    int x = 0;
    int y = 0;

    if (strlen(event->request) < 8)
        return;
    if (sscanf(event->request, "bct %d %d", &x, &y) != 2)
        return;
    if (x < 0 || x >= map_setting->width || y < 0 || y >= map_setting->height)
        return;
    create_response_to_event(x, y, zappy);
}
