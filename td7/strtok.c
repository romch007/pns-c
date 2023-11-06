#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

char *strtok_own(char *s, const char *delim) {
    static char* rest;
    if (s == NULL) s = rest;
    if (strlen(s) == 0) return NULL;

    size_t start_len = strspn(s, delim);
    size_t end_len = strcspn(s, delim);

    s[end_len] = '\0';
    rest = s + end_len + 1;
    return s + start_len;
}

int main(void) {
    char phrase[] = "Une phrase composée de mots.";
    char* p;
    for (p = strtok_own(phrase, " ."); p; p = strtok_own(NULL, " ."))
        printf("mot '%s'\n", p);
    return 0;
}

