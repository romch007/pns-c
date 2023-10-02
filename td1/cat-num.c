#include <stdio.h>

int main() {
    int i = 0;
    char* line;
    size_t read = 0;

    while (getline(&line, &read, stdin) != -1) {
        i++;
        printf("%d: %s", i, line);
    }

    return 0;
}