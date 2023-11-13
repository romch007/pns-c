#include <stdio.h>
#include <string.h>

int strstr_own(char a[], char b[]) {
    size_t len_a = strlen(a);
    size_t len_b = strlen(b);

    for (size_t i = 0; i < len_a; i++) {
        for (size_t j = 0; j < len_b; j++) {
            if (a[i + j] != b[j]) break;

            if (j == len_b - 1) return 1;
        }
    }

    return 0;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("invalid arguments");
        return 1;
    }

    char* target = argv[1];

    char* line = NULL;
    size_t len = 0;

    while (getline(&line, &len, stdin) != 0) {
        if (strstr(line, target)) {
            printf("%s", line);
        }
        fflush(stdin);
    }

    return 0;
}