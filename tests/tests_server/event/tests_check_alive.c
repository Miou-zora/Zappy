/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_check_alive
*/

#include <criterion/criterion.h>
#include "server.h"
#include "check_functions.h"

typedef struct argv_s argv_t;

Test(update_trantorian_life, check_if_trantorian_is_alive)
{
    trantorian_t *trantorian = calloc(1, sizeof(trantorian_t));

    trantorian->inventory = calloc(1, sizeof(object_t));
    trantorian->inventory->nb_of_objects[FOOD] = 1;
    update_trantorian_life(trantorian);
    cr_assert_eq(trantorian->is_dead, false);
    trantorian->inventory->nb_of_objects[FOOD] = 0;
    update_trantorian_life(trantorian);
    cr_assert_eq(trantorian->is_dead, true);
}

Test(update_all_trantorians_life, check_all_trantorians_are_alive)
{
    game_struct_t *game_struct = calloc(1, sizeof(game_struct_t));
    argv_t *argv = calloc(1, sizeof(argv_t));
    argv->clientsNb = 2;
    argv->freq = 100;
    argv->height = 10;
    argv->width = 10;
    game_struct = init_game_struct(argv);
    clan_t *clan = create_clan(2, "test");
    egg_t * egg = create_egg(0,0, "re", 0);
    trantorian_t *trant1 = create_trantorian(egg);
    trant1->inventory->nb_of_objects[FOOD] = 0;
    trantorian_t *trant2 = create_trantorian(egg);
    trant2->inventory->nb_of_objects[FOOD] = 1;

    clan_member_t *member = NULL;
    clan_member_t *member1 = create_clan_member(trant1);
    clan_member_t *member2 = create_clan_member(trant2);

    LIST_INSERT_HEAD(&(game_struct->all_clans), clan, next_clan);

    LIST_FOREACH(clan, &game_struct->all_clans, next_clan) {
        LIST_INSERT_HEAD(&clan->all_members, member1, next_clan_member);
        LIST_INSERT_HEAD(&clan->all_members, member2, next_clan_member);
    }
    update_all_trantorians_life(&game_struct->all_clans);
    LIST_FOREACH(clan, &game_struct->all_clans, next_clan) {
        LIST_FOREACH(member, &clan->all_members, next_clan_member) {
        }
    }
    cr_assert_eq(LIST_FIRST(&game_struct->all_clans.lh_first->all_members), member2);
}