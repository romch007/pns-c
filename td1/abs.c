#include <stdio.h>

int abs(int x) {
    return x > 0 ? x : -x;
}

int main() {
    int x;
    scanf("%d", &x);
    printf("abs: %d\n", abs(x));

    return 0;
}
