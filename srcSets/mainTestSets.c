#include "sets.h"
#include <stdio.h>


int main()
{
    char *item0 = "Luigi";
    char *item1 = "Hello";
    char *item2 = "Lulu";
    char *item3 = "blabla";
    char *item4 = "blabla";

    set_table_t *set_table_0 = set_table_new(10);

    set_insert(set_table_0, item0);
    set_insert(set_table_0, item1);
    set_insert(set_table_0, item2);
    set_insert(set_table_0, item3);
    set_insert(set_table_0, item4);

    //remove_item(set_table_0, item3);
    remove_item(set_table_0, item0);

    if(search_item(set_table_0, item3))
    {
        printf("The item is in the set\n");
    }
    else printf("The item is not in the set\n");

    set_insert(set_table_0, item3);

    if(search_item(set_table_0, item1))
    {
        printf("Now the item is in the set\n");
    }
    else printf("Now the item is not in the set\n");
}