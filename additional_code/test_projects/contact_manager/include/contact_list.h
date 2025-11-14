#include <stdlib.h>
#include "contact.h"

typedef struct{
    Contact* data;
    size_t size;
    size_t capacity;

} Contact_List;

void contact_list_init(Contact_List* list);
void contact_list_add(Contact_List* list, Contact c);
void contact_list_delete(Contact_List* list, int id);
void contact_list_print(const Contact_List* list);
void contact_list_free(Contact_List* list);