#include "../inc/header.h"

void mx_clear_list(sm_list **list) {
    if (!*list) return; 
    sm_list *temp;
    while (*list) {
        //printf(" os ");
        temp = (*list) -> next;
        (*list) -> next = NULL;
        free(*list);
        *list = temp;
    }
    list = NULL;
}
void mx_clear_list_big(b_list **list) {
    if (!*list) return; 
    b_list *temp;
    while (*list) {
        //printf(" ok \n");
        temp = (*list) -> next_big;
        (*list) -> next_big = NULL;
        free(*list);
        *list = temp;
    }
    list = NULL;
}

