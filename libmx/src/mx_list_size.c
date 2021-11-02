#include "../inc/libmx.h"

int mx_list_size(t_list *list) {
    int i  = 0;
    while (list != NULL) {
        list = list->next;
        i++;
    }
    return  i;
}

