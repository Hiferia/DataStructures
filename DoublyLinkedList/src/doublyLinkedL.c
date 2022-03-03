#include "doublyLinkedL.h"
#include "stringItem.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

list_node_t *ls_list_get_tail(LIST_NODE_PTRPTR head)
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


list_node_t *ls_list_append(LIST_NODE_PTRPTR head, LIST_NODE_PTR item)
{
    list_node_t *tail = ls_list_get_tail(head);
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

list_node_t *ls_remove_node(LIST_NODE_PTRPTR head, LIST_NODE_PTR item)
{
    list_node_t *current_node = *head;
     if(current_node == item)                    //if the item is the first item in the list
    {
        *head = item->next;
        current_node->next->prev = NULL;
        current_node->next = NULL;
        free(item);
        return current_node;
    }

    list_node_t *previous_node = NULL;

    if(!current_node) return NULL;

    while(current_node->next != item)               //the cycle continue till it reaches the node that has "item" into his ->next
    {
        previous_node = current_node;               //we set the previous node as the current node
        current_node = current_node->next;          //we set the current node as the next node so we move 1 node ahead
    }

    //we're out of the cycle, that means we reach the node that has "item" into his ->next
    current_node->next = item->next;                //we change the ->next of the current node into the ->next of the item
    if(current_node->next != NULL)                  //if the current node is not the last node
    {
        current_node->next->prev = current_node;    //we change the prev of the next node into the current node (cause it was item)
    }
                                                    //now we have item attached to anything       
    free(item);                                     //we can free the memory it occupied
    return current_node;
}

void ls_reverse_list(LIST_NODE_PTRPTR head)
{
    list_node_t *current_node = *head;
    list_node_t *next_node = NULL;
    list_node_t *prev_node = NULL;

    while(current_node != NULL)
    {
        next_node = current_node->next;     //set the next_node using current->next
        current_node->next = prev_node;     //change the next of the current_node, in the first cicle we'll have NULL cause it will be the last item on the list
        current_node->prev = next_node;     //change the next of the current_node
        prev_node = current_node;           //set the prev_node as the current_node, at the next cicle the current_node will have this prev as next
        current_node = next_node;           //Move 1 position ahead and restart
    }
    *head = prev_node;                      //change the head into the prev node
}

void ls_insert_after(LIST_NODE_PTRPTR head, LIST_NODE_PTR item_to_insert, LIST_NODE_PTR item_to_use)
{
    list_node_t *current_node = *head;

    while(current_node != item_to_use)
    {
        current_node = current_node->next;          //cycle till it reaches the item we are looking for
    }

    item_to_insert->next = current_node->next;        //set the ->next of the new item as the ->next of the current
    item_to_insert->prev = current_node;              //set the ->prev of the new item as current node
    if(current_node->next != NULL)
    {
        current_node->next->prev = item_to_insert;    //set the ->prev of the ->next as the new item, if current node is not the last item
    }
    current_node->next = item_to_insert;              //set the ->next of the current as the new item

}
void ls_insert_before(LIST_NODE_PTRPTR head, LIST_NODE_PTR item_to_insert, LIST_NODE_PTR item_to_use)
{
    list_node_t *current_node = *head;

    while(current_node != item_to_use)
    {
        current_node = current_node->next;          //cycle till it reaches the item we are looking for
    }

    item_to_insert->next = current_node;              //set the next of the new item as the current node
    item_to_insert->prev = current_node->prev;        //set the -prev of the new item as the -prev of the current
    if(current_node->prev != NULL)
    {
        current_node->prev->next = item_to_insert;    //set the ->prev of the ->next as the new item, if current node is not the first item
    }
    current_node->prev = item_to_insert;              //set the ->next of the current as the new item

}

int ls_get_list_lenght(LIST_NODE_PTRPTR head)
{
    list_node_t *current_node = *head;

    int listLenght = 0;
    while(current_node)
    {
        listLenght++;
        current_node = current_node->next;
    }
    return listLenght;
}

list_node_t *ls_get_node_from_list(LIST_NODE_PTRPTR head, int index)
{
    //A little function to get a node from the list having an index
    if(index < 0) return NULL;
    list_node_t *current_node = *head;
    for (int i = 0; i < index; i++)
    {
        if(!current_node) return NULL;
        current_node = current_node->next;
    }
    
    return current_node;
}

void ls_swap_nodes(LIST_NODE_PTRPTR head, LIST_NODE_PTR node_01, LIST_NODE_PTR node_02)
{
    //Creating next and prev temps to work with
    list_node_t *node_01_next_temp = node_01->next;
    list_node_t *node_01_prev_temp = node_01->prev;

    list_node_t *node_02_next_temp = node_02->next;
    list_node_t *node_02_prev_temp = node_02->prev;

    if(node_01->next == node_02)                    //if node_02 is next to node_01 we already set the next and prev
    {
        node_01_next_temp = node_01;
        node_02_prev_temp = node_02;
    }
    if(node_01->prev == node_02)                   //if node_02 is prev to node_01 we already set the next and prev
    {
        node_01_prev_temp = node_01;
        node_02_next_temp = node_02;
    }
    
    if(node_01_next_temp!=NULL)                     //if next of 01 is not NULL we change his prev into node_02
    {
        node_01_next_temp->prev = node_02;
    }
    if(node_01_prev_temp != NULL)                   //if prev of 01 is not NULL we change his next into node_02
    {
        node_01_prev_temp->next = node_02;
    }
    else *head = node_02;                           //if prev is NULL it means node_01 was the head, so we have to change it

     
    if(node_02_next_temp!=NULL)                     //if next of 02 is not NULL we change his prev into node_01
    {
        node_02_next_temp->prev = node_01;
    }

    if(node_02_prev_temp != NULL)                   //if prev of 02 is not NULL we change his next into node_01
    {
        node_02_prev_temp->next = node_01;
    }
    else *head = node_01;                           //if prev is NULL it means node_01 was the head, so we have to change it


    //Swapping the nexts and prevs of the two nodes with the temps we worked with
    node_01->next = node_02_next_temp; 
    node_01->prev = node_02_prev_temp;

    node_02->next = node_01_next_temp;
    node_02->prev = node_01_prev_temp;
}
void ls_shuffle_list(LIST_NODE_PTRPTR head)
{
    int listLenght = ls_get_list_lenght(head);                                          //we get the lenght of the list
    srand(time(NULL));
    int shuffle_counter = ((rand() % listLenght) + 2);                                  //we set how many times we want to shuffle, it's random
    for (int i = 0; i < shuffle_counter; i++)                                           //we shuffle random times
    {
        int random_01 = rand() % listLenght;                                            //creating random_01
        int random_02 = rand() % listLenght;                                            //creating random_02
        while(random_01 == random_02)                                                   //changing random_02 till it's different from random_02
        {
            random_02 = rand() % listLenght;
        }

        list_node_t *node_01 = ls_get_node_from_list(head, random_01);                  //getting the first node at random_01 index
        list_node_t *node_02 = ls_get_node_from_list(head, random_02);                  //getting the second node at random_02 index

        ls_swap_nodes(head, node_01, node_02);                                          //we call the swap function to swap the first and second node
    }
}
void ls_shuffle_list_not_random_nearby_nodes(LIST_NODE_PTRPTR head, int shuffle_times)
{
    int listLenght = ls_get_list_lenght(head);                                          //we get the lenght of the list
    for (int i = 0; i < shuffle_times; i++)                                             //we shuffle random times
    {
        int random_01 = i;                                                              //creating random_01
        int random_02 = i + 1;                                                          //creating random_02

        list_node_t *node_01 = ls_get_node_from_list(head, random_01);                  //getting the first node at random_01 index
        list_node_t *node_02 = ls_get_node_from_list(head, random_02);                  //getting the second node at random_02 index

        ls_swap_nodes(head, node_01, node_02);                                          //we call the swap function to swap the first and second node
    }
}
void ls_shuffle_list_not_random_distant_nodes(LIST_NODE_PTRPTR head, int shuffle_times)
{
    int listLenght = ls_get_list_lenght(head);                                          //we get the lenght of the list
    for (int i = 0; i < shuffle_times; i++)                                             //we shuffle random times
    {
        int random_01 = i;                                                              //creating random_01
        int random_02 = i + 2;                                                          //creating random_02

        list_node_t *node_01 = ls_get_node_from_list(head, random_01);                  //getting the first node at random_01 index
        list_node_t *node_02 = ls_get_node_from_list(head, random_02);                  //getting the second node at random_02 index

        ls_swap_nodes(head, node_01, node_02);                                          //we call the swap function to swap the first and second node
    }
}