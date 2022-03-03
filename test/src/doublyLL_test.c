#include "clove.h"
#include "clove-experimental.h"
#include <stdio.h>
#include "doublyLinkedL.h"
#include "stringItem.h"


string_item_t *my_doubly_linked_list;


CLOVE_SUITE_SETUP()
{
    my_doubly_linked_list = NULL;
}
CLOVE_SUITE_TEARDOWN()
{
    free(my_doubly_linked_list);
}

CLOVE_TEST(insert_1_item_with_success)
{

    string_item_t *item0 = string_item_new("Hello World");
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0);

    string_item_t *item_to_check = (string_item_t *)(ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0));

    CLOVE_IS_TRUE((string_item_t *)item_to_check == item0);
}
CLOVE_TEST(insert_2_items_with_success)
{

    string_item_t *item0 = string_item_new("Hello World");
    string_item_t *item1 = string_item_new("Ciao");
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item1);

    list_node_t *item_to_check_00 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0);
    list_node_t *item_to_check_01 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);

    CLOVE_IS_TRUE((string_item_t *)item_to_check_00 == item0);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_01 == item1);
}

CLOVE_TEST(is_next_the_right_node)
{

    string_item_t *item0 = string_item_new("Hello World");
    string_item_t *item1 = string_item_new("Ciao");
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item1);

    list_node_t *item_to_check_00 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0);
    list_node_t *item_to_check_01 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);

    CLOVE_IS_TRUE(item_to_check_00->next == item_to_check_01);
}
CLOVE_TEST(is_prev_the_right_node)
{

    string_item_t *item0 = string_item_new("Hello World");
    string_item_t *item1 = string_item_new("Ciao");
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item1);

    list_node_t *item_to_check_00 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0);
    list_node_t *item_to_check_01 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);

    CLOVE_IS_TRUE(item_to_check_01->prev == item_to_check_00);
}
CLOVE_TEST(is_prev_null)
{
    string_item_t *item0 = string_item_new("Hello World");
    string_item_t *item1 = string_item_new("Ciao");
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item1);

    list_node_t *item_to_check_00 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0);
    list_node_t *item_to_check_01 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);

    CLOVE_IS_TRUE(item_to_check_00->prev == NULL);
}
CLOVE_TEST(remove_first_item_from_list)
{
    string_item_t *item0 = string_item_new("Hello World");
    string_item_t *item1 = string_item_new("Ciao");
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item1);

    list_node_t *item_to_check_00 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0);
    list_node_t *item_to_check_01 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);

    CLOVE_INT_EQ(2, ls_get_list_lenght((LIST_NODE_PTRPTR)&my_doubly_linked_list));

    ls_remove_node((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0);

    CLOVE_IS_TRUE(item_to_check_01->prev == NULL)
    CLOVE_INT_EQ(1, ls_get_list_lenght((LIST_NODE_PTRPTR)&my_doubly_linked_list));
}
CLOVE_TEST(remove_last_item_from_list)
{
    string_item_t *item0 = string_item_new("Hello World");
    string_item_t *item1 = string_item_new("Ciao");
    string_item_t *item2 = string_item_new("Giulia");
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item1);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item2);

    list_node_t *item_to_check_00 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0);
    list_node_t *item_to_check_01 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);
    list_node_t *item_to_check_02 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 2);

    CLOVE_INT_EQ(3, ls_get_list_lenght((LIST_NODE_PTRPTR)&my_doubly_linked_list));

    ls_remove_node((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item2);

    CLOVE_INT_EQ(2, ls_get_list_lenght((LIST_NODE_PTRPTR)&my_doubly_linked_list));
    CLOVE_IS_TRUE(item_to_check_01->next == NULL)
}
CLOVE_TEST(reverse_list)
{
    string_item_t *item0 = string_item_new("Hello World");
    string_item_t *item1 = string_item_new("Ciao");
    string_item_t *item2 = string_item_new("Giulia");
    string_item_t *item3 = string_item_new("Gigi");

    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item1);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item2);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item3);

    ls_reverse_list((LIST_NODE_PTRPTR)&my_doubly_linked_list);
    
    list_node_t *item_to_check_00 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0);
    list_node_t *item_to_check_01 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);
    list_node_t *item_to_check_02 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 2);
    list_node_t *item_to_check_03 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 3);

    CLOVE_IS_TRUE((string_item_t *)item_to_check_00 == item3);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_01 == item2);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_02 == item1);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_03 == item0);
  
    CLOVE_IS_TRUE((string_item_t *)item_to_check_00->prev == NULL);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_01->prev == item3);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_02->prev == item2);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_03->prev == item1);

    CLOVE_IS_TRUE((string_item_t *)item_to_check_00->next == item2);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_01->next == item1);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_02->next == item0);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_03->next == NULL);
}
CLOVE_TEST(insert_after_an_item)
{
    string_item_t *item0 = string_item_new("Hello World");
    string_item_t *item1 = string_item_new("Ciao");
    string_item_t *item2 = string_item_new("Giulia");
    string_item_t *item3 = string_item_new("Gigi");

    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item1);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item2);

    list_node_t *item_to_check_00 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0);
    list_node_t *item_to_check_01 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);
    list_node_t *item_to_check_02 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 2);

    CLOVE_INT_EQ(3, ls_get_list_lenght((LIST_NODE_PTRPTR)&my_doubly_linked_list));

    ls_insert_after((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item3, (LIST_NODE_PTR)item0);

    list_node_t *item_to_check_03 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);

    CLOVE_INT_EQ(4, ls_get_list_lenght((LIST_NODE_PTRPTR)&my_doubly_linked_list));
    CLOVE_IS_TRUE((string_item_t *)item_to_check_00->next == item3);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_01->prev == item3);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_03->next == item1);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_03->prev == item0);
}
CLOVE_TEST(insert_before_an_item)
{
    string_item_t *item0 = string_item_new("Hello World");
    string_item_t *item1 = string_item_new("Ciao");
    string_item_t *item2 = string_item_new("Giulia");
    string_item_t *item3 = string_item_new("Gigi");

    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item1);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item2);

    list_node_t *item_to_check_00 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0);
    list_node_t *item_to_check_01 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);
    list_node_t *item_to_check_02 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 2);

    CLOVE_INT_EQ(3, ls_get_list_lenght((LIST_NODE_PTRPTR)&my_doubly_linked_list));

    ls_insert_before((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item3, (LIST_NODE_PTR)item2);

    list_node_t *item_to_check_03 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 2);

    CLOVE_INT_EQ(4, ls_get_list_lenght((LIST_NODE_PTRPTR)&my_doubly_linked_list));
    CLOVE_IS_TRUE((string_item_t *)item_to_check_01->next == item3);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_02->prev == item3);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_03->next == item2);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_03->prev == item1);
}
CLOVE_TEST(swap_two_nodes)
{
    string_item_t *item0 = string_item_new("Hello World");
    string_item_t *item1 = string_item_new("Ciao");
       
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item1);

    ls_swap_nodes((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0, (LIST_NODE_PTR)item1);

    list_node_t *item_to_check_00 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0);
    list_node_t *item_to_check_01 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);

    CLOVE_IS_TRUE((string_item_t *)item_to_check_01->prev == item1);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_01->next == NULL);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_00->next == item0);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_00->prev == NULL);
}
CLOVE_TEST(shuffle_list_swapping_nearby_nodes)
{
    string_item_t *item0 = string_item_new("Hello World");
    string_item_t *item1 = string_item_new("Ciao");
    string_item_t *item2 = string_item_new("Giulia");
    string_item_t *item3 = string_item_new("Gigi");

    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item1);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item2);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item3);

    ls_shuffle_list_not_random_nearby_nodes((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);

    list_node_t *item_to_check_00 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0);
    list_node_t *item_to_check_01 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);

    CLOVE_IS_TRUE((string_item_t *)item_to_check_00 == item1);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_01 == item0);

    ls_shuffle_list_not_random_nearby_nodes((LIST_NODE_PTRPTR)&my_doubly_linked_list, 2);

    item_to_check_00 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0);
    item_to_check_01 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);
    list_node_t *item_to_check_02 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 2);

    CLOVE_IS_TRUE((string_item_t *)item_to_check_00 == item0);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_01 == item2);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_02 == item1);
}
CLOVE_TEST(shuffle_list_swapping_distant_nodes)
{
    string_item_t *item0 = string_item_new("Hello World");
    string_item_t *item3 = string_item_new("Gigi");
    string_item_t *item2 = string_item_new("Giulia");
    string_item_t *item1 = string_item_new("Ciao");
    string_item_t *item4 = string_item_new("Blabla");
    string_item_t *item5 = string_item_new("Lulu");

    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item0);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item1);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item2);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item3);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item4);
    ls_list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item5);

    ls_shuffle_list_not_random_distant_nodes((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);

    list_node_t *item_to_check_00 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0);
    list_node_t *item_to_check_01 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 2);

    CLOVE_IS_TRUE((string_item_t *)item_to_check_00 == item2);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_01 == item0);

    ls_shuffle_list_not_random_distant_nodes((LIST_NODE_PTRPTR)&my_doubly_linked_list, 2);

    item_to_check_00 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 0);
    item_to_check_01 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 2);
    list_node_t *item_to_check_02 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 3);
    list_node_t *item_to_check_03 = ls_get_node_from_list((LIST_NODE_PTRPTR)&my_doubly_linked_list, 1);

    CLOVE_IS_TRUE((string_item_t *)item_to_check_00 == item0);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_01 == item2);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_02 == item1);
    CLOVE_IS_TRUE((string_item_t *)item_to_check_03 == item3);
}