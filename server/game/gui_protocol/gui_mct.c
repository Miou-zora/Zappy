/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_mct
*/

#include "server.h"
#include "gui_protocol.h"
#include "map.h"

char *convert_tile_to_str(object_t *tile, int x, int y)
{
    char buffer[1024] = {0};

    sprintf(buffer, "bct %d %d %ld %ld %ld %ld %ld %ld %ld\n", x, y,
    tile->nb_of_objects[FOOD], tile->nb_of_objects[LINEMATE],
    tile->nb_of_objects[DERAUMERE], tile->nb_of_objects[SIBUR],
    tile->nb_of_objects[MENDIANE], tile->nb_of_objects[PHIRAS],
    tile->nb_of_objects[THYSTAME]);
    return (strdup(buffer));
}

int create_line_response(int y, zappy_t *zappy, client_t *client)
{
    char *buffer = NULL;
    response_t *response = NULL;
    map_t *map = zappy->game_struct->map;

    for (int x = 0; x < map->width; x++) {
        buffer = convert_tile_to_str(&map->tile[y][x], x, y);
        if (buffer == NULL) {
            printf("Error: malloc failed for strdup\n");
            return (84);
        }
        response = create_response(buffer);
        if (response == NULL) {
            printf("Error: malloc failed for create_response\n");
            return (84);
        }
        add_client_to_response(response, client);
        LIST_INSERT_HEAD(&zappy->responses, response, next);
        free(buffer);
    }
    return (0);
}

void handle_gui_mct(event_t *event, zappy_t *zappy)
{
    map_t *map = zappy->game_struct->map;

    if (!event->client->is_graphic || !event->client->is_logged
    || !event->client->is_connected)
        return;
    for (int y = 0; y < map->height; y++) {
        if (create_line_response(y, zappy, event->client) == 84)
            return;
    }
}
