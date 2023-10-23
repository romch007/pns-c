#include <string.h>
#include <stdio.h>

void strcpy_own(char s1[], char s2[]) {
    while ((*s1++ = *s2++));
}

int strcmp_own(char s1[], char s2[]) {
    char c1;
    char c2;

    do {
        c1 = *s1++;
        c2 = *s2++;

        if (c1 == '\0')
            return c1 - c2;
    }  while (c1 == c2);

    return c1 - c2;
}

void strupper_own(char s[]) {
    size_t len = strlen(s);

    for (size_t i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            s[i] += 'A' - 'a';
        }
    }
}

int main() {
    // strcpy_own
    char s1[6] = {0};
    strcpy_own(s1, "salut");
    printf("%s\n", s1);

    // strcmp_own
    char s2[] = "test";
    char s2bis[] = "test";
    char s2bisbis[] = "autre";
    printf("%d\n", strcmp_own(s2, s2bis));
    printf("%d\n", strcmp_own(s2, s2bisbis));

    // strupper_own
    char s3[] = "sAlUt";
    strupper_own(s3);
    printf("%s\n", s3);

    return 0;
}