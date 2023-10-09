#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void shuffle(char arr[]) {
    size_t len = strlen(arr);

    for (int i = 0; i < 1000; i++) {
        long pos1 = (random() % (len - 2)) + 1;
        long pos2 = (random() % (len - 2)) + 1;

        char tmp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = tmp;
    }
}

int main() {
    srandom(time(NULL));
    char test[] = "Quand";
    shuffle(test);
    printf("%s\n", test);

    return 0;
}