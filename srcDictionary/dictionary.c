#include "dictionary.h"
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
dictionary_table_t *dictionary_table_new(const size_t hashmap_size)
{
    dictionary_table_t *table = malloc(sizeof(dictionary_table_t));
    if(!table)
    {
        return NULL;
    }
    table->hashmap_size = hashmap_size;
    table->nodes = calloc(table->hashmap_size, sizeof(dictionary_node_t));
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

dictionary_node_t *dictionary_insert(dictionary_table_t *table, const char *key, void *value)
{
    const size_t key_len = strlen(key);
    printf("trying to insert\n");
    size_t index = get_Index(table->hashmap_size, key);

    dictionary_node_t *head = table->nodes[index];

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
        table->nodes[index] = malloc(sizeof(dictionary_node_t));
        if(!table->nodes[index])
        {
            return NULL;
        }
        table->nodes[index]->key = key;
        table->nodes[index]->key_len = key_len;
        table->nodes[index]->value = value;
        table->nodes[index]->next = NULL;
        table->nodes[index]->prev = NULL;
        return table->nodes[index];
    }
    dictionary_node_t *new_item = malloc(sizeof(dictionary_node_t));
    if(!new_item)
    {
        return NULL;
    }

    new_item->key = key;
    new_item->key_len = key_len;
    new_item->value = value;
    new_item->next = NULL;
    new_item->prev = NULL;

    dictionary_node_t *tail = head;
    while(head)
    {
        tail = head;
        head = head->next;
    }
    tail->next = new_item;
    return new_item;
}

dictionary_node_t *search_item(dictionary_table_t *table, const char *key)
{
    size_t index = get_Index(table->hashmap_size, key);             //calling the function get_Index to get the index of the item we are looking for
    dictionary_node_t *current_node = table->nodes[index];          //creating a node like the one we are looking for
    
    while (current_node)                                            //cycling till current_node is not null
    {
        if(strcmp(key, current_node->key) == 0)                     //comparing the key
        {
            return current_node;
        }
        current_node = current_node->next;
    }
    return NULL;
}
dictionary_node_t *search_item01(dictionary_table_t *table, const char *key)
{
    size_t index = get_Index(table->hashmap_size, key);             //calling the function get_Index to get the index of the item we are looking for
    dictionary_node_t *current_node = table->nodes[index];          //creating a node like the one we are looking for
    if(current_node)
    {
        if(strcmp(key, current_node->key) == 0)                     //comparing the key
        {
            return current_node;
        }
    }
    return NULL;
}
void remove_item01(dictionary_table_t *table, const char *key)
{
    size_t index = get_Index(table->hashmap_size, key);
    dictionary_node_t *current_node = table->nodes[index];
    if(current_node)
    {
        table->nodes[index] = current_node->next;
        printf("Key %s removed\n", key);
    }
}

void remove_item(dictionary_table_t *table, const char *key)
{
    size_t index = get_Index(table->hashmap_size, key);
    dictionary_node_t *prev_node = NULL;
    dictionary_node_t *current_node = table->nodes[index];

    while(strcmp(current_node->key, key) != 0)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }
    if(prev_node)
    {
        prev_node->next = current_node->next;
    }
    else
    {
        table->nodes[index] = current_node->next;
    }
}

void print_Dictionary_Node_double(dictionary_table_t *table, const char *key)
{
    size_t index = get_Index(table->hashmap_size, key);             //calling the function get_Index to get the index of the item we are looking for
    dictionary_node_t *current_node = table->nodes[index];          //creating a node like the one we are looking for
    if(current_node)
    {
        if(strcmp(key, current_node->key) == 0)                     //comparing the key
        {
            printf("Key %s is in the dictionary and is value is %f\n", key, *(double*)current_node->value);
        }
    }
}
void print_Dictionary_Node_int(dictionary_table_t *table, const char *key)
{
    size_t index = get_Index(table->hashmap_size, key);             //calling the function get_Index to get the index of the item we are looking for
    dictionary_node_t *current_node = table->nodes[index];          //creating a node like the one we are looking for
    if(current_node)
    {
        if(strcmp(key, current_node->key) == 0)                     //comparing the key
        {
            printf("Key %s is in the dictionary and is value is %d\n", key, *(int*)current_node->value);
        }
    }
}
void print_Dictionary_Node_char(dictionary_table_t *table, const char *key)
{
    size_t index = get_Index(table->hashmap_size, key);             //calling the function get_Index to get the index of the item we are looking for
    dictionary_node_t *current_node = table->nodes[index];          //creating a node like the one we are looking for
    if(current_node)
    {
        if(strcmp(key, current_node->key) == 0)                     //comparing the key
        {
            printf("Key %s is in the dictionary and is value is %s\n", key, (char*)current_node->value);
        }
    }
}
void print_Dictionary_Node_float(dictionary_table_t *table, const char *key)
{
    size_t index = get_Index(table->hashmap_size, key);             //calling the function get_Index to get the index of the item we are looking for
    dictionary_node_t *current_node = table->nodes[index];          //creating a node like the one we are looking for
    if(current_node)
    {
        if(strcmp(key, current_node->key) == 0)                     //comparing the key
        {
            printf("Key %s is in the dictionary and is value is %f\n", key, *(float*)current_node->value);
        }
    }
}