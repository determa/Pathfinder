#include "../inc/libmx.h"

char *mx_strnew(const int size) {
    char *string = malloc(size + 1);
    if (string == NULL) {
        return NULL;
    }
    for (int i = 0; i < size + 1; i++) {
        string[i] = '\0';
    }
    return string;
}

