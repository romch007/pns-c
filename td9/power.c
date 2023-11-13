#include <stdio.h>

double power(double x, unsigned int n) {
    double y = 1;
    double z = x;

    for (int i = 0; i < sizeof(int) * 8; i++) {
        if (n & 1) {
            y *= z;
            z *= z;
        }
        n >>= 1;
    }

    return y;
}

int main() {
    printf("5.6^7 = %.5f\n", power(5.6, 7));

    return 0;
}