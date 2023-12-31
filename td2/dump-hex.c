#include <ctype.h>
#include <stdio.h>

#define LINE_SIZE 16

int main() {
    int c;
    int buffer[LINE_SIZE];
    int cursor = 0;

    while ((c = getchar()) != EOF) {
        buffer[cursor] = c;
        cursor++;

        if (cursor == LINE_SIZE) {
            for (int i = 0; i < LINE_SIZE; i++) {
                printf("%02X ", buffer[i]);
            }

            printf("| ");

            for (int i = 0; i < LINE_SIZE; i++) {
                int a = buffer[i];
                if (a == '\n' || !isascii(a)) a = '.';
                printf("%c", a);
            }

            cursor = 0;
            printf("%s", "\n");
        }
    }
}