#include <stdio.h>
#include <string.h>

void shift_str(char str[], size_t pos, size_t n) {
    size_t len = strlen(str);

    for (size_t i = pos; i < len; i++) {
        str[i] = str[i + n];
    }

    str[len - n] = '\0';
}

void suppression(char str[], const char suppr[]) {
    size_t len = strlen(str);
    size_t len_suppr = strlen(suppr);

    for (int i = 0; i < len; i++) {
        int found = 1;
        for (size_t j = 0; j < len_suppr; j++) {
            if (str[i + j] != suppr[j]) {
                found = 0;
                break;
            }
        }

        if (found) {
            shift_str(str, i, len_suppr);
            str[len - len_suppr] = '\0';
            return;
        }
    }
}

int main() {
    char test[] = "Bonjour";
    suppression(test, "abc");
    printf("%s\n", test);

    return 0;
}