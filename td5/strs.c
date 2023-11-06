#include <stdlib.h>

char *strcpy(char *dest, const char *src) {
    while ((*dest++ = *src++));

    return dest;
}

size_t strlen(const char *s) {
    size_t len = 0;
    while (*s++ != 0)
        len++;
    return len;
}

char *strdup(const char *s) {
    char* dest = malloc(strlen(s) + 1);
    return strcpy(dest, s);
}

char *strchr(const char *s, int c) {
    do {
        if (*s == c) return (char*)s;
    } while (*s++);

    return 0;
}

int main() {return 0;}