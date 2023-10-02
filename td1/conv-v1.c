#include <stdio.h>

double celsius_to_fahrenheit(double c) {
    return ((9 * c) / 5) + 32;
}

int main() {
    const char* sep = "+-------+-------+\n";
    printf("%s", sep);
    for (double c = 0; c < 20; c += 0.5) {
        printf("| %04.1fC | %03.1fF |\n", c, celsius_to_fahrenheit(c));
    }
    printf("%s", sep);
    return 0;
}