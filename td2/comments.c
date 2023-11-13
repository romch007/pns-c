#include <stdbool.h>
#include <stdio.h>

int main() {
    int c;
    bool in_comment = false;
    bool in_str = false;

    while ((c = getchar()) != EOF) {
        if (c == '\"') {
            in_str = !in_str;
        }

        if (!in_str) {
            if (c == '/' && !in_comment && getchar() == '*') {
                in_comment = true;
                continue;
            }
            if (c == '*' && in_comment && getchar() == '/') {
                in_comment = false;
                continue;
            }
        }

        if (!in_comment) {
            printf("%c", c);
        }
    }
}