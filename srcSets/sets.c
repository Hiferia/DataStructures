#include "sets.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

size_t djb33x_hash(const char *key, const size_t keylen)
{
    size_t hash = 5381;
    for (size_t i = 0; i < keylen; i++)
    {
        hash = ((hash << 5) + hash) ^ key[i];
    }
    return hash;
}

set_table_t *set_table_new(const size_t hashmap_size)
{
    set_table_t *table = malloc(sizeof(set_table_t));
    if(!table)
    {
        return NULL;
    }
    table->hashmap_size = hashmap_size;
    table->nodes = calloc(table->hashmap_size, sizeof(set_node_t));
    if(!table->nodes)
    {
        free(table);
        return NULL;
    }
    printf("table created\n");
    return table;
}

size_t get_Index(const size_t hashmap_size, const char *key)
{
    size_t hash = djb33x_hash(key, strlen(key));
    size_t index = hash % hashmap_size;
    return index;
}

set_node_t *set_insert(set_table_t *table, const char *key)
{
    const size_t key_len = strlen(key);
    printf("trying to insert\n");
    size_t index = get_Index(table->hashmap_size, key);

    set_node_t *head = table->nodes[index];

    if(head)
    {
        if(strcmp(key, head->key) == 0)
        {
            printf("The item is already in the set\n");
            return head;
        }
    }
    if(!head)
    {
        table->nodes[index] = malloc(sizeof(set_node_t));
        if(!table->nodes[index])
        {
            printf("first null");
            return NULL;
        }
        table->nodes[index]->key = key;
        table->nodes[index]->key_len = key_len;
        table->nodes[index]->next = NULL;
        return table->nodes[index];
    }
    set_node_t *new_item = malloc(sizeof(set_node_t));
    if(!new_item)
    {
        printf("second null");

        return NULL;
    }

    new_item->key = key;
    new_item->key_len = key_len;
    new_item->next = NULL;

    set_node_t *tail = head;
    while(head)
    {
        tail = head;
        head = head->next;
    }
    tail->next = new_item;
    return new_item;
}

set_node_t *search_item(set_table_t *table, const char *key)
{
    size_t index = get_Index(table->hashmap_size, key);             //calling the function get_Index to get the index of the item we are looking for
    set_node_t *current_node = table->nodes[index];                 //creating a node like the one we are looking for
    if(current_node)
    {
        if(strcmp(key, current_node->key) == 0)                     //comparing the key
        {
            return current_node;
        }
    }
    return NULL;
}
void remove_item(set_table_t *table, const char *key)
{
    size_t index = get_Index(table->hashmap_size, key);
    set_node_t *current_node = table->nodes[index];
    if(current_node)
    {
        table->nodes[index] = current_node->next;
    }
}