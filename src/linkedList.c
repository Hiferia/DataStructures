#include "linkedList.h"
#include "stringItem.h"
#include <stdio.h>
#include <stddef.h>

list_node_t *list_get_tail(list_node_t **head)
{
    list_node_t *current_node = *head;
    list_node_t *last_node = NULL;

    while (current_node)
    {
        last_node = current_node;
        current_node = current_node->next;
    }
    
    return last_node;
}


list_node_t *list_append(list_node_t **head, list_node_t *item)
{
    list_node_t *tail = list_get_tail(head);
    if(!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }

    item->next = NULL;
    return item;
}

list_node_t *list_pop(list_node_t **head)
{
    list_node_t *current_head = *head;
    if(!current_head)
    {
        return NULL;
    }
    
    *head = (*head)->next;
    current_head->next = NULL;

    return current_head;
}

list_node_t *remove_node(list_node_t **head, list_node_t *item)
{
    list_node_t *current_node = *head;
    if(current_node == item)
    {
        list_pop(head);
        return 0;
    }

    list_node_t *previous_node = NULL;

    if(!current_node) return NULL;

    while(current_node->next != item)           //the cycle continue till it reaches the node that has "item" into his ->next
    {
        previous_node = current_node;           //we set the previous node as the current node
        current_node = current_node->next;      //we set the current node as the next node so we move 1 node ahead
    }

    //we're out of the cycle, that means we reach the node that has "item" into his ->next
    current_node->next = item->next;            //we change the ->next of the current node into the ->next of the item
                                                //now we have item attached to anything       
    free(item);                                 //we can free the memory it occupied
    return current_node;
}

void reverse(list_node_t **head)
{
    list_node_t *current_node = *head;
    list_node_t *next_node = NULL;
    list_node_t *prev_node = NULL;

    while(current_node != NULL)
    {
        next_node = current_node->next;         //set the next_node using current->next
        current_node->next = prev_node;         //change the next of the current_node, in the first cicle we'll have NULL cause it will be the last item on the list
        prev_node = current_node;               //set the prev_node as the current_node, at the next cicle the current_node will have this prev as next
        current_node = next_node;               //Move 1 position ahead and restart
    }
    *head = prev_node;                          //change the head into the prev node
}