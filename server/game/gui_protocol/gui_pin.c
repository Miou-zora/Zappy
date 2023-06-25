/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** gui_pin
*/

#include "gui_protocol.h"

static int convert_food_number(int food)
{
    if (food / 126 > 0)
        return (food / 126);
    else if (food % 126 > 0)
        return (1);
    return (0);
}

void send_gui_pin(trantorian_t *tran, zappy_t *zappy)
{
    char buffer[1024] = {0};
    response_t *response;
    size_t nb_food = (size_t)convert_food_number(
        tran->inventory->nb_of_objects[FOOD]);

    if (tran == NULL)
        return;
    if (sprintf(buffer, "pin %d %d %d %ld %ld %ld %ld %ld %ld %ld\n",
        tran->id, tran->position.x, tran->position.y,
        nb_food, tran->inventory->nb_of_objects[1],
        tran->inventory->nb_of_objects[2], tran->inventory->nb_of_objects[3],
        tran->inventory->nb_of_objects[4], tran->inventory->nb_of_objects[5],
        tran->inventory->nb_of_objects[6]) < 0)
        return;
    response = create_response(buffer);
    if (response == NULL)
        return;
    send_response_to_all_gui_clients(response, zappy);
}

void handle_gui_pin(event_t *event, zappy_t *zappy)
{
    int id = 0;
    trantorian_t *trantorian = NULL;

    if (!event->client->is_connected || !event->client->is_logged ||
        !event->client->is_graphic)
        return;
    if (sscanf(event->request, "pin %d\n", &id) != 1)
        return;
    trantorian = get_trantorian_by_id(zappy, id);
    send_gui_pin(trantorian, zappy);
}
