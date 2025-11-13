#include <stdio.h>

void swap_by_pointer(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_by_reference(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}
