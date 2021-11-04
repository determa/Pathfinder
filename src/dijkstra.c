#include "../inc/header.h"

int minDistance(int dist[], bool sptSet[], int num) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < num; v++)
    if (sptSet[v] == false && dist[v] <= min)
        min = dist[v], min_index = v;

    return min_index;
}

void dijkstra(char *names[], int num, int graph[num][num]) {
    int dist[num];
    int dist2[num];
    int dist_prev[num][2];
    bool sptSet[num];
    int u = 0;
    int tmp;
    bool t = false;
    bool t2 = false;
    b_list *big_list = NULL;
    
    for (int k = 0; k < num; k++) {
        tmp = 0;
        for (int i = 0; i < num; i++) {
            dist[i] = INT_MAX;
            dist2[i]= INT_MAX;
            sptSet[i] = false;
            dist_prev[i][0] = -1;
            dist_prev[i][1] = -1;
        }
        dist[k] = 0;
        dist[k] = 0;
        
        for (int count = 0; count < num - 1; count++) {
            u = minDistance(dist, sptSet, num);
            sptSet[u] = true;
            for (int v = 0; v < num; v++) {

                tmp = dist[u] + graph[u][v];
                if (!sptSet[v] && graph[u][v] != -1 && dist[u] != INT_MAX && tmp <= dist[v]) {
                    if (tmp == dist[v]) {
                        dist_prev[v][1] = u;
                    }
                    else {
                        dist_prev[v][0] = u;
                    }
                    dist[v] = tmp;
                    dist2[v] = graph[u][v];
                }
            }
        }

        t = false;
        t2 = false;
        for (int count = k; count < num; count++) {
            sm_list *list = NULL;
            tmp = count;
            
            while(dist_prev[tmp][0] != -1) {
                if (dist_prev[tmp][1] != -1 && t == false) {
                    t = true;
                    mx_push_front_small(&list, names[dist_prev[tmp][1]], dist[tmp]);
                }
                else {
                    if (t == true && t2 == false) {
                        mx_push_front_small(&list, names[dist_prev[tmp][0]], dist[tmp - 1]);
                    }
                    else {
                        mx_push_front_small(&list, names[dist_prev[tmp][0]], dist[tmp]);
                    }
                }
                tmp = dist_prev[tmp][0];
                if (dist_prev[tmp][0] == -1 && t == true && t2 == false) {
                    mx_push_back_big(&big_list, list, names[count]);
                    t2 = true;
                    list = NULL;
                    tmp = count;
                }
            }
            mx_push_back_big(&big_list, list, names[count]);
            t = false;
            t2 = false;
        }
    }
    print_path(big_list);
}

