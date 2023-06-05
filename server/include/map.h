/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include "all_objects.h"
    #include <sys/queue.h>

    /**
     * @brief egg structure
     * @param width width of the map
     * @param height height of the map
     * @param objects array of objects for each case of the map
     */

    typedef struct map_s {
        int width;
        int height;
        object_t **tile;
    } map_t;

#endif /* !MAP_H_ */
