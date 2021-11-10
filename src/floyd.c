#include "../inc/header.h"

void floyd(int num, int graph[num][num], char *islands[]) {
    int tmp;
    int t_graph[num][num];

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            t_graph[i][j] = graph[i][j];
        }
    }
    for (int k = 0; k < num; k++) {
        for (int i = 0; i < num; i++) {
            for (int j = i + 1; j < num; j++) {
                tmp = t_graph[i][k] + t_graph[k][j];
                if (t_graph[i][k] != INT_MAX && t_graph[k][j] != INT_MAX && tmp < t_graph[i][j]) {
                    t_graph[i][j] = tmp;
                    t_graph[j][i] = tmp;
                }
            }
        }
    }
    int path[num];
    for (int i = 0; i < num; i++) {
        for (int j = i + 1; j < num; j++) {
            path[1] = i;
            path[0] = j;
            build_path(num, 1, path, graph, t_graph, islands);
        }
    }
}

