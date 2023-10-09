#include <stdio.h>
#include <string.h>

void insertion(int *arr, size_t len, int v) {
    size_t index = 0;

    for (size_t i = 0; i < len - 1; i++) {
        if (arr[i] > v && v < arr[i + 1]) {
            index = i;
            break;
        }
    }

    for (size_t k = len - 1; k > index; k--) {
        arr[k] = arr[k - 1];
    }

    arr[index] = v;
}

#define ARR_SIZE 10

int main() {
    int arr[ARR_SIZE] = {0};

    arr[0] = 1;
    arr[1] = 5;
    arr[2] = 8;

    insertion(arr, ARR_SIZE, 2);

    for (int i = 0; i < ARR_SIZE; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}