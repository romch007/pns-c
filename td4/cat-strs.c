#include <stdio.h>
#include <stdarg.h>

void cat_strings(char str1[], ...) {
    va_list strs;
    va_start(strs, str1);

    do {
        printf("%s", str1);
        str1 = va_arg(strs, char*);
    } while (str1 != NULL);

    va_end(strs);
}

int main() {
    cat_strings("foo", "bar", "foo", NULL);

    return 0;
}