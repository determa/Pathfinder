#include "../inc/header.h"

int minDistance(int dist[], bool sptSet[], int num) {
    int min = INT_MAX, min_index;

    for (int v = 0; v < num; v++)
    if (sptSet[v] == false && dist[v] <= min)
        min = dist[v], min_index = v;

    return min_index;
}

void printSolution(b_list *big_list) {
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

void dijkstra(char *names[], int num, int graph[num][num]) {
    int dist[num];
    int dist_prev[num][2];
    bool sptSet[num]; 
    int tmp;
    int tmp2 = 0;
    int u = 0;
    b_list *big_list = NULL;
    
    //!!!! k<num
    for (int k = 0; k < 1; k++) {
        tmp = 0;
        for (int i = 0; i < num; i++) {
            dist[i] = INT_MAX; 
            sptSet[i] = false;
            dist_prev[i][0] = -1;
            dist_prev[i][1] = -1;
        }
        dist[k] = 0;
        for (int count = 0; count < num - 1; count++) {
            u = minDistance(dist, sptSet, num);
            sptSet[u] = true;
            for (int v = 0; v < num; v++) {
                tmp2 = tmp;
                tmp = dist[u] + graph[u][v];
                
                if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && tmp <= dist[v]) {
                    if (tmp == dist[v]) {
                        dist_prev[v][1] = u;
                    }
                    else {
                        dist_prev[v][0] = u;
                    }
                    dist[v] = tmp;
                }
            }
        }
        bool t = false;
        bool t2 = false;
        for (int count = k; count < num; count++) {
            sm_list *list = NULL;

            tmp = count;
            while(dist_prev[tmp][0] != -1) {
                if (dist_prev[tmp][1] != -1 && t == false) {
                    t = true;
                    mx_push_front_small(&list, names[dist_prev[tmp][1]], dist[tmp]);
                }
                else {
                    mx_push_front_small(&list, names[dist_prev[tmp][0]], dist[tmp]);
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
    printSolution(big_list);
}

//для тестов так, потом будет через функцию брать все
#define V 5

//int main(int argc, char *argv[]) {
int main(void) {
    //парсер
    /*if (argc != 2)
        error_list(argv[1], 0, -1);

    int file = open(argv[1], O_RDONLY);
    if (file == -1) {
        close(file);
        error_list(argv[1], 1, -1);
    }
    char buf = 0;
    if(read(file, &buf, 1) == 0)
        error_list(argv[1], 2, -1);
    close(file);
    
    char *str = mx_file_to_str(argv[1]);
    const int size = get_size(str);
    if (size < 0) {
        error_list(argv[1], 3, -1);
    }
    int graph[size][size];
    char *islands[size];
    parser(size, islands, graph, str);*/

    /*for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            mx_printstr(" ");
            mx_printint(graph[i][j]);
        }
        mx_printstr("\n");
    }
    for(int i = 0; i < size; i++) {
        mx_printstr(islands[i]);
        mx_printstr("\n");
    }*/
    //mx_printint(size);
    const int v = 5;

    /*int graph[V][V] = {{0,7,9,0,0,14},
                        {7,0,10,15,0,0},
                        {9,10,0,11,0,2},
                        {0,15,11,0,6,0},
                        {0,0,0,6,0,9},
                        {14,0,2,0,9,0}};*/

    //int gr[V][V];
    int gr[V][V] = {{0,11,10,0,0},
                      {11,0,0,5,0},
                      {10,0,0,6,15},
                      {0,5,6,0,4},
                      {0,0,15,4,0}};
    char *a[] = {"A","B","C","D","E"};

    //parser(v, &graph);
    /*for (int i = 0; i < v; i++) {
        for (int j = 0; j < v; j++) {
            mx_printint(graph[i][j]);
        }
        mx_printstr("\n");
    }*/
    //char *a[] = {"A","B","C","D","E","F"};

    dijkstra(a, v, gr);

    return 0;
}

