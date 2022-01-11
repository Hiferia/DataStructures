#pragma once


typedef struct dictionary_node
{
    const char *key;
    size_t key_len;
    void *value;
    struct dictionary_node *next;
    struct dictionary_node *prev;
}dictionary_node_t;

typedef struct  dictionary_table
{
    dictionary_node_t **nodes;
    size_t hashmap_size;
}dictionary_table_t;

dictionary_table_t *dictionary_table_new(const size_t hashmap_size);
size_t get_Index(const size_t hashmap_size, const char *key);
dictionary_node_t *dictionary_insert(dictionary_table_t *table, const char *key, void *value);
dictionary_node_t *search_item(dictionary_table_t *table, const char *key);
dictionary_node_t *search_item01(dictionary_table_t *table, const char *key);
void remove_item01(dictionary_table_t *table, const char *key);
void remove_item(dictionary_table_t *table, const char *key);
void print_Dictionary_Node_double(dictionary_table_t *table, const char *key);
void print_Dictionary_Node_int(dictionary_table_t *table, const char *key);
void print_Dictionary_Node_char(dictionary_table_t *table, const char *key);
void print_Dictionary_Node_float(dictionary_table_t *table, const char *key);
