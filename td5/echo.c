#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("no arguments\n");
        return 1;
    }

    int reversed = strcmp(argv[1], "-r") == 0;

    int str_count = argc - reversed - 1;
    char** strs = malloc(sizeof(char*) * str_count);

    for (int i = 0; i < str_count; i++) {
        strs[i] = argv[i + reversed + 1];
    }

    if (reversed) {
        for (int i = str_count - 1; i >= 0; i--)  {
            printf("%s ", strs[i]);
        }
    } else {
        for (int i = 0; i < str_count; i++)  {
            printf("%s ", strs[i]);
        }
    }

    printf("\n");
    free(strs);
    return 0;
}