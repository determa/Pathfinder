#ifndef HEADER_H
#define HEADER_H
#define INT_MIN -2147483648
#define INT_MAX +2147483647

#include "../libmx/inc/libmx.h"

int mx_atoi(const char *str);

int get_size(char *str);
void parser(int num, char *islands[num], int graph[num][num], char *str);
void error_file(int argc, char **argv);
void error_list(int error_id, int line);

void floyd(int num, int graph[num][num], char *islands[]);
void build_path(int num, int len, int path[num], int graph[num][num], int t_graph[num][num], char *islands[]);
void print_path(int num, int len, int path[num], int graph[num][num], char *islands[]);

#endif

