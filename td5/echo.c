#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("no arguments\n");
        return 1;
    }

    bool reversed = strcmp(argv[1], "-r") == 0;
    int start_index = reversed ? 2 : 1;
    int str_count = 0;

    for (int i = start_index; i < argc; i++) {
        if (!reversed)
            printf("%s ", argv[i]);
        str_count++;
    }

    if (reversed) {
        for (int j = str_count; j-- > 0;) {
            printf("%s ", argv[start_index + j]);
        }
    }

    printf("\n");
    return 0;
}