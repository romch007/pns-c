#include <stdio.h>

int main() {
    int x = 0;
    int n = 0;
    int x_max = 0;
    int sum = 0;

    do {
        printf("entrer un un entier: ");
        scanf("%d", &x);

        if (x >= 0) {
            if (x > x_max) {
                x_max = x;
            }

            sum += x;
            n++;
        }

    } while (x >= 0);

    printf("Le maximum des %d nombres saisis est %d. La somme est %d.\n", n, x_max, sum);
    return 0;
}
