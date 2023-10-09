#include <stdio.h>
#include <string.h>

int palindrome(const char str[]) {
    size_t len = strlen(str);

    for (size_t i = 0; i < len; i++) {
        if (str[i] != str[len - i - 1]) return 0;
    }

    return 1;
}

void check(int b) {
    printf("%s\n", b ? "true" : "false");
}

int main() {
    check(palindrome("ressasser"));
    check(palindrome("kayak"));
    check(palindrome("X"));
    check(palindrome("test"));

    return 0;
}