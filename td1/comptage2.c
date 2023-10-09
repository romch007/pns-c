#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define UPPER_LIMIT 26
#define LOWER_LIMIT 52
#define LIMIT 62

int main() {
    int c;
    int counter[LIMIT] = { 0 };

    for (int i = 0; i < LIMIT; i++) {
        counter[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (isupper(c)) {
            counter[c - 'A']++;
        } else if (islower(c)) {
            counter[(c - 'a') + UPPER_LIMIT]++;
        } else if (isdigit(c)) {
            counter[(c - '0') + LOWER_LIMIT]++;
        }
    }

    for (int i = 0; i < LIMIT; i++) {
        if (counter[i] == 0) continue;

        if (i < UPPER_LIMIT) {
            c = i + 'A';
        } else if (i < LOWER_LIMIT) {
            c = (i + 'a') - UPPER_LIMIT;
        } else {
            c = (i + '0') - LOWER_LIMIT;
        }

        printf("%c: %d\n", c, counter[i]);
    }

    return 0;
}