/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** initialize_trantorian
*/

#include "trantorian.h"

//TODO when this function will be called increment the nb of trantorian
//in game struct
trantorian_t *create_trantorian(egg_t* egg)
{
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));

    trantorian->level = 1;
    trantorian->inventory = calloc(1, sizeof(object_t));
    trantorian->life = 10;
    trantorian->position.x = egg->pos.x;
    trantorian->position.y = egg->pos.y;
    trantorian->id = egg->id;
    trantorian->direction = rand() % 4;
    return (trantorian);
}

struct trantorian_head create_trantorian_chained_list(void)
{
    struct trantorian_head head;
    LIST_INIT(&head);
    return (head);
}
