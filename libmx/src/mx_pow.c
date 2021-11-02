#include "../inc/libmx.h"

double mx_pow(double n, unsigned int pow) {
    if (pow == 0) return 1;
    if (pow < 0) return mx_pow(10 / n, -pow);
    return n * mx_pow(n, pow -1);
}

