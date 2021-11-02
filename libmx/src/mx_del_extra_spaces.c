#include "../inc/libmx.h"

char *mx_del_extra_spaces(const char *str) {
    char *arr = NULL;
    char *tmp = NULL;
    int i = 0;
    int j = 0;

    if (!str) return NULL;
    
    arr = mx_strnew(mx_strlen(str));
    while (str[i]) {
        if (!(mx_isspace(str[i]))) {
            arr[j] = str[i];
            j++;
        }
        if (!(mx_isspace(str[i])) && mx_isspace(str[i + 1])) {
            arr[j] = ' ';
            j++;
        }
        i++;
    }
    tmp = mx_strtrim(arr);
    mx_strdel(&arr);
    return tmp;
}

