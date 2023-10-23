#include <stdio.h>
#include <string.h>

typedef struct {
    char sep;
    int reversed;
    int help;
} options;

char** option_analysis(char** argv, options* opt) {
    ++argv;
    opt->sep = ' ';
    for (;;) {
        char* current = *argv;
        if (current[0] != '-')
            return argv;

        if (current[1] != '-') {
            // Short flags
            switch (current[1]) {
                case 'h':
                    opt->help = 1;
                    break;
                case 'O':
                    opt->sep = '\n';
                    break;
                case 'r':
                    opt->reversed = 1;
                    break;
            }
        } else {
            // Long flags
            if (strcmp(&current[2], "help") == 0) {
                opt->help = 1;
            }
        }

        ++argv;
    }
}

int main(int argc, char** argv) {
    options opt;
    int str_count = 0;

    for (argv = option_analysis(argv, &opt); *argv; argv++) {
        if (opt.help) {
            printf("Usage: better-echo [...args]\n");
            printf("  -h, --help: print help\n");
            printf("  -O        : print one per line\n");
            printf("  -r        : print in reverse order\n");
            return 0;
        }

        if (!opt.reversed)
            printf("%s%c", *argv, opt.sep);
        str_count++;
    }

    if (opt.reversed) {
        argv--;
        for (int j = str_count; j > 0; j-- && argv--) {
            printf("%s%c", *argv, opt.sep);
        }
    }

    return 0;
}