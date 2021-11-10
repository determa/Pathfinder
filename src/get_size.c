#include "../inc/header.h"

int get_size(char *str) {
    for (int i = 0; i != '\0'; i++) {
        if (str[i] == '\n')
            break;
        if (str[i + 1] == '\0')
            return -1;
    }
    char **tmp = mx_strsplit(str, '\n');
    int res = mx_atoi(*tmp);
    mx_strdel(tmp);
    return res;
}

