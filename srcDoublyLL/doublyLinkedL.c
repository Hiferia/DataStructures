#include "doublyLinkedL.h"
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

    item->prev = tail;
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
    if(current_node->next != NULL)              //if the current node is not the last node
    {
        current_node->next->prev = current_node;//we change the prev of the next node into the current node (cause it was item)
    }
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
        next_node = current_node->next;     //set the next_node using current->next
        current_node->next = prev_node;     //change the next of the current_node, in the first cicle we'll have NULL cause it will be the last item on the list
        prev_node = current_node;           //set the prev_node as the current_node, at the next cicle the current_node will have this prev as next
        current_node = next_node;           //Move 1 position ahead and restart
    }
    *head = prev_node;                      //change the head into the prev node
}

void insert_after(LIST_NODE_PTRPTR head, LIST_NODE_PTR itemToInsert, LIST_NODE_PTR itemToUse)
{
    list_node_t *current_node = *head;

    while(current_node != itemToUse)
    {
        current_node = current_node->next;          //cycle till it reaches the item we are looking for
    }

    itemToInsert->next = current_node->next;        //set the ->next of the new item as the ->next of the current
    itemToInsert->prev = current_node->prev;
    if(current_node->next != NULL)
    {
        current_node->next->prev = itemToInsert;    //set the ->prev of the ->next as the new item, if current node is not the last item
    }
    current_node->next = itemToInsert;              //set the ->next of the current as the new item

}
void insert_before(LIST_NODE_PTRPTR head, LIST_NODE_PTR itemToInsert, LIST_NODE_PTR itemToUse)
{
    list_node_t *current_node = *head;

    while(current_node != itemToUse)
    {
        current_node = current_node->next;          //cycle till it reaches the item we are looking for
    }

    itemToInsert->prev = current_node->prev;        //set the ->next of the new item as the ->next of the current
    itemToInsert->next = current_node;
    if(current_node->prev != NULL)
    {
        current_node->prev->next = itemToInsert;    //set the ->prev of the ->next as the new item, if current node is not the first item
    }
    current_node->prev = itemToInsert;              //set the ->next of the current as the new item

}