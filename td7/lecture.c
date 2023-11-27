#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TBLOC 10

char* readline() {
    size_t capacity = TBLOC;
    size_t size = 0;
    char* buffer = malloc(capacity);
    int c;

    memset(buffer, 0, capacity);

    while ((c = getchar()) != '\n') {
        if (c == EOF) {
            free(buffer);
            return NULL;
        }

        if (size >= capacity) {
            size_t old_capacity = capacity;
            capacity *= 2;
            char* new_buff = realloc(buffer, capacity);
            if (new_buff == NULL) {
                free(buffer);
                return NULL;
            }
            buffer = new_buff;

            // zeroing new buffer space
            memset(&buffer[old_capacity], 0, capacity - old_capacity);
        }

        buffer[size++] = (char) c;
    }

    return buffer;
}


int main(void) {
    for (;;) {
        printf("Entrer une chaîne: ");
        fflush(stdout);
        char* s = readline();

        if (!s)
            return 0;

        printf("Chaîne lue : '%s'\n", s);
        free(s);
    }
}