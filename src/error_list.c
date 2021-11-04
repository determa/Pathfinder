#include "../inc/header.h"

void error_file(int argc, char **argv) {
    if (argc != 2) {
        mx_printerr("usage: ./pathfinder [filename]\n");
        exit(-1);
    }

    int file = open(argv[1], O_RDONLY);
    if (file == -1) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" does not exist\n");
        close(file);
        exit(-1);
    }
    char buf = 0;
    if(read(file, &buf, 1) == 0) {
        mx_printerr("error: file ");
        mx_printerr(argv[1]);
        mx_printerr(" is empty\n");
        close(file);
        exit(-1);
    }
}

void error_list(int error_id, int line) {
    switch (error_id) {
        
        case 1:
            mx_printerr("error: line 1 is not valid\n");
            exit(-1);
            break;

        case 2:
            mx_printerr("error: line ");
            mx_printerr(mx_itoa(line));
            mx_printerr(" is not valid\n");
            exit(-1);
            break;

        case 3:
            mx_printerr("error: invalid number of islands\n");
            exit(-1);
            break;

        case 4:
            mx_printerr("error: duplicate bridges\n");
            exit(-1);
            break;

        case 5:
            mx_printerr("error: sum of bridges lengths is too big\n");
            exit(-1);
            break;
        
        default:
            exit(-1);
            break;
    }
}

