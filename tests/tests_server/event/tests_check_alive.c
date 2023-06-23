/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_check_alive
*/

#include <criterion/criterion.h>
#include "server.h"
#include "game.h"

typedef struct argv_s argv_t;

Test(update_all_trantorians_life, check_all_trantorians_are_alive)
{
    game_struct_t *game_struct = calloc(1, sizeof(game_struct_t));
    argv_t *argv = calloc(1, sizeof(argv_t));
    argv->clientsNb = 2;
    argv->freq = 100;
    argv->height = 10;
    argv->width = 10;
    argv->names = calloc(2, sizeof(char *));
    argv->names[0] = "test";
    argv->names[1] = "test2";
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

    add_clan_to_list(game_struct, clan);
    LIST_FOREACH(clan, &game_struct->all_clans, next_clan) {
        add_clan_member_to_list(clan, member1);
        add_clan_member_to_list(clan, member2);
    }

    LIST_FOREACH(clan, &game_struct->all_clans, next_clan) {
        LIST_FOREACH(member, &clan->all_members, next_clan_member) {
        }
    }
    cr_assert_eq(LIST_FIRST(&game_struct->all_clans.lh_first->all_members), member1);
}