#include <stddef.h>
#include <string.h>
#include <stdlib.h>

size_t filter_int(const int *src, size_t len, int *dest, int (*pred)(int)) {
    size_t j = 0;
    for (size_t i = 0; i < len; ++i) {
        if (pred(src[i])) {
            dest[j++] = src[i];
        }
    }
    return j;
}