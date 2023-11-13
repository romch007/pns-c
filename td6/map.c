#include <stddef.h>
#include <stdio.h>

void map(int (*fn)(int), int arr[], size_t len) {
    for (size_t i = 0; i < len; i++) {
        arr[i] = fn(arr[i]);
    }
}

int square(int x) { return x * x; }

int display(int x) {
    printf("%d ", x);
    return x;
}

int main() {
    int tab[] = {1, 2, 3, 4, 5};
    map(square, tab, 5);
    map(display, tab, 5);

    return 0;
}