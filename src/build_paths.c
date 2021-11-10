#include "../inc/header.h"

void build_path(int num, int len, int path[num], int graph[num][num], int t_graph[num][num], char *islands[]) {

    int i = path[len];
    int j = path[0];
    for (int k = 0; k < num; k++) {
        if (graph[i][k] == t_graph[i][j] - t_graph[k][j] && k != path[len]) {
            len++;
            path[len] = k;
            build_path(num, len, path, graph, t_graph, islands);
            len--;
        }
    }
    if (path[len] != path[0])
        return;
    
    print_path(num, len, path, graph, islands);
}

