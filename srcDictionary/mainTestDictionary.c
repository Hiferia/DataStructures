#include "dictionary.h"
#include <stdio.h>




int main()
{
    char *key0 = "Luigi";
    char *key1 = "Hello";
    char *key2 = "Lulu";
    char *key3 = "blabla";
    char *key4 = "blabla";

    int value_0 = 4;
    char *value_01 = "Value!";
    float value_02 = 0.5;
    double value_03 = 1.56;

    dictionary_table_t *dictionary_table_0 = dictionary_table_new(10);

    dictionary_insert(dictionary_table_0, key0, &value_0);
    dictionary_insert(dictionary_table_0, key1, value_01);
    dictionary_insert(dictionary_table_0, key2, &value_02);
    dictionary_insert(dictionary_table_0, key3, &value_03);
    dictionary_insert(dictionary_table_0, key4, &value_0);

    

    

    print_Dictionary_Node_int(dictionary_table_0, key0);
    print_Dictionary_Node_double(dictionary_table_0, key3);
    print_Dictionary_Node_float(dictionary_table_0, key2);
    print_Dictionary_Node_char(dictionary_table_0, key1);

    remove_item01(dictionary_table_0, key3);

    if(search_item01(dictionary_table_0, key3))
    {
        printf("The item is in the set\n");
    }
    else printf("The item is not in the set\n");

    dictionary_insert(dictionary_table_0, key3, &value_03);

    if(search_item01(dictionary_table_0, key1))
    {
        printf("Now the item is in the set\n");
    }
    else printf("Now the item is not in the set\n");
}