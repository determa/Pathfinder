#include "../inc/header.h"

void print_path(b_list *big_list) {
    int dst;
    int l_count;
    b_list **tmp = &big_list;
    sm_list *tmp2 = NULL;

    while(big_list) {
        l_count = 0;
        dst = 0;
        tmp2 = big_list->head;
        mx_printstr("========================================\n");
        mx_printstr("Path: ");
        mx_printstr(big_list->head->name);
        mx_printstr(" -> ");
        mx_printstr(big_list->final_name);
        mx_printstr("\n");

        mx_printstr("Route: ");
        while(big_list->head) {
            mx_printstr(big_list->head->name);
            mx_printstr(" -> ");
            big_list->head = big_list->head->next;
            l_count++;
        }
        mx_printstr(big_list->final_name);

        mx_printstr("\nDistance: ");
        big_list->head = tmp2;
        while(big_list->head) {
            mx_printint(big_list->head->dist - dst);
            dst = big_list->head->dist;
            if (big_list->head->next == NULL) {
                if(l_count > 1) {
                    mx_printstr(" = ");
                    mx_printint(big_list->head->dist);
                }
            } else {
                mx_printstr(" + ");
            }
            big_list->head = big_list->head->next;
        }
        mx_printstr("\n========================================\n");
        mx_clear_list(&tmp2);
        big_list = big_list->next_big;
    }
    mx_clear_list_big(tmp);
}

