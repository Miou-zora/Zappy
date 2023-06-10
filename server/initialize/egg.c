/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** egg
*/

#include "server.h"
#include "egg.h"

egg_t *create_egg(int pos_x, int pos_y, char *team_name)
{
    egg_t *egg = calloc(1, sizeof(egg_t));

    if (egg == NULL)
        return (NULL);
    egg->pos.x = pos_x;
    egg->pos.y = pos_y;
    egg->team_name = strdup(team_name);
    return (egg);
}

struct egg_head create_egg_chained_list(void)
{
    struct egg_head head;
    LIST_INIT(&head);
    return (head);
}
