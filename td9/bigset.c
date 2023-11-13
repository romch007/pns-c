#include <stdio.h>

#define CHAR_SIZE 8
#define MAX_BIGSET 125
#define MAX_VAL (CHAR_SIZE * MAX_BIGSET)

typedef unsigned char bigset[MAX_BIGSET];

void bigset_init(bigset s) {
    for (int i = 0; i < MAX_BIGSET; i++) {
        s[i] = 0;
    }
}

void bigset_add(bigset s, int value) {
    if (value >= MAX_VAL)
        return;

    size_t cell = value / CHAR_SIZE;
    s[cell] |= 1 << (value % CHAR_SIZE);
}

int bigset_is_in(const bigset s, int value) {
    if (value >= MAX_VAL)
        return 0;

    size_t cell = value / CHAR_SIZE;
    return (s[cell] & (1 << (value % CHAR_SIZE)));
}

void bigset_print(const bigset s) {
    printf("{");
    for (int v = 0; v < 999; v++) {
        if (bigset_is_in(s, v)) {
            printf("%d, ", v);
        }
    }
    printf("}\n");
}

void bigset_inter(const bigset s1, const bigset s2, bigset res) {
    bigset_init(res);

    for (size_t i = 0; i < MAX_BIGSET; i++) {
        res[i] = s1[i] & s2[i];
    }
}

int main() {
    bigset e1, e2, e3;

    bigset_init(e1);
    bigset_init(e2);

    for (int i = 0; i < 140; i += 12) bigset_add(e2, i);
    for (int i = 0; i < 140; i += 9) bigset_add(e1, i);

    bigset_inter(e1, e2, e3);
    printf("e1 = ");
    bigset_print(e1);
    printf("e2 = ");
    bigset_print(e2);
    printf("e3 = ");
    bigset_print(e3);
    return 0;
}