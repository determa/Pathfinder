#include "../inc/libmx.h"

char *mx_strchr(const char *s, int c) {
    while (*s)
        s++;
    while (*s != c)
        s--;
    return (char*)s;
}

