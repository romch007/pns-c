#include <stdio.h>

void print_base(int n, int base) {
    if (n < 0) {
        putchar('-');
        print_base(-n, base);
    } else {
        int d = n % base;
        if (n >= base) {
            print_base(n / base, base);
        }
        putchar(d + ((d < 10) ? '0' : 'A' - 10));
    }
}

void en_binaire_rec(int n) {
    int d = n % 2;
    if (n >= 2)
        en_binaire_rec(n / 2);
    putchar(d == 0 ? '0' : '1');
}

void en_binaire_iter(int n) {
    for (size_t i = 0; i < sizeof(int) * 8; i++) {
        putchar(n & 1 ? '1' : '0');
        n >>= 1;
    }
}

int main() {
    // 123456 = 0b11110001001000000
    en_binaire_rec(123456);
    putchar('\n');
    en_binaire_iter(123456);
    putchar('\n');
    return 0;
}