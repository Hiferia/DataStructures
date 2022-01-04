#pragma once

#define LIST_NODE_PTRPTR list_node_t**
#define LIST_NODE_PTR list_node_t*

typedef struct  list_node
{
    struct list_node *prev;
    struct list_node *next;
}list_node_t;

list_node_t *list_get_tail(list_node_t **head);
list_node_t *list_append(list_node_t **head, list_node_t *item);
list_node_t *list_pop(list_node_t **head);
list_node_t *remove_node(list_node_t **head, list_node_t *item);
void reverse(list_node_t **head);
void insert_after(LIST_NODE_PTRPTR head, LIST_NODE_PTR itemToInsert, LIST_NODE_PTR itemToUse);
void insert_before(LIST_NODE_PTRPTR head, LIST_NODE_PTR itemToInsert, LIST_NODE_PTR itemToUse);
int get_List_Lenght(LIST_NODE_PTRPTR head);
list_node_t *get_Node_From_List(LIST_NODE_PTRPTR head, int index);
void swap_Nodes(LIST_NODE_PTRPTR head, LIST_NODE_PTR node_01, LIST_NODE_PTR node_02);
void shuffle_List(LIST_NODE_PTRPTR head);








