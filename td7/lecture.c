#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TBLOC 1 << 6

char* readline() {
    size_t capacity = TBLOC;
    size_t size = 0;
    char* buffer = malloc(capacity);
    int c;

    memset(buffer, 0, capacity);

    while ((c = getchar()) != '\n') {
        if (c == EOF)
            return NULL;

        if (size >= capacity) {
            capacity *= 2;
            buffer = realloc(buffer, capacity);
        }

        buffer[size++] = (char) c;
    }

    return buffer;
}


int main(void) {
    char* s = NULL;
    do {
        printf("Entrer une chaîne: ");
        fflush(stdout);
        s = readline();
        if (s) {
            printf("Chaîne lue : '%s'\n", s);
            free(s);
        }
    } while (s != NULL);
    return 0;
}