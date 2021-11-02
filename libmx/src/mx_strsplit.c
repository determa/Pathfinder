#include "../inc/libmx.h"

char **mx_strsplit(const char *s, char c) {
    int count_words = 0;
    
    if (!s || (count_words = mx_count_words(s, c)) < 0)
        return NULL;
    
    char **split = malloc(sizeof(char*) * count_words + 1);
    split[count_words] = NULL;
    
    for (int i = 0, len = 0; i < count_words; ++i, s += len, len = 0) {
        for (; *s == c; ++s);
        for (; s[len] != c; ++len);
        split[i] = mx_strnew(len);
        mx_strncpy(split[i], s, len);
    }
    return split;
}

