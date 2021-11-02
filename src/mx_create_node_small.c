#include "../inc/header.h"

sm_list *mx_create_node_small(char *name, int dist) {
    sm_list *new_node = NULL;

    if (!name)
        return NULL;
    else {
        new_node = (sm_list *)malloc(sizeof(sm_list));
        if (!new_node)
            return NULL;
        new_node->name = name;
        new_node->dist = dist;
        new_node->next = NULL;
        return new_node;
    }
}

