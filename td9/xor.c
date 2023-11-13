#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* xorcrypt(const char* msg, const char* key) {
    size_t msg_len = strlen(msg);
    size_t key_len = strlen(key);

    char* crypted_msg = malloc(msg_len + 1);

    for (size_t i = 0; i < msg_len; i++) {
        crypted_msg[i] = msg[i] ^ key[i % key_len];
    }

    crypted_msg[msg_len] = '\0';

    return crypted_msg;
}

int main() {
    const char* original = "HELLO, WORLD";
    const char* key = "abcde";

    char* s = xorcrypt(original, key);
    printf("%s\n", s);
    free(s);
    return 0;
}