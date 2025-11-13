#include <stddef.h>
#include <string.h>
#include <stdlib.h>

size_t filter_generic(const void *src, size_t len, size_t elem_size, void *dest, int (*pred)(const void *)) {
    const char *s = (const char *)src;
    char *d = (char *)dest;
    size_t j = 0;
    for (size_t i = 0; i < len; ++i) {
        const void *elem = s + i * elem_size;
        if (pred(elem)) {
            memcpy(d + j * elem_size, elem, elem_size);
            ++j;
        }
    }
    return j;
}