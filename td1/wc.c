#include <stdbool.h>
#include <stdio.h>

int main() {
    int c;
    int char_count = 0;
    int word_count = 0;
    int line_count = 0;
    bool was_space = false;

    while ((c = getchar()) != EOF) {
        char_count++;

        if (c == ' ' || c == '\n') {
            if (was_space) continue;

            word_count++;
            was_space = true;
        } else {
            was_space = false;
        }

        if (c == '\n') line_count++;
    }

    if (!was_space) {
        word_count++;
        line_count++;
    }

    printf("lines: %d\nwords: %d\nchars: %d\n", line_count, word_count, char_count);

    return 0;
}