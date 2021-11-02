#include "../inc/header.h"

int get_size(char *str) {
    char **tmp = mx_strsplit(str, '\n');
    int res = mx_atoi(*tmp);
    mx_strdel(tmp);
    return res;
}

