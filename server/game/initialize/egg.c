/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** egg
*/

#include "server.h"
#include "egg.h"

//TODO when this function will be called increment the nb_eggs in game struct
egg_t *create_egg(int pos_x, int pos_y, char *team_name, int id)
{
    egg_t *egg = calloc(1, sizeof(egg_t));

    if (egg == NULL)
        return (NULL);
    egg->pos.x = pos_x;
    egg->pos.y = pos_y;
    egg->team_name = strdup(team_name);
    egg->id = id;
    return (egg);
}

struct egg_head create_egg_chained_list(void)
{
    struct egg_head head;
    LIST_INIT(&head);
    return (head);
}
