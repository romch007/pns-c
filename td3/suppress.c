#include <stdio.h>
#include <string.h>

void suppress_char(char str[], char c) {
    size_t len = strlen(str);
    size_t new_len = len;

    for (size_t i = 0; i < len; i++) {
        if (str[i] == c) {
            for (size_t j = i; j < new_len; j++) {
                str[j] = str[j + 1];
            }
            new_len--;
        }
    }

    str[new_len] = '\0';
}

int main() {
    char test[] = "salut a tous et a toutes";
    suppress_char(test, 'a');
    printf("%s\n", test);

    return 0;
}