/*
** EPITECH PROJECT, 2023
** Zappy-Mirror
** File description:
** tests_clan_structure
*/

#include <criterion/criterion.h>
#include "clan.h"

Test(create_clan_structure, test_create_clan_structure)
{
    clan_t *clan = create_clan("equipe");

    cr_assert_eq(strcmp(clan->name, "equipe"),0);
    cr_assert_eq(LIST_EMPTY(&clan->all_members), 1);
}

Test(create_clan_structure, test_create_clan_chained_list)
{
    struct clan_head head = create_clan_chained_list();

    cr_assert_eq(LIST_EMPTY(&head), 1);
}

Test(create_clan_structure, test_add_clan_to_chained_list)
{
    struct clan_head head = create_clan_chained_list();
    clan_t *clan = create_clan("equipe");

    LIST_INSERT_HEAD(&head, clan, next_clan);
    cr_assert_eq(LIST_EMPTY(&head), 0);
    cr_assert_eq(LIST_FIRST(&head), clan);
    cr_assert_eq(strcmp(clan->name, "equipe"), 0);
}

Test(create_clan_structure, test_remove_clan_from_chained_list)
{
    struct clan_head head = create_clan_chained_list();
    clan_t *clan = create_clan("equipe");

    LIST_INSERT_HEAD(&head, clan, next_clan);
    LIST_REMOVE(clan, next_clan);
    cr_assert_eq(LIST_EMPTY(&head), 1);
}

Test(create_clan_structure, test_create_clan_member_structure)
{
    trantorian_t *trantorian = create_trantorian(create_egg(0,0,"equipe"));
    clan_member_t *clan_member = create_clan_member(trantorian);

    cr_assert_eq(clan_member->trantorian, trantorian);
}

Test(create_clan_structure, test_create_clan_member_chained_list)
{
    struct clan_member_head head = create_clan_members_chained_list();

    cr_assert_eq(LIST_EMPTY(&head), 1);
}

Test(create_clan_structure, test_add_clan_member_to_clan)
{
    clan_t *clan = create_clan("equipe");
    clan_member_t *clan_member = create_clan_member(create_trantorian(
        create_egg(0,0,"equipe")));

    LIST_INSERT_HEAD(&clan->all_members, clan_member, next_clan_member);
    cr_assert_eq(LIST_EMPTY(&clan->all_members), 0);
    cr_assert_eq(LIST_FIRST(&clan->all_members), clan_member);
}

Test(create_clan_structure, test_remove_clan_member_from_clan)
{
    clan_t *clan = create_clan("equipe");
    clan_member_t *clan_member = create_clan_member(create_trantorian(
        create_egg(0,0,"equipe")));

    LIST_INSERT_HEAD(&clan->all_members, clan_member, next_clan_member);
    LIST_REMOVE(clan_member, next_clan_member);
    cr_assert_eq(LIST_EMPTY(&clan->all_members), 1);
}
