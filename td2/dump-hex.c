#include <stdio.h>

#define LINE_SIZE 16

int main() {
    int c;
    int buffer[LINE_SIZE];
    int cursor = 0;

    while ((c = getchar()) != EOF) {
        buffer[cursor] = c;

        if (cursor == 15) {

            // print hex
            for (int i = 0; i < LINE_SIZE; i++) {
                printf("%02X ", buffer[i]);
            }

            printf("| ");

            // print normal

            for (int i = 0; i < LINE_SIZE; i++) {
                int a = buffer[i];
                if (a == '\n') a = '.';
                printf("%c", a);
            }

            cursor = 0;
            printf("%s", "\n");
        }

        cursor++;
    }
}