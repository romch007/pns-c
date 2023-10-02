#include <stdio.h>

int main() {
    int i = 0;
    int c;

    while ((c = getchar()) != EOF) {
        if (c == '\n') i++;
    }

    printf("nombre de lignes: %d\n", i);

    return 0;
}