#include <stdio.h>

int iterate(int (*fn)(int, int), int tab[], size_t len) {
    int val = tab[0];

    for (size_t i = 1; i < len; i++) {
        val = fn(val, tab[i]);
    }

    return val;
}

int max(int a, int b) {
    return a < b ? b : a;
}

int sum(int a, int b) {
    return a + b;
}

int prod(int a, int b) {
    return a * b;
}

int main() {
    int tab[] = {6, 7, 2, 3, 9, 8};

    printf("%d\n", iterate(max, tab, 6));
    printf("%d\n", iterate(sum, tab, 6));
    printf("%d\n", iterate(prod, tab, 6));

    return 0;
}