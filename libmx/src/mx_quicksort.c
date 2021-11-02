#include "../inc/libmx.h"

int mx_quicksort(char **arr, int left, int right) {
    if (!arr) return -1;
    int counter = 0;

    if (left < right) {
        int i = left;
        int j = right;
        char *pivot = arr[(j + i) / 2];

        while (i <= j) {
            while (mx_strlen(arr[i]) < mx_strlen(pivot)) 
                i++;
            while (mx_strlen(arr[j]) > mx_strlen(pivot)) 
                j--;

            if (i <= j) {
                if (mx_strlen(arr[j]) != mx_strlen(arr[i])) {
                    char *temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                    counter++;
                }
                j--;
                i++;
            }
        }

        counter += mx_quicksort(arr, left, j);
        counter += mx_quicksort(arr, i, right);
    }    
    return counter;
}

