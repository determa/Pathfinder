#include "../inc/header.h"

b_list *mx_create_node_big(sm_list *smaller_list, char *final_name) {
    b_list *new_node = NULL;

    if (!smaller_list)
        return NULL;
    else {
        new_node = (b_list *)malloc(sizeof(b_list));
        if (!new_node)
            return NULL;
        new_node->final_name = final_name;
        new_node->head = smaller_list;
        new_node->next_big = NULL;
        return new_node;
    }
}

