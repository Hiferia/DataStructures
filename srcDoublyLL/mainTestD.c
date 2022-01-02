#include "doublyLinkedL.h"
#include "stringItem.h"
#include <stdio.h>
#include <stddef.h>

int main()
{
    string_item_t *my_doubly_linked_list = NULL;
    string_item_t *item1 = string_item_new("Hello World");
    string_item_t *item2 = string_item_new("Ciao");
    string_item_t *item3 = string_item_new("Giulia");
    string_item_t *item4 = string_item_new("Gigi");
    string_item_t *item5 = string_item_new("blabla");
    string_item_t *item6 = string_item_new("INTRUSO");
    string_item_t *item7 = string_item_new("INTRUSO2");

    list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item1);
    list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item2);
    list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item3);
    list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item4);
    list_append((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item5);

    remove_node((list_node_t **)&my_doubly_linked_list, (list_node_t *)item5);
    
    insert_after((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item6, (LIST_NODE_PTR)item2);

    insert_before((LIST_NODE_PTRPTR)&my_doubly_linked_list, (LIST_NODE_PTR)item7, (LIST_NODE_PTR)item2);

    reverse((LIST_NODE_PTRPTR)&my_doubly_linked_list);

    
    
    string_item_t *string_item = my_doubly_linked_list;

    while(string_item)
    {
        printf("%s\n", string_item->string);
        string_item = (string_item_t *)string_item->node.next;
    }
    return 0;
}