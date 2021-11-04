#include "../inc/header.h"

int main(int argc, char *argv[]) {
    // провеяем есть ли файл и не пустой ли он
    error_file(argc, argv);

    char *str = mx_file_to_str(argv[1]);

    // получаем кол-во островов, создаем граф и массив островов
    const int size = get_size(str);
    if (size < 0) {
        error_list(1, 1);
    }
    int graph[size][size];
    char *islands[size];

    //парсим и заполняем граф с островами
    parser(size, islands, graph, str);
    
    dijkstra(islands, size, graph);

    mx_strdel(islands);

    return 0;
}

