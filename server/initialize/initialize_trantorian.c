/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** initialize_trantorian
*/

#include "trantorian.h"


/**
 * @brief Initialize the trantorian
 * @param egg_t
*/

trantorian_t *initialize_trantorian(egg_t* egg)
{
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));

    trantorian->level = 1;
    trantorian->inventory = calloc(1, sizeof(object_t));
    trantorian->life = 10;
    trantorian->position.x = egg->pos.x;
    trantorian->position.y = egg->pos.y;
    trantorian->direction = rand() % 4;
    return (trantorian);
}

/**
 * @brief Initialize an empty trantorian
 * @return trantorian_t*
*/

trantorian_t *initialize_empty_trantorian(void)
{
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));

    trantorian->level = 1;
    trantorian->inventory = calloc(1, sizeof(object_t));
    trantorian->life = 10;
    trantorian->position.x = 0;
    trantorian->position.y = 0;
    trantorian->direction = rand() % 4;
    return (trantorian);
}
