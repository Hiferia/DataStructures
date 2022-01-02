#pragma once
#include <stddef.h>

#define LIST_NODE_PTRPTR list_node_t**
#define LIST_NODE_PTR list_node_t*

typedef struct  list_node
{
    struct list_node *next;
}list_node_t;

list_node_t *list_get_tail(list_node_t **head);
list_node_t *list_append(list_node_t **head, list_node_t *item);
list_node_t *list_pop(list_node_t **head);
list_node_t *remove_node(list_node_t **head, list_node_t *item);
void reverse(list_node_t **head);