#pragma once
#include <stddef.h>

typedef struct set_node
{
    const char *key;
    size_t key_len;
    struct set_node *next;
}set_node_t;

typedef struct  set_table
{
    set_node_t **nodes;
    size_t hashmap_size;
}set_table_t;

size_t djb33x_hash(const char *key, const size_t keylen);
set_table_t *set_table_new(const size_t hashmap_size);
size_t get_Index(const size_t hashmap_size, const char *key);
set_node_t *set_insert(set_table_t *table, const char *key);
set_node_t *search_item(set_table_t *table, const char *key);
void remove_item(set_table_t *table, const char *key);





