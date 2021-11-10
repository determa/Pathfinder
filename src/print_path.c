#include "../inc/header.h"

void print_path(int num, int len, int path[num], int graph[num][num], char *islands[]) {
    int res = 0;

    mx_printstr("========================================\n");
    mx_printstr("Path: ");
    mx_printstr(islands[path[1]]);
    mx_printstr(" -> ");
    mx_printstr(islands[path[0]]);
    mx_printstr("\n"); 

    mx_printstr("Route: ");
    for (int i = 1; i < len + 1; i++) {
        mx_printstr(islands[path[i]]); 
        if (i < len)
            mx_printstr(" -> ");
    }
    mx_printstr("\n");
    
    mx_printstr("Distance: ");
    for (int i = 1; i < len; i++) {
        mx_printint(graph[path[i]][path[i + 1]]);
        res += graph[path[i]][path[i + 1]];

        if (i < len - 1) {
            mx_printstr(" + ");
        }
        else {
            if (i > 1) {
                mx_printstr(" = ");
                mx_printint(res);
            }
        }
    }
    mx_printstr("\n========================================\n");
}

