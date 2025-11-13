#include <stddef.h>
#include <string.h>
#include <stdlib.h>

void map_generic(void *arr, size_t len, size_t elem_size, void (*func)(void *)) {
    char *base = (char *)arr;
    for (size_t i = 0; i < len; ++i) {
        func(base + i * elem_size);
    }
}