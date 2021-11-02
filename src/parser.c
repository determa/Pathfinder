#include "../inc/header.h"

/*void parser(int num, char *islands[num], int graph[num][num], char *str) {
    int i = 0;
    int city_num = 0;
    //int line = 1;
    char *tmp = str;
    char **island1;
    char **island2;
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            graph[i][j] = -1;
        }
        islands[i] = "NULL";
    }

    while (tmp[i] != '\n') {
        i++;
    }

    bool t = false;
    bool t2 = false;
    while (tmp[i] != '\0') {
        if (t == false) {
            island1 = mx_strsplit(&tmp[i], '-');
            t = true;
        }
        if (tmp[i] == '-' && t2 == false) {
            island2 = mx_strsplit(&tmp[i + 1], ',');
            t2 = true;
        }
        if (tmp[i] == '\n') {
            if (city_num < 2) {
                islands[city_num++] = island1;
            }
            for (int k = 0; k < city_num; k++) {
                islands[city_num++] = island2;
            }
            
            t = false;
            t2 = false;
        }
        i++;
    }
    mx_printstr(*island1);
    mx_printstr(" - ");
    mx_printstr(*island2);

    tmp++;
}
*/
