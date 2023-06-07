/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** egg
*/

#ifndef EGG_H_
    #define EGG_H_

    #include "vector.h"

    /**
     * @brief egg structure
     * @param pos_x x position of the egg
     * @param pos_y y position of the egg
     * @param team_name team name of the egg
     */

    typedef struct egg_s {
        vector_t pos;
        char *team_name;
    } egg_t;

    /**
     * @brief Add values to the egg
     *
     * @param egg egg structure
     * @param pos_x x position of the egg
     * @param pos_y y position of the egg
     * @param team_name name of the team
     * @return void
     */
    void add_egg(egg_t *egg, int pos_x, int pos_y, char *team_name);

#endif /* !EGG_H_ */
