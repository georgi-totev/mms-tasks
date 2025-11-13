#include <stddef.h>
#include <string.h>

void sort_generic(void *base, size_t len, size_t elem_size,
                  int (*cmp)(const void *, const void *)) {
    char *arr = (char *)base;
    char tmp[elem_size];

    for (size_t i = 0; i < len; ++i) {
        for (size_t j = i + 1; j < len; ++j) {
            void *a = arr + i * elem_size;
            void *b = arr + j * elem_size;
            if (cmp(a, b) > 0) {
                memcpy(tmp, a, elem_size);
                memcpy(a, b, elem_size);
                memcpy(b, tmp, elem_size);
            }
        }
    }
}
