#include "contact_list.h"

void contact_list_init(Contact_List* list){
    list->size = 0; // list->size is the same as (*list).size
    list->capacity = 4;
    list->data = malloc(list->capacity * sizeof(Contact));
}

void contact_list_add(Contact_List* list, Contact c){
    

}
