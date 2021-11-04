#ifndef HEADER_H
#define HEADER_H

#include "../libmx/inc/libmx.h"
#include <limits.h>

typedef struct a_list {
    char *name;
    int dist;
    struct a_list *next;
}               sm_list;

typedef struct c_list {
    char *final_name;
    sm_list *head;
    struct c_list *next_big;
}               b_list;


void mx_push_back_big(b_list **list, sm_list *smaller_list, char *final_name);
b_list *mx_create_node_big(sm_list *smaller_list, char *final_name);
sm_list *mx_create_node_small(char *name, int dist);
void mx_push_front_small(sm_list **list, char *name, int dist);
void mx_clear_list(sm_list **list);
void mx_clear_list_big(b_list **list);

int mx_atoi(const char *str);
int get_size(char *str);
void parser(int num, char *islands[num], int graph[num][num], char *str);
void dijkstra(char *names[], int num, int graph[num][num]);
void error_file(int argc, char **argv);
void error_list(int error_id, int line);
void print_path(b_list *big_list);

#endif

