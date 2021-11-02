#include "../inc/libmx.h"

int mx_count_words(const char *str, char delimiter) {
    int count = 0;
    int delim = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if(str[i] == delimiter)
            delim = 0;
        else if (delim == 0) {
            delim = 1;
            count++;
        }
    }
    return count;
}

