#include <stdio.h>

int main() {
    int x = 0;
    int n = 0;

    do {
        printf("entrer un un entier: ");
        scanf("%d", &x);
        n++;
    } while (x >= 0);

    printf("nombre d'entiers saisis: %d\n", --n);
    return 0;
}
