#include "../inc/header.h"

void parser(int num, char *islands[num], int graph[num][num], char *str) {
    int i = 0;
    int city_num = 0;
    int line = 1;
    char *tmp = str;
    char **island;
    char **island_tmp;
    char *der;
    int dist = 0;
    int sum_dist = 0;
    bool t = true;

    // начальное заполнение графа и островов
    for(int i = 0; i < num; i++) {
        for(int j = 0; j < num; j++) {
            graph[i][j] = -1;
        }
        islands[i] = "\0";
    }
    // пропускаем строку с количеством островов
    while (tmp[i] != '\n') {
        i++;
    }

    // сам парсинг островов и дистанций
    while (tmp[i] != '\0') {
        if (tmp[i - 1] == '\n' || tmp[i] == '-' || tmp[i] == ',') {
            if (tmp[i - 1] == '\n') {
                line++;
                island = mx_strsplit(&tmp[i], '-');
                island_tmp = island;
            }
            if (tmp[i] == '-') {
                island = mx_strsplit(&tmp[i + 1], ',');
            }
            der = *island;
            for (int k = 0; k < mx_strlen(der); k++) {
                if(!mx_isalpha(der[k])) {
                    error_list(2, line);
                }
            }
            for (int k = 0; k < num; k++) {
                if (mx_strcmp(*island, islands[k]) == 0)
                    t = false;
            }
            if (t == true) {
                if (city_num == num)
                    error_list(3, line);
                islands[city_num++] = *island;
            }
            t = true;
            if (tmp[i] == ',') {
                if (mx_strcmp(*island, *island_tmp) == 0)
                    error_list(2, line);
                dist = mx_atoi(*mx_strsplit(&tmp[i + 1], '\n'));
                sum_dist += dist;
                if (sum_dist < 0)
                    error_list(5, line);
                
                // заполняем граф если находим 2 острова в массиве островов
                for (int k = 0; k < num; k++) {
                    for (int j = 0; j < num; j++) {
                        if (mx_strcmp(*island, islands[k]) == 0 && mx_strcmp(*island_tmp, islands[j]) == 0) {
                            if (graph[k][j] != -1)
                                error_list(4, line);

                            if (dist >= 0) {
                                graph[k][j] = dist;
                                graph[j][k] = dist;
                            }
                            else {
                                error_list(2, line);
                            }
                        }
                    }
                }
            }
        }
        i++;
    }
    if (city_num != num)
        error_list(3, line);
    mx_strdel(&tmp);
    mx_strdel(&der);
}

