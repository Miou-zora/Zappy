/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** clan
*/

#pragma once
#include "trantorian.h"

/**
 * @brief Declarate caln_member structure
 */
typedef struct clan_member_s {
    trantorian_t *trantorian;
    bool is_first;
    struct clan_member_s *next;
} clan_member_t;

/**
 * @brief Declarate clan structure
 */
typedef struct clan_s {
    char *name;
    int nb_of_members;
    clan_member_t *clan_member;
} clan_t;

/**
 * @brief Initialize the clan
 * @param team_name
 * @return clan_t*
 */

clan_t *create_clan(char *name);

/**
 * @brief Add a trantorian to the clan
 * @param clan
 * @param trantorian
 * @return clan_t *
 */
clan_t *add_member_to_clan(clan_t *clan, clan_member_t *trantorian);

/**
 * @brief Remove a trantorian from the clan
 * @param clan
 * @param trantorian
 * @return clan_t *
 */
clan_t *remove_member_from_clan(clan_t *clan, clan_member_t *trantorian);
