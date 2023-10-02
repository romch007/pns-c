#include <stdio.h>
#include <math.h>

double celsius_to_fahrenheit(double c) {
    return ((9 * c) / 5) + 32;
}

int main() {
    const char* sep = "+----+----+\n";
    printf("%s", sep);
    for (double c = 0; c < 20; c += 0.5) {
        int c_int = (int) rint(c);
        int f_int = (int) rint(celsius_to_fahrenheit(c));
        printf("| %02d | %02d |\n", c_int, f_int);
    }
    printf("%s", sep);
    return 0;
}