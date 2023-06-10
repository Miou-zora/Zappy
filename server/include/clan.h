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
    LIST_ENTRY(clan_member_s) next_clan_member;
} clan_member_t;

/**
 * @brief Declarate clan structure
 */
typedef struct clan_s {
    char *name;
    LIST_HEAD(clan_member_head, clan_member_s) all_members;
    LIST_ENTRY(clan_s) next_clan;
} clan_t;


LIST_HEAD(clan_head, clan_s);

/**
 * @brief Create a clan member object
 * @param trantorian
 * @return clan_member_t*
 */
clan_member_t *create_clan_member(trantorian_t *trantorian);

/**
 * @brief Create a clan chained list with head object
 * @return clan_t*
 */
struct clan_member_head create_clan_members_chained_list(void);

/**
 * @brief Initialize the clan
 * @param team_name
 * @return clan_t*
 */
clan_t *create_clan(char *name);

/**
 * @brief Create a clan chained list object
 *
 * @return struct clan_head
 */
struct clan_head create_clan_chained_list(void);

/**
 * @brief Create a clan chained list object
 *
 * @return struct clan_head
 */
struct clan_head create_clan_chained_list(void);


