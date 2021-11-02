#include "../inc/header.h"

void mx_push_back_big(b_list **list, sm_list *smaller_list, char *final_name) {
    if (!*list) {
        *list = mx_create_node_big(smaller_list, final_name);
        return;
    }
    b_list *temp = *list;
    while (temp->next_big) {
        temp = temp->next_big;
    }
    temp->next_big = mx_create_node_big(smaller_list, final_name);
}

