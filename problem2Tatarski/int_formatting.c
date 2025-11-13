#include <stdio.h>
#include <stdlib.h>

unsigned int extract_digits(unsigned int num, unsigned int start, unsigned int end) {
    char buf[32];
    sprintf(buf, "%u", num);
    unsigned int len = 0;
    while (buf[len]) len++;
    if (start >= len || end >= len || start > end) return 0;
    char out[32];
    unsigned int j = 0;
    for (unsigned int i = start; i <= end; i++) out[j++] = buf[i];
    out[j] = '\0';
    return (unsigned int)atoi(out);
}

unsigned int reverse_digits(unsigned int num) {
    unsigned int rev = 0;
    while (num > 0) {
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

void print_in_base(unsigned int num, unsigned int base) {
    if (base < 2 || base > 16) {
        printf("Invalid base.\n");
        return;
    }
    char digits[] = "0123456789ABCDEF";
    char buf[64];
    int i = 0;
    if (num == 0) {
        printf("0\n");
        return;
    }
    while (num > 0) {
        buf[i++] = digits[num % base];
        num /= base;
    }
    for (int j = i - 1; j >= 0; j--) putchar(buf[j]);
    putchar('\n');
}

unsigned int concat_numbers(unsigned int a, unsigned int b) {
    unsigned int mul = 1;
    unsigned int temp = b;
    while (temp > 0) {
        mul *= 10;
        temp /= 10;
    }
    return a * mul + b;
}

int main() {
    int op;
    while (1) {
        printf("Enter operation (1-extract, 2-reverse, 3-print base, 4-concat, 0-exit): ");
        if (scanf("%d", &op) != 1) break;
        if (op == 0) break;
        if (op == 1) {
            unsigned int num, s, e;
            printf("Enter number, start index, end index: ");
            scanf("%u%u%u", &num, &s, &e);
            printf("%u\n", extract_digits(num, s, e));
        } else if (op == 2) {
            unsigned int num;
            printf("Enter number: ");
            scanf("%u", &num);
            printf("%u\n", reverse_digits(num));
        } else if (op == 3) {
            unsigned int num, base;
            printf("Enter number and base (2-16): ");
            scanf("%u%u", &num, &base);
            print_in_base(num, base);
        } else if (op == 4) {
            unsigned int a, b;
            printf("Enter two numbers: ");
            scanf("%u%u", &a, &b);
            printf("%u\n", concat_numbers(a, b));
        } else {
            printf("Invalid operation.\n");
        }
    }
    return 0;
}
