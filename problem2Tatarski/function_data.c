#include <stdio.h>

static int is_prime(unsigned int n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if ((n & 1u) == 0) return 0;
    for (unsigned int i = 3; i * (unsigned long)i <= n; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

static int is_palindrome_decimal(unsigned int n) {
    unsigned int orig = n, rev = 0;
    while (n > 0) {
        rev = rev * 10u + (n % 10u);
        n /= 10u;
    }
    return orig == rev;
}

static int has_equal_ones_zeros_binary(unsigned int n) {
    unsigned int ones = 0, bits = 0;
    while (n > 0) {
        ones += (n & 1u);
        bits += 1u;
        n >>= 1u;
    }
    if (bits == 0) return 0;          
    return (bits % 2u == 0) && (ones * 2u == bits);
}

int analyze_range(unsigned int start,
                  unsigned int end,
                  unsigned int *prime_count,
                  unsigned int *pal_count,
                  unsigned int *eq_bits_count) {
    if (start == 0u || end == 0u || start > end ||
        !prime_count || !pal_count || !eq_bits_count) {
        return -1;
    }

    unsigned int pc = 0, palc = 0, eqc = 0;

    for (unsigned int x = start; x <= end; ++x) {
        if (is_prime(x)) pc++;
        if (is_palindrome_decimal(x)) palc++;
        if (has_equal_ones_zeros_binary(x)) eqc++;
        if (x == 0xFFFFFFFFu) break; 
    }

    *prime_count = pc;
    *pal_count = palc;
    *eq_bits_count = eqc;
    return 0;
}

int main(){

    printf("%d", is_prime(4));

    return 0;
}
