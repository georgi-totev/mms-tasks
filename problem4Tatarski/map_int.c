#include <stddef.h>
#include <string.h>
#include <stdlib.h>


void map_int(int *arr, size_t len, int (*func)(int)) {
    for (size_t i = 0; i < len; ++i) {
        arr[i] = func(arr[i]);
    }
}