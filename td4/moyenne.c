#include <stdarg.h>
#include <stdio.h>

double moyenne(int count, ...) {
    if (count == 0) return 0;

    va_list numbers;
    va_start(numbers, count);
    double sum = 0;
    for (int i = 0; i < count; i++) {
        double num = va_arg(numbers, double);
        sum += num;
    }
    va_end(numbers);
    return sum / (double) count;
}

int main() {
    printf("Moyenne1 = %f\n", moyenne(2, 10.0, 15.0));
    printf("Moyenne2 = %f\n", moyenne(5, 10.0, 15.0, 18.5, 0.0, 3.5));
    printf("Moyenne3 = %f\n", moyenne(0));
}