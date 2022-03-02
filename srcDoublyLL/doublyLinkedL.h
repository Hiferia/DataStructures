#pragma once

#define LIST_NODE_PTRPTR list_node_t**
#define LIST_NODE_PTR list_node_t*

typedef struct  list_node
{
    struct list_node *prev;
    struct list_node *next;
}list_node_t;

/*
 * This function will return the last node of the list
 * @param head ptr of ptr of the list
 */
list_node_t *ls_list_get_tail(LIST_NODE_PTRPTR head);

/*
 * This function will insert an item into the list after the last node
 * @param head ptr of ptr of the list
 * @param item the item to insert
 */
list_node_t *ls_list_append(LIST_NODE_PTRPTR head, LIST_NODE_PTR item);

/*
 * This function will remove an item into the list
 * @param head ptr of ptr of the list
 * @param item the item to remove
 */
list_node_t *ls_remove_node(LIST_NODE_PTRPTR head, LIST_NODE_PTR item);

/*
 * This function will reverse the list
 * @param head ptr of ptr of the list
 */
void ls_reverse_list(LIST_NODE_PTRPTR head);

/*
 * This function will insert an item after a specific item
 * @param head ptr of ptr of the list
 * @param item_to_insert the item to insert
 * @param item_to_use the item after which we want to insert the item
 */
void ls_insert_after(LIST_NODE_PTRPTR head, LIST_NODE_PTR item_to_insert, LIST_NODE_PTR item_to_use);

/*
 * This function will insert an item before a specific item
 * @param head ptr of ptr of the list
 * @param item_to_insert the item to insert
 * @param item_to_use the item before which we want to insert the item
 */
void ls_insert_before(LIST_NODE_PTRPTR head, LIST_NODE_PTR item_to_insert, LIST_NODE_PTR item_to_use);

/*
 * This function will return the lenght of the list
 * @param head ptr of ptr of the list
 */
int ls_get_list_lenght(LIST_NODE_PTRPTR head);

/*
 * This function will return an item from a specific index
 * @param head ptr of ptr of the list
 * @param index index from which we want to take the item
 */
list_node_t *ls_get_node_from_list(LIST_NODE_PTRPTR head, int index);

/*
 * This function will swap two nodes
 * @param head ptr of ptr of the list
 * @param node_01 the first node to swap
 * @param node_01 the second node to swap
 */
void ls_swap_nodes(LIST_NODE_PTRPTR head, LIST_NODE_PTR node_01, LIST_NODE_PTR node_02);

/*
 * This function will randomly shuffle the list
 * @param head ptr of ptr of the list
 */
void ls_shuffle_list(LIST_NODE_PTRPTR head);

/*
 * This function will shuffle the list n times swapping distant nodes
 * es: node_00 with node_02, node_01 with node_03 ecc
 * @param head ptr of ptr of the list
 * @param shuffle_times number of times we want to shuffle
 */
void ls_shuffle_list_not_random_distant_nodes(LIST_NODE_PTRPTR head, int shuffle_times);

/*
 * This function will shuffle the list n times swapping nearby nodes
 * es: node_00 with node_01, node_01 with node_02 ecc
 * @param head ptr of ptr of the list
 * @param shuffle_times number of times we want to shuffle
 */
void ls_shuffle_list_not_random_nearby_nodes(LIST_NODE_PTRPTR head, int shuffle_times);









