#include "../inc/header.h"

void mx_push_front_small(sm_list **list, char *name, int dist) {
    if (!*list) {
        *list = mx_create_node_small(name, dist);
        return;
    }
    sm_list *temp = mx_create_node_small(name, dist);
    temp->next = *list;
    *list = temp;
}

