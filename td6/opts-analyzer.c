#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    printf("Executable: %s\n", argv[0]);

    bool in_args = false;

    for (int i = 1; i < argc; i++) {
        char* opt = argv[i];

        if (!in_args) {
            if (opt[0] == '-') {
                if (opt[1] == '-') {
                    if (opt[2] == '\0') {
                        in_args = true;
                    } else {
                        printf("Option longue: %s\n", opt);
                    }
                } else {
                    opt += 1;
                    while (*opt != '\0') {
                        printf("Option courte: -%c\n", *opt);
                        opt++;
                    }
                }
            } else {
                in_args = true;
            }
        }

        if (in_args) {
            printf("Argument: %s\n", opt);
        }
    }

    return 0;
}