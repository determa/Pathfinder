#include "../inc/libmx.h"

int mx_sqrt(int x) {
    if(x <= 0) 
        return 0;
    for (int i = 1; i < x; i++) 
        if (i * i == x)
            return i;
    return 0;
}

