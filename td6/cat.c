#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    bool option_n = false;
    bool option_E = false;
    bool option_h = false;

    for (int i = 1; i < argc; i++) {
        char* opt = argv[i];

        if (opt[0] == '-') {
            if (opt[1] == '-') {
                if (strcmp(opt, "--help") == 0) {
                    option_h = true;
                }
            } else {
                opt += 1;
                while (*opt != '\0') {
                    char c = *opt;

                    option_n = c == 'n' || option_n;
                    option_E = c == 'E' || option_E;
                    option_h = c == 'h' || option_h;

                    opt++;
                }
            }
        }
    }

    if (option_h) {
        printf("usage: cat\n");
        printf("  -h: print help\n");
        printf("  -E: display $ at end of line\n");
        printf("  -n: number all output lines\n");
        return 0;
    }

    int c;
    int lines_nb = 0;
    while ((c = getchar()) != EOF) {
        if (option_E && c == '\n') printf("$");
        printf("%c", c);
        if (c == '\n') {
            lines_nb++;
            if (option_n) {
                printf("%d ", lines_nb);
            }
        }
    }

    return 0;
}
