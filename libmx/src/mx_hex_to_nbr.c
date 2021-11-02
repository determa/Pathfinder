#include "../inc/libmx.h"

bool mx_isdigit(int c) {
    if (c  >= '0' && c <= '9') {
        return 1;
    }
    else {
        return 0;
    }
}

bool mx_islower(int c) {
    if (c >= 'a' && c <= 'z') 
        return true;
    else
        return false;
}

bool mx_isupper(int c) {
    if (c >= 'A' && c <= 'Z')
        return true;
    else
        return false;
}

unsigned long mx_hex_to_nbr(const char *hex) {
    int l = 0;
    unsigned long num = 0;
    unsigned long b = 1;

    if (hex != NULL) {
        while (hex[l])
            l++;
    }
    else {
        return num;
    }

    for (int i = 0; i <= l; i++) {
        if (mx_isdigit(hex[l - i])) {
            num = num + (hex[l - i] - 48) * b;
            b = b * 16;
        }
        if (mx_isupper(hex[l - i])) {
            num = num + (hex[l - i] - 55) * b;
            b = b * 16;
        }
        if (mx_islower(hex[l - i])) {
            num = num + (hex[l - i] - 87) * b;
            b = b * 16;
        }
    }
    return num;
}

