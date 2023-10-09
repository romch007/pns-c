#include <string.h>
#include <stdio.h>

ssize_t indice(const char str[], const char c) {
    for (size_t i = 0; i < strlen(str); i++) {
        if (str[i] == c) return i;
    }

    return -1;
}

ssize_t indice_droite(const char str[], const char c) {
    for (size_t i = strlen(str); i-- > 0;) {
        if (str[i] == c) return i;
    }

    return -1;
}

int main() {
    printf("%zd\n", indice("Test", 'T'));
    printf("%zd\n", indice("Test", 't'));
    printf("%zd\n", indice("Test", 'z'));
    printf("%zd\n", indice("Tester", 'e'));
    printf("%zd\n", indice_droite("Test", 'T'));
    printf("%zd\n", indice_droite("Test", 't'));
    printf("%zd\n", indice_droite("Test", 'z'));
    printf("%zd\n", indice_droite("Tester", 'e') );

    return 0;
}