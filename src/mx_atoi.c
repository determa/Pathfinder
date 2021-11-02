#include "../inc/header.h"

bool mx_isdigit(int c) {
    if (c >= 48 && c <= 57)
        return true;
    else
        return false;
}

int mx_atoi(const char *str) {
    int i = 0;
    long int res = 0;
    
    while (str[i]) {
        if(!mx_isdigit(str[i]))
            return -1;
        res = res * 10;
        res = res + (str[i] - 48);
        i++;
    }
    return res;
}

