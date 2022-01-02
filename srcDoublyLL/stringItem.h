#pragma once


#include "doublyLinkedL.h"

typedef struct string_item
{
    list_node_t node;
    const char *string;
}string_item_t;

string_item_t *string_item_new(const char *string);