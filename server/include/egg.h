/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** egg
*/

#ifndef EGG_H_
    #define EGG_H_

    /**
     * @brief egg structure
     * @param pos_x x position of the egg
     * @param pos_y y position of the egg
     * @param team_name team name of the egg
     */

    typedef struct egg_s {
        int pos_x;
        int pos_y;
        char *team_name;
    } egg_t;

#endif /* !EGG_H_ */
