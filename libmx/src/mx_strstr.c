#include "../inc/libmx.h"

char *mx_strstr(const char *s1, const char *s2) {

    int len1 = mx_strlen(s1);
    int len2 = mx_strlen(s2);      
    
    for (int i = 0; i<len1; s1++, i++) {
        char *tmp = mx_strchr(s1, s1[0]);

        if(mx_strncmp(tmp, s2, len2) == 0)
            return (char*)s1;
    }
    return NULL;

}

