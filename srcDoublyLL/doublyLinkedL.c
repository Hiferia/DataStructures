#include "doublyLinkedL.h"
#include "stringItem.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>

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

int get_List_Lenght(LIST_NODE_PTRPTR head)
{
    list_node_t *current_node = *head;

    int listLenght;
    while(current_node)
    {
        listLenght++;
        current_node = current_node->next;
    }
    return listLenght;
}

list_node_t *get_Node_From_List(LIST_NODE_PTRPTR head, int index)
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

void swap_Nodes(LIST_NODE_PTRPTR head, LIST_NODE_PTR node_01, LIST_NODE_PTR node_02)
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


    //TODO understand why if we swap with the last item it breaks
    //Swapping the nexts and prevs of the two nodes with the temps we worked with
    node_01->next = node_02_next_temp; 
    node_01->prev = node_02_prev_temp;

    node_02->next = node_01_next_temp;
    node_02->prev = node_01_prev_temp;


}
void shuffle_List(LIST_NODE_PTRPTR head)
{
    int listLenght = get_List_Lenght(head);                                             //we get the lenght of the list
    printf("list lenght is: %d \n", listLenght);
    srand(time(NULL));
    int shuffle_counter = ((rand() % listLenght) + 2);                                  //we set how many times we want to shuffle, it's random
    printf("we're gonna shuffle %d times\n", shuffle_counter);
    for (int i = 0; i < shuffle_counter; i++)                                           //we shuffle random times
    {
        printf("Shuffle number: %d\n", i);
        int random_01 = rand() % listLenght;                                            //creating random_01
        int random_02 = rand() % listLenght;                                            //creating random_02
                                                                                        //NOTE: we should add 1 at these random, atm they avoid the last element of the list
        while(random_01 == random_02)                                                   //changing random_02 till it's different from random_01
        {
            random_02 = rand() % listLenght;
        }

        list_node_t *node_01 = get_Node_From_List(head, random_01);                     //getting the first node at random_01 index
        list_node_t *node_02 = get_Node_From_List(head, random_02);                     //getting the second node at random_02 index

        printf("we're about to swap node %d with node %d\n", random_01, random_02);
        swap_Nodes(head, node_01, node_02);                                             //we call the swap function to swap the first and second node
    }
}
