#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define OPTION_n 1 << 1
#define OPTION_E 1 << 2
#define OPTION_h 1 << 3

int main(int argc, char** argv) {
    int flags = 0;

    for (int i = 1; i < argc; i++) {
        char* opt = argv[i];

        if (opt[0] == '-') {
            if (opt[1] == '-') {
                if (strcmp(opt, "--help") == 0) {
                    flags |= OPTION_h;
                }
            } else {
                ++opt;
                while (*opt != '\0') {
                    char c = *opt++;

                    if (c == 'n') flags |= OPTION_n;
                    if (c == 'E') flags |= OPTION_E;
                    if (c == 'h') flags |= OPTION_h;
                }
            }
        }
    }

    if (flags & OPTION_h) {
        printf("usage: cat\n");
        printf("  -h: print help\n");
        printf("  -E: display $ at end of line\n");
        printf("  -n: number all output lines\n");
        return 0;
    }

    int c;
    int lines_nb = 0;
    while ((c = getchar()) != EOF) {
        if ((flags & OPTION_E) && c == '\n') printf("$");
        printf("%c", c);
        if (c == '\n') {
            lines_nb++;
            if (flags & OPTION_n) {
                printf("%d ", lines_nb);
            }
        }
    }

    return 0;
}
